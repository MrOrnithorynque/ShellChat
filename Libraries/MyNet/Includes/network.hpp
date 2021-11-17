/*
** EPITECH PROJECT, 2021
** reseau[first tests]
** File description:
** reseau
*/

#pragma once

/*----------------------------------INCLUDES-----------------------------------*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */

/*-----------------------------------DEFINES-----------------------------------*/

#define closesocket(s)      close(s)
#define INVALID_SOCKET      -1
#define SOCKET_ERROR        -1
#define IP                  "127.0.0.1"
const int LOAD_NO_DATA      = 0;
const int MAX_CLIENTS       = 5;
const int LOAD_DATA         = 1;
const int PORT              = 30000;

/*-----------------------------------STRUCTS-----------------------------------*/

typedef struct  sockaddr_in SOCKADDR_IN;
typedef struct  sockaddr SOCKADDR;
typedef struct  in_addr IN_ADDR;
typedef int     SOCKET;

/*---------------------------------FUNCTIONS-----------------------------------*/

namespace net
{
    static void         print_err(const char *error_msg) { std::cerr << "\033[31m" << error_msg << "\033[0m" << "\n"; }
    void                check(int return_value, const char *error_msg);
    SOCKET              create_socket(void);

    class Client
    {
        public:
            typedef struct Data_s {
                SOCKADDR_IN addr_client;
                SOCKET socket_client;
            } Data_t;
            Data_t ClientData;

            void connectClient(void);
            void exitClient(void);

            Client() { clientData(); }
            ~Client() { /*free what to free*/}

        private:
            inline void clientData(void)
            {
                ClientData.addr_client.sin_family      = AF_INET;
                ClientData.addr_client.sin_addr.s_addr = inet_addr(IP);
                ClientData.addr_client.sin_port        = htons(PORT);
                ClientData.socket_client               = create_socket();
            }
    }; // class client

    class Server
    {
        public:
            typedef struct Data_s {
                SOCKET socket_server;
                SOCKADDR_IN addr_server;
            } Data_t;
            Data_t ServerData;

            void waitClientConnection(Client::Data_t *ClientData);
            void closeServer(void);

            Server() { serverData(); }
            ~Server() {}

        private:
            char *ip_address;

            inline void serverData(void)
            {
                ServerData.addr_server.sin_family      = AF_INET;
                ServerData.addr_server.sin_addr.s_addr = inet_addr(IP);//INADDR_ANY;
                ServerData.addr_server.sin_port        = htons(PORT);
                ServerData.socket_server               = create_socket();
            }

    }; // class server
} // namespace net
