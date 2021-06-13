/*
** EPITECH PROJECT, 2021
** reseau[first tests]
** File description:
** get_client_username
*/

#include <string.h>
#include "my.h"
#include "chat.h"
#include "reseau.h"

static int check_username(char *username)
{
    int username_len = strlen(username);

    if (username_len > 20 || username_len < 1) {
        printf("Username must be between 1 and 20 characters.\n");
        return -1;
    } else if (username[0] == '\n') {
        printf("Username cannot be empty.\n");
        return -1;
    }

    return 0;
}

void get_username(user_t *user)
{
    size_t bytes;
    char *ptr_name = (char *)user->name;
    char *username = NULL;

    while (1) {
        printf("Username : ");
        if (getline(&username, &bytes, stdin) == EOF) {
            printf("\nEOF character is not allowed.\n");
            exit(0);
        } else if (check_username(username) != -1) {
            username[strlen(username) - 1] = '\0';
            my_strcpy(ptr_name, username);
            printf("%s\n", user->name);
            break;
        }
    }
}