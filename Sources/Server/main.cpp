/*
** SHELLCHAT PROJECT NOVEMBER 2021
*/

#include <iostream>

#include <thread>
#include "server.hpp"

int main(int argc, char **argv)
{
    shellchat::error_handling(argc, argv);
    //check_options(argc, argv);
    std::cout << "Launching server ...\n";
    net::Server Server;

    net::check(bind(Server.ServerData.socket_server, (SOCKADDR *) &Server.ServerData.addr_server, sizeof(Server.ServerData.addr_server)), \
                "Bind error.\n");
    net::check(listen(Server.ServerData.socket_server, MAX_CLIENTS), \
                "Listen error.\n");

    shellchat::handle_client(&Server);

    Server.closeServer();

    return 0;
}