/*
** EPITECH PROJECT, 2021
** ShellChat
** File description:
** create_socket
*/

#include <stdlib.h>
#include <stdio.h>
#include "network.h"

SOCKET createSocket(void)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET)
    {
        perror("socket() error.");
        exit(EXIT_FAILURE);
    }
    return sock;
}