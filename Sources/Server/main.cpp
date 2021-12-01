/*
** SHELLCHAT PROJECT NOVEMBER 2021
*/

#include <iostream>

#include "server.hpp"

static void launching_host_server(slct::Host *Host)
{
    std::cout << "Launching server ...\n";

    Host->bindTo();
    Host->listenTo();

    slct::handle_client(Host);
}

int main(int const argc, char **argv)
{
    slct::Host Host;

    slct::error_handling(argc, argv, &Host.HostData);
    launching_host_server(&Host);

    Host.Server.closeServer();

    return 0;
}

/*
** FUNCTION that send a size and type for the client to prepare for the second send who send the data
** so it's modular
*/