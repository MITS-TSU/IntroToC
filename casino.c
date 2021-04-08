#include <stdio.h>
#include <string.h>

void greet_user() {
    puts("");
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    puts("$ Welcome, to $MITS Casino $");
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    puts("");
}

void print_menu() {
    puts("Menu:");
    puts("1. Register");
    puts("2. Login");
    puts("3. Exit");
}

int register_user() {
    char login[255];
    char password[255];
    printf("Enter your login:\n:> ");
    scanf("%s", login);
    printf("Enter your password:\n:> ");
    scanf("%s", password);

    FILE *check_file = fopen(login, "r");
    if (check_file) {
        puts("Sorry, this user is already registered!");
        return 2;
    }

    FILE *user_file = fopen(login, "w");
    if (!user_file) {
        puts("Error! Can't open file. sorry");
        return 1;
    }
    fprintf(user_file, "%s", password);
    fclose(user_file);
    return 0;
}

int login_user() {
    char login[255];
    char password[255];
    printf("Enter your login:\n:> ");
    scanf("%s", login);
    printf("Enter your password:\n:> ");
    scanf("%s", password);

    FILE *user_file = fopen(login, "r");
    if (!user_file) {
        puts("Error! No such user!");
        return 1;
    }

    char correct_password[255];
    fscanf(user_file, "%s", correct_password);
    
    if (!strcmp(password, correct_password)) {
        printf("Welcome back, ");
        puts(login);
        return 0;
    } else {
        puts("Error! Incorrect password!");
        return 1;
    }
}

int main() {
    greet_user();

    int choice;

    int exit = 0;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                exit = 1;
                break;
            default:
                puts("Please, enter command 1-3");
                break;
        }
    }
    while (!exit);
    return 0;
}
