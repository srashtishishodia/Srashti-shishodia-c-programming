#include <stdio.h>
#include <string.h>

struct user {
    char name[100];
    char username[100];
    char password[100];
};

struct book {
    char title[100];
    char author[100];
    int copies;
};

typedef struct user u;
typedef struct book b;


void register_user() {
    u newUser, temp;
    FILE *fp;

    printf("Enter Name: ");
    scanf(" %[^\n]", newUser.name);

    printf("Enter Username: ");
    scanf("%s", newUser.username);

    printf("Enter Password: ");
    scanf("%s", newUser.password);

    fp = fopen("users.dat", "rb");

    if (fp != NULL) {
        while (fread(&temp, sizeof(temp), 1, fp)) {
            if (strcmp(newUser.username, temp.username) == 0) {
                printf("Username already exists!\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    fp = fopen("users.dat", "ab");
    fwrite(&newUser, sizeof(newUser), 1, fp);
    fclose(fp);

    printf("Registration Successful!\n");
}

// Login Function
int login_user() {
    u user;
    char username[100], password[100];
    FILE *fp;

    fp = fopen("users.dat", "rb");

    if (fp == NULL) {
        printf("No users found!\n");
        return 0;
    }

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    while (fread(&user, sizeof(user), 1, fp)) {
        if (strcmp(username, user.username) == 0 &&
            strcmp(password, user.password) == 0) {
            printf("Login Successful!\n");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// Display Books
void show_books() {
    b library[4] = {
        {"C Programming", "Dennis Ritchie", 10},
        {"Data Structures", "Mark Allen", 7},
        {"Operating System", "Galvin", 5},
        {"Computer Networks", "Tanenbaum", 8}
    };

    printf("\nLibrary Books:\n");

    for (int i = 0; i < 4; i++) {
        printf("Title: %s | Author: %s | Copies: %d\n",
               library[i].title,
               library[i].author,
               library[i].copies);
    }
}

// Menu
void menu() {
    printf("\n1. Register\n");
    printf("2. Login\n");
    printf("Enter choice: ");
}

int main() {
    int choice;

    menu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            register_user();
            break;

        case 2:
            if (login_user()) {
                show_books();
            } else {
                printf("Invalid Login!\n");
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}