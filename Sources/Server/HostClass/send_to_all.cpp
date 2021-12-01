#include <iostream>

#include "shellchat.hpp"
#include "server.hpp"

void slct::Host::sendToAll(SOCKET sender_socket, slct::UserData_t *UserData)
{
    size_t size = AllClients.size();

    for (size_t i = 0; i < size; ++i)
    {
        if (AllClients[i].ClientData.socket_client != sender_socket)
        {
            std::cout << "sending to " << AllClients[i].ClientData.socket_client << std::endl;
            send(AllClients[i].ClientData.socket_client, UserData, sizeof(*UserData), 0);
        }
    }
}