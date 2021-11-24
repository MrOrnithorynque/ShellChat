/*
** SHELLCHAT PROJECT NOVEMBER 2021
*/

#include <iostream>

#include <thread>
#include "server.hpp"

/*
** FUNCTION that send a size and type for the client to prepare for the second send who send the data
** so it's modular
*/

int main(int const argc, char **argv)
{
    shellchat::Host Host;
    shellchat::error_handling(argc, argv, &Host.HostData);

    // launching_server(&Host);
    std::cout << "Launching server ...\n";
    net::Server Server;

    // Host.bind();
    net::check(bind(Server.ServerData.socket_server, (SOCKADDR *) &Server.ServerData.addr_server, sizeof(Server.ServerData.addr_server)), \
                "Bind error.\n");
    // Host.listen();
    net::check(listen(Server.ServerData.socket_server, MAX_CLIENTS), \
                "Listen error.\n");

    shellchat::handle_client(&Server);

    // Host.Server.closeServer();
    Server.closeServer();

    return 0;
}