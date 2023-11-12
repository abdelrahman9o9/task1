#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

// Union to represent user activity status
union UserStatus {
    int active;  // Flag to indicate user activity (1 for active, 0 for inactive)
    float dummy; // A dummy member to ensure the union size is the same as the largest member
};

struct User {
    char username[20];
    char password[20];
    union UserStatus status; // Union to represent user status
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

    // Set the user as active by default
    newUser.status.active = 1;

    users[numUsers] = newUser;
    numUsers++;
    printf("User registered successfully!\n");
}

int loginUser(const char *username, const char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].status.active) {
                return 1; // User is active, login successful
            } else {
                printf("User is inactive. Please contact support for assistance.\n");
                return 0; // User is inactive, login failed
            }
        }
    }
    return 0; // Username or password is incorrect
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
