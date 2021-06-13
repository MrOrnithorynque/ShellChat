/*
** EPITECH PROJECT, 2021
** reseau[first tests]
** File description:
** chat
*/

#ifndef CHAT_H_
#define CHAT_H_

//const char *USER_QUIT   = "\n\033[91mYou left the chat\033[0m\n";
//const char *USER_INPUT   = "\033[92m> : \033[0m";
//const char *USER_MSG    = "\033[93m%s\033[0m : %s\n";
//const char *USER_JOIN   = "User \"\033[93m%s\033[0m\" join the channel.\n";
//const char *USER_LEFT   = "User \"\033[93m%s\033[0m\" left the channel.\n";

/*-----------------------------------STRUCTS-----------------------------------*/

typedef struct user_s {
    char name[21];
    char msg[2000];
    int age;
    int status;
} user_t;
typedef struct chat_box_s {
    char name[21];
    char msg[2000];
    size_t index;
    struct chat_box_s *next;
} chat_box_t;

/*---------------------------------FUNCTIONS-----------------------------------*/

void    get_username(user_t *user);

#endif /* !CHAT_H_ */
