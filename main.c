#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

struct User {
    char username[20];
    char password[20];
};

struct User users[MAX_USERS];
int numUsers = 0;

int isUserRegistered(const char *username) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of registered users exceeded.\n");
        return;
    }

    struct User newUser;
    printf("Please enter a username: ");
    scanf("%s", newUser.username);

    if (isUserRegistered(newUser.username)) {
        printf("Username already exists. Please choose another username.\n");
        return;
    }

    printf("Please enter a password: ");
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    numUsers++;
    printf("User registered successfully!\n");
}

int loginUser(const char *username, const char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int choice;
    char username[20];
    char password[20];

    while (1) {
        printf("\nPlease select an action:\n");
        printf("1. Register a new user\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                printf("Please enter your username: ");
                scanf("%s", username);
                printf("Please enter your password: ");
                scanf("%s", password);
                if (loginUser(username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Please check your username and password.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Please select a valid option.\n");
        }
    }

    return 0;
}
