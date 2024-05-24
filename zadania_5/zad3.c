#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int value;
    struct Node* next;
};

void append(struct Node** head, int new_value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->value = new_value;
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
void removeLast(struct Node** head) 
{
    if (*head == NULL) {
        printf("There are no elements to remove.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* last = *head;
    while (last->next->next != NULL) {
        last = last->next;
    }
    free(last->next);

    last->next = NULL;
}

void display(struct Node* current)
{
    while (current != NULL) {
        printf("%d > ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() 
{

    struct Node* start = NULL;

    append(&start, 1);
    append(&start, 2);
    append(&start, 3);
    append(&start, 4);
    append(&start, 5);

    printf("List before removing last value: ");
    display(start);
    removeLast(&start);
    printf("List after removing last value: ");
    display(start);

    return 0;
}