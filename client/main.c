/*
** EPITECH PROJECT, 2021
** reseau[first tests]
** File description:
** main
*/

#include <string.h>
#include "my.h"
#include "chat.h"
#include "reseau.h"

static SOCKET createSocket(void)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET)
    {
        perror("socket() error.");
        exit(EXIT_FAILURE);
    }
    return sock;
}

user_t user_data(void)
{
    user_t user;

    user.status = 0;

    return user;
}

static SOCKADDR_IN client_data(void)
{
    SOCKADDR_IN addrClient;

    addrClient.sin_addr.s_addr  = inet_addr(IP);
    addrClient.sin_family       = AF_INET;
    addrClient.sin_port         = htons(PORT);

    return addrClient;
}

static void exit_client(SOCKET socketClient, user_t user)
{
    user.status = -1;
    printf("\n\033[91mYou left the chat\033[0m\n");
    send(socketClient, &user, sizeof(user), 0);
    closesocket(socketClient);
    exit(0);
}

static int check_msg(char *msg)
{
    int msg_len = strlen(msg);

    if (msg_len > 200 || msg_len < 1) {
        printf("your message must be between 1 and 200 characters.\n");
        return -1;
    } else if (msg[0] == '\n') {
        printf("Your message cannot be empty.\n");
        return -1;
    }

    return 0;
}

void chat(user_t user, SOCKET socketClient)
{
    size_t bytes;
    char *ptr_msg = (char *)user.msg;
    char *user_msg = NULL;
//change ptrmsg par ptr puis cpy
    while (1)
    {
        printf("\033[92m> : \033[0m");
        if (getline(&user_msg, &bytes, stdin) == EOF) {
            exit_client(socketClient, user);
        } else if (check_msg(user_msg) == -1) {
            continue;
        } else {
            user_msg[strlen(user_msg) - 1] = '\0';
            my_strcpy(ptr_msg, user_msg);
            //ptr_msg = remove_char_space(ptr_msg, ' '); not working, don't know why (work in lib)
            send(socketClient, &user, sizeof(user), 0);
        }
    }
}

void connect_client(SOCKET socketClient, SOCKADDR_IN addrClient)
{
    printf("\033[92mConnecting...\n\033[0m");
    if (connect(socketClient, (SOCKADDR *) &addrClient, sizeof(addrClient)) == -1) {
        my_puterror("\033[91mThe client failed to connect, please retry.\n\033[0m");
        exit(84);
    } else {
        printf("\033[92mConnected!\n\033[0m");
    }
}

int main(void)
{
    SOCKET socketClient     = createSocket();
    SOCKADDR_IN addrClient  = client_data();
    user_t user             = user_data();

    connect_client(socketClient, addrClient);
    get_username(&user);
    send(socketClient, &user, sizeof(user), 0);
    chat(user, socketClient);

    return 0;
}