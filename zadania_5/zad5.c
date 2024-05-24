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
    struct Element* lastElement = *head;
    newNode->value = newValue;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (lastElement->next != NULL)
    {
        lastElement = lastElement->next;
    }
    lastElement->next = newNode;
}

void removeByValue(struct Element** head, int targetValue)
{
    if (*head == NULL)
    {
        printf("List is empty, no elements to remove.\n");
        return;
    }
    struct Element* temp = *head;
    if (temp->value == targetValue)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    struct Element* prev = NULL;
    while (temp != NULL && temp->value != targetValue)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value %d is not found in the list.\n", targetValue);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(struct Element* node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Element* head = NULL;
    int valueToRemove;

    addElement(&head, 1);
    addElement(&head, 2);
    addElement(&head, 3);
    addElement(&head, 4);

    printf("Enter the value of the element you want to remove: ");
    scanf("%d", &valueToRemove);

    printf("List before removing element of value %d: ", valueToRemove);
    display(head);

    removeByValue(&head, valueToRemove);

    printf("List after removing element of value %d: ", valueToRemove);
    display(head);

    return 0;
}