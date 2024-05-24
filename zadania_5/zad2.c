#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* next;
};

int pop(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty, no elements to remove.\n");
        return -1;
    }
    int deletedVal = (*head)->value;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return deletedVal;
}

void display(struct Node* current) {
    while (current != NULL) {
        printf("%d > ", current->value);
        current = current->next;
    }
    printf("NULL\n");

}

//===================================================================//

int main() {
    struct Node* start = NULL;
    for (int i = 5; i > 0; --i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = i;
        newNode->next = start;
        start = newNode;

    }
    printf("Before removing first value: ");
    display(start);

    int deletedVal = pop(&start);
    if (deletedVal != -1) {
        printf("Deleted first value: %d\n", deletedVal);
    }
    printf("List after deleting first value: ");
    display(start);

    return 0;

}