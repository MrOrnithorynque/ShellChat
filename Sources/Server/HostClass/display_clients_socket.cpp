#include <iostream>

#include "server.hpp"

void slct::Host::displayClientsSocket(void)
{
    size_t AllClients_size = AllClients.size();

    for (size_t i = 0; i < AllClients_size; ++i)
    {
        std::cout << AllClients[i].ClientData.socket_client << std::endl;
    }
}