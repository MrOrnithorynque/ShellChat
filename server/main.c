/*
** EPITECH PROJECT, 2021
** src
** File description:
** main
*/

#include <string.h>
#include "my.h"
#include "chat.h"
#include "network.h"

SOCKET creatSocket(void)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET)
    {
        perror("socket() error.");
        exit(EXIT_FAILURE);
    }
    return sock;
}

/*
POUR AFFICHER LE CHAT:
    j'envoie a chaque client, les 30 dernieres lignes ecrites.
    C'est a dire, je stock dans une liste chainé auquel je vais ajouter
    une list a chaque fois que qu'elqu'un envoie un msg.
    Cette list contient :
        typedef struct chat_box_s {
            char msg[2000];
            char name[30];
            size_t index; //pour la place du message dans le tableau
            chat_box_s *next;
        } chat_box_t;
    Et je boucle de index n jusqu'a NULL pour afficher.
    je n'ai pas besoin de réafficher tout, a chaque fois, j'affiche la list avant NULL
    a chaque msg envoyé.
    Je peut save cette list dans un file et afficher le file en lancant le serveur.
*/

void *function(void *arg)
{
    SOCKET socket = *(int *)arg;
    user_t user;

    recv(socket, &user, sizeof(user), 0);
    printf("User \"\033[93m%s\033[0m\" join the channel.\n", user.name);
    while (1)
    {
        recv(socket, &user, sizeof(user), 0);
        if (user.status == -1)
        {
            printf("User \"\033[93m%s\033[0m\" left the channel.\n", user.name);
            break;
        }
        printf("\033[93m%s\033[0m : %s\n", user.name, user.msg);
    }
    //free(arg);
    closesocket(socket);
    pthread_exit(NULL);
}

int main(void)
{
    SOCKET socketServer = createSocket();
    SOCKET socketClient;
    SOCKADDR_IN addrServer;
    SOCKADDR_IN addrClient;
    socklen_t csize = sizeof(addrClient);
    pthread_t clientThread;
    int *arg = malloc(sizeof(int));

    addrServer.sin_addr.s_addr = inet_addr(IP);
    addrServer.sin_family = AF_INET;
    addrServer.sin_port = htons(PORT);

    bind(socketServer, (SOCKADDR *) &addrServer, sizeof(addrServer));
    printf("Bind : %d\n", socketServer);

    listen(socketServer, MAX_CLIENTS);
    printf("Listening...\n");

    for (size_t i = 0; i < MAX_CLIENTS; ++i)
    {
        SOCKADDR_IN addrClient;
        socklen_t csize = sizeof(addrClient);
        socketClient = accept(socketServer, (SOCKADDR *) &addrClient, &csize);
        printf("Accept client %d.\n", socketClient);
        *arg = socketClient;
        pthread_create(&clientThread, NULL, function, arg);
    }
    closesocket(socketServer);
    printf("Sockets are closed.\n");
    return 0;
}