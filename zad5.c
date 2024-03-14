#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstName[20];
    char lastName[20];
    char phoneNumber[20];
} Contact;

void addContact(Contact contacts[], int *size, const char *firstName, const char *lastName, const char *phoneNumber);
void searchContact(const Contact contacts[], int size, const char *lastName);
void deleteContact(Contact contacts[], int *size, const char *lastName);
void printContacts(const Contact contacts[], int size);

int main() {
    Contact contacts[100];
    int size = 0;

    addContact(contacts, &size, "Timothy", "Beard", "511611712");
    addContact(contacts, &size, "Tymoteusz", "Broda", "100200300");

    printContacts(contacts, size);

    printf("Szukanie 'Beard':\n");
    searchContact(contacts, size, "Beard");

    deleteContact(contacts, &size, "Broda");
    printf("Lista po usunięciu 'Broda':\n");
    printContacts(contacts, size);

    return 0;
}

void addContact(Contact contacts[], int *size, const char *firstName, const char *lastName, const char *phoneNumber) {
    if (*size >= 100) {
        printf("Maksymalna liczba kontaktów osiągnięta.\n");
        return;
    }
    strncpy(contacts[*size].firstName, firstName, 50);
    contacts[*size].firstName[49] = '\0';
    strncpy(contacts[*size].lastName, lastName, 50);
    contacts[*size].lastName[49] = '\0';
    strncpy(contacts[*size].phoneNumber, phoneNumber, 20);
    contacts[*size].phoneNumber[19] = '\0';
    (*size)++;
}

void searchContact(const Contact contacts[], int size, const char *lastName) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            printf("Znaleziono: %s %s, tel: %s\n", contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
            return;
        }
    }
    printf("Nie znaleziono.\n");
}

void deleteContact(Contact contacts[], int *size, const char *lastName) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            return;
        }
    }
    printf("Nie znaleziono kontaktu do usunięcia.\n");
}

void printContacts(const Contact contacts[], int size) {
    if (size == 0) {
        printf("Brak kontaktów.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d. %s %s, tel: %s\n", i + 1, contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
    }
}