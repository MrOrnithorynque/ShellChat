#include <iostream>

#include "shellchat.hpp"
#include "server.hpp"

template <typename T>
void shellchat::Host::sendToAll(SOCKET sender_socket, T Data)
{
    size_t size = AllClients.size();

    for (size_t i = 0; i < size; ++i)
    {
        if (AllClients[i].ClientData.socket_client != sender_socket)
        {
            std::cout << "sending to " << AllClients[i].ClientData.socket_client << std::endl;
            send(AllClients[i].ClientData.socket_client, &Data, sizeof(Data), 0);
        }
    }
}