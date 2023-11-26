#include <stdio.h>
#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
};

int addBook(struct Book library[], int numBooks);
void displayBooks(const struct Book library[], int numBooks);

int main() {
    struct Book library[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    do {
        printf("Library Management \n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numBooks = addBook(library, numBooks);
                break;
            case 2:
                displayBooks(library, numBooks);
                break;
            case 3:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice .\n");
        }
    } while (choice != 3);

    return 0;
}

int addBook(struct Book library[], int numBooks) {
    if (numBooks < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]%*c", library[numBooks].title);

        printf("Enter author: ");
        scanf(" %[^\n]%*c", library[numBooks].author);

        printf("Book added successfully\n");
        return numBooks + 1;
    } else {
        printf("Library is full\n");
        return numBooks;
    }
}

void displayBooks(const struct Book library[], int numBooks) {
    if (numBooks > 0) {
        printf("\nList of Books:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("**************************\n");
        }
    } else {
        printf("No books in the library.\n");
    }
}

