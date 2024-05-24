#include <stdio.h>
#include <stdlib.h>

struct Element
 {
    int value;
    struct Element* next;
};

void addElement(struct Element** head, int newValue)
{
    struct Element* newNode = (struct Element*)malloc(sizeof(struct Element));
    struct Element* last = *head;
    newNode->value = newValue;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void removeByIndex(struct Element** head, int index) 
{
    if (*head == NULL) {
        printf("List is empty, no elements to remove.\n");
        return;
    }
    struct Element* temp = *head;
    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Given index is out of range.\n");
        return;
    }
    struct Element* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void display(struct Element* node) 
{
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Element* head = NULL;
    int indexToRemove;

    addElement(&head, 1);
    addElement(&head, 2);
    addElement(&head, 3);
    addElement(&head, 4);


    printf("Enter the index of the element you want to remove: ");
    scanf("%d", &indexToRemove);
    
    printf("List before removing element at index %d: ", indexToRemove);
    display(head);

    removeByIndex(&head, indexToRemove);
    
    printf("List after removing element at index %d: ", indexToRemove);
    display(head);

    return 0;
}