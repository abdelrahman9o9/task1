#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

struct User {
    char username[20];
    char password[20];
};

union UserActivity {
    struct {
        int isActive : 1;
        int activityFlag;
    };
};

struct User users[MAX_USERS];
union UserActivity userActivity[MAX_USERS];

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
        printf("Sorry, the maximum number of registered users has been exceeded.\n");
        return;
    }

    struct User newUser;
    union UserActivity newActivity;

    printf("Please enter the username: ");
    scanf("%s", newUser.username);

    if (isUserRegistered(newUser.username)) {
        printf("Username already exists. Please choose another username.\n");
        return;
    }

    printf("Please enter the password: ");
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    newActivity.isActive = 0; // Corrected the member name here
    userActivity[numUsers] = newActivity;
    numUsers++;

    printf("User registered successfully!\n");
}

int loginUser(const char *username, const char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (userActivity[i].isActive == 1) { // Corrected the member name here
                return 1;
            } else {
                return 2;
            }
        }
    }
    return 0;
}

int main() {
    int choice;
    char username[20];
    char password[20];

    while (1) {
        printf("\nPlease choose an action:\n");
        printf("1. Register a new user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                printf("Please enter the username: ");
                scanf("%s", username);
                printf("Please enter the password: ");
                scanf("%s", password);
                int loginStatus = loginUser(username, password);
                if (loginStatus == 1) {
                    printf("Login successful!\n");
                } else if (loginStatus == 2) {
                    printf("The account exists but is inactive. Please check the activity.\n");
                } else {
                    printf("Login failed. Please check the username and password.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Please choose a valid option.\n");
        }
    }

    return 0;
}
