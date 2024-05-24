#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void addFirst(struct Node** head_ptr, int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->value = data;
    new->next = *head_ptr;
    *head_ptr = new;
}
void display(struct Node* current) {
    while (current) {
        printf("%d > ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

//==========================================================//
int main() {
    struct Node* start = NULL;
    addFirst(&start, 5);
    addFirst(&start, 4);
    addFirst(&start, 3);
    addFirst(&start, 2);
    addFirst(&start, 1);
    addFirst(&start, 6);

    display(start);
    return 0;
}