#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *DB_FOLDER_NAME = "users/";


typedef struct {
    char username[255];
    unsigned int balance;
} Player;


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

void print_game_menu() {
    puts("Games:");
    puts("1. Roulette");
    puts("2. Dice");
    puts("3. Poker");
    puts("4. Exit");
}

void print_player(Player *player) {
    printf("%s: \nBalance: %d\n\n", player->username, player->balance);
}

void build_db_file_path_with_login(char *login, char *db_file_path) {
    int db_folder_len = strlen(DB_FOLDER_NAME);
    // db_file_path = ['u', 's', 'e', 'r', 's', '\', '\0', 0, 0, 0, 0, 0, .... 0]
    strcpy(db_file_path, DB_FOLDER_NAME);

    // db_file_path = ['u', 's', 'e', 'r', 's', '\', 'l1', 'l2', 'l3' ... 'ln', '\0']
    strcpy(db_file_path + db_folder_len, login);
}


int register_user(Player *player) {
    char login[255];
    char password[255];
    printf("Enter your login:\n:> ");
    scanf("%s", login);

    //                                255
    //          ----------------------------------------------
    // login = ['m', 'a', 's', 'h', 'a', '\0', 0, 0, 0, .... 0]

    printf("Enter your password:\n:> ");
    scanf("%s", password);

    int db_path_len = strlen(login) + strlen(DB_FOLDER_NAME);
    char *db_file_path = (char *)malloc(db_path_len + 1);
    build_db_file_path_with_login(login, db_file_path);

    FILE *check_file = fopen(db_file_path, "r");
    if (check_file) {
        puts("Sorry, this user is already registered!");
        return 2;
    }

    FILE *user_file = fopen(db_file_path, "w");
    if (!user_file) {
        puts("Error! Can't open file. sorry");
        return 1;
    }
    free(db_file_path);
    fprintf(user_file, "%s\n", password);
    fprintf(user_file, "%d", 100);
    fclose(user_file);

    player->balance = 100;
    strcpy(player->username, login);
    return 0;
}

int login_user(Player *player) {
    char login[255];
    char password[255];
    printf("Enter your login:\n:> ");
    scanf("%s", login);
    printf("Enter your password:\n:> ");
    scanf("%s", password);

    int db_path_len = strlen(login) + strlen(DB_FOLDER_NAME);
    char *db_file_path = (char *)malloc(db_path_len + 1);
    build_db_file_path_with_login(login, db_file_path);

    FILE *user_file = fopen(db_file_path, "r");
    if (!user_file) {
        puts("Error! No such user!");
        return 1;
    }

    char correct_password[255];
    fscanf(user_file, "%s", correct_password);

    int balance;
    fscanf(user_file, "%d", &balance);

    if (strcmp(password, correct_password)) {
        puts("Error! Incorrect password!");
        return 1;
    }

    printf("Welcome back, ");
    puts(login);

    player->balance = balance;
    strcpy(player->username, login);
    return 0;
}

int main() {
    greet_user();

    Player player;

    int choice;
    int exit = 0;
    int logged_in = 0;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                logged_in = !register_user(&player);
                break;
            case 2:
                logged_in = !login_user(&player);
                break;
            case 3:
                exit = 1;
                break;
            default:
                puts("Please, enter command 1-3");
                break;
        }
    }
    while (!exit && !logged_in);

    exit = 0;
    do {
        print_player(&player);
        print_game_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // play_roulette(*player);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
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
