#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_USERS 100

struct Book {
    char code[50];
    char name[100];
    char author[100];
    char genre[100];
    char status[20];
};

struct User {
    char ino[50];
    char name[100];
    char book[50];
    char issue[50];
    char returndate[50];
};

struct Book B[MAX_BOOKS];
struct User U[MAX_USERS];
int bookCount = 0;
int userCount = 0;

void AddBook() {
    if (bookCount == MAX_BOOKS) {
        printf("Maximum book limit reached!\n");
        return;
    }

    struct Book b;
    printf("Enter book code: ");
    scanf("%s", b.code);
    printf("Enter book's name: ");
    getchar();
    fgets(b.name, sizeof(b.name), stdin);
    b.name[strcspn(b.name, "\n")] = '\0';
    printf("Enter author's name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    printf("Enter book's genre: ");
    fgets(b.genre, sizeof(b.genre), stdin);
    b.genre[strcspn(b.genre, "\n")] = '\0';
    strcpy(b.status, "available");

    B[bookCount++] = b;

    printf("Book successfully added!\n");
}

void IssueBook() {
    char code[50], ino[50], name[100], issue[50];
    printf("Enter code of issued book: ");
    scanf("%s", code);

    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(B[i].code, code) == 0) {
            if (strcmp(B[i].status, "available") == 0) {
                struct User u;
                printf("Enter issue number: ");
                scanf("%s", ino);
                printf("Enter user's name: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter date of issue: ");
                scanf("%s", issue);

                strcpy(u.ino, ino);
                strcpy(u.name, name);
                strcpy(u.book, code);
                strcpy(u.issue, issue);
                strcpy(u.returndate, "");

                U[userCount++] = u;

                strcpy(B[i].status, "unavailable");

                printf("Book successfully issued!\n");
                return;
            } else {
                printf("Book unavailable!\n");
                return;
            }
        }
    }

    printf("Book not found!\n");
}

void ReturnBook() {
    char ino[50], returndate[50];
    printf("Enter issue number: ");
    scanf("%s", ino);

    int i;
    for (i = 0; i < userCount; i++) {
        if (strcmp(U[i].ino, ino) == 0) {
            printf("Enter date of return: ");
            scanf("%s", returndate);

            strcpy(U[i].returndate, returndate);

            int j;
            for (j = 0; j < bookCount; j++) {
                            if (strcmp(B[j].code, U[i].book) == 0) {
                    strcpy(B[j].status, "available");
                    break;
                }
            }

            printf("Book successfully returned!\n");
            return;
        }
    }

    printf("Issue number not found!\n");
}

void Search() {
    int option;
    printf("Press 1 to search by book's name, 2 to search by author's name, 3 to search by book's genre: ");
    scanf("%d", &option);

    int i, found = 0;
    char searchStr[100];

    switch (option) {
        case 1:
            printf("Enter book's name: ");
            getchar();
            fgets(searchStr, sizeof(searchStr), stdin);
            searchStr[strcspn(searchStr, "\n")] = '\0';

            for (i = 0; i < bookCount; i++) {
                if (strcmp(B[i].name, searchStr) == 0) {
                    printf("Book found!\n");
                    printf("Code: %s\nName: %s\nAuthor: %s\nGenre: %s\nStatus: %s\n",
                           B[i].code, B[i].name, B[i].author, B[i].genre, B[i].status);
                    found = 1;
                }
            }

            if (!found) {
                printf("Book not found!\n");
            }

            break;

        case 2:
            printf("Enter author's name: ");
            getchar();
            fgets(searchStr, sizeof(searchStr), stdin);
            searchStr[strcspn(searchStr, "\n")] = '\0';

            for (i = 0; i < bookCount; i++) {
                if (strcmp(B[i].author, searchStr) == 0) {
                    printf("Book found!\n");
                    printf("Code: %s\nName: %s\nAuthor: %s\nGenre: %s\nStatus: %s\n",
                           B[i].code, B[i].name, B[i].author, B[i].genre, B[i].status);
                    found = 1;
                }
            }

            if (!found) {
                printf("Book not found!\n");
            }

            break;

        case 3:
            printf("Enter genre: ");
            getchar();
            fgets(searchStr, sizeof(searchStr), stdin);
            searchStr[strcspn(searchStr, "\n")] = '\0';

            for (i = 0; i < bookCount; i++) {
                if (strcmp(B[i].genre, searchStr) == 0) {
                    printf("Book found!\n");
                    printf("Code: %s\nName: %s\nAuthor: %s\nGenre: %s\nStatus: %s\n",
                           B[i].code, B[i].name, B[i].author, B[i].genre, B[i].status);
                    found = 1;
                }
            }

            if (!found) {
                printf("Book not found!\n");
            }

            break;

        default:
            printf("Invalid option!\n");
    }
}

void ModifyBook() {
    char code[50];
    int option;
    printf("Enter book's code: ");
    scanf("%s", code);

    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(B[i].code, code) == 0) {
                        printf("Press 1 to change book's name, 2 to change author's name, 3 to change book's genre: ");
            scanf("%d", &option);

            char newValue[100];

            switch (option) {
                case 1:
                    printf("Enter new book's name: ");
                    getchar();
                    fgets(newValue, sizeof(newValue), stdin);
                    newValue[strcspn(newValue, "\n")] = '\0';
                    strcpy(B[i].name, newValue);
                    printf("Book's name updated successfully!\n");
                    break;

                case 2:
                    printf("Enter new author's name: ");
                    getchar();
                    fgets(newValue, sizeof(newValue), stdin);
                    newValue[strcspn(newValue, "\n")] = '\0';
                    strcpy(B[i].author, newValue);
                    printf("Author's name updated successfully!\n");
                    break;

                case 3:
                    printf("Enter new book's genre: ");
                    getchar();
                    fgets(newValue, sizeof(newValue), stdin);
                    newValue[strcspn(newValue, "\n")] = '\0';
                    strcpy(B[i].genre, newValue);
                    printf("Book's genre updated successfully!\n");
                    break;

                default:
                    printf("Invalid option!\n");
            }

            return;
        }
    }

    printf("Book not found!\n");
}

void DisplayBooks() {
    if (bookCount == 0) {
        printf("No books available!\n");
        return;
    }

    int i;
    for (i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("Code: %s\nName: %s\nAuthor: %s\nGenre: %s\nStatus: %s\n",
               B[i].code, B[i].name, B[i].author, B[i].genre, B[i].status);
    }
}

void DisplayUsers() {
    if (userCount == 0) {
        printf("No users found!\n");
        return;
    }

    int i;
    for (i = 0; i < userCount; i++) {
        printf("User %d:\n", i + 1);
        printf("Issue Number: %s\nUser Name: %s\nBook Code: %s\nDate of Issue: %s\nDate of Return: %s\n",
               U[i].ino, U[i].name, U[i].book, U[i].issue, U[i].returndate);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Search Book\n");
        printf("5. Modify Book\n");
        printf("6. Display Books\n");
        printf("7. Display Users\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddBook();
                break;

            case 2:
                IssueBook();
                break;

            case 3:
                ReturnBook();
                break;

            case 4:
                Search();
                break;

            case 5:
                ModifyBook();
                break;

            case 6:
                DisplayBooks();
                break;

            case 7:
                DisplayUsers();
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

                       default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}