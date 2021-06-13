/*
** EPITECH PROJECT, 2021
** reseau[first tests]
** File description:
** reseau
*/

#ifndef RESEAU_H_
#define RESEAU_H_2

/*----------------------------------INCLUDES-----------------------------------*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <pthread.h>

/*-----------------------------------DEFINES-----------------------------------*/

#define INVALID_SOCKET  -1
#define SOCKET_ERROR    -1
#define closesocket(s)  close(s)
#define PORT            30000
#define IP              "127.0.0.1" //adresse IP privée : 192.168.43.36, sinon locale : 127.0.0.1
#define MAX_CLIENTS     100

/*-----------------------------------STRUCTS-----------------------------------*/

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

/*---------------------------------FUNCTIONS-----------------------------------*/

SOCKET createSocket(void);

#endif
