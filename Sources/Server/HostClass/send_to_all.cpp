#include <iostream>

#include "shellchat.hpp"
#include "server.hpp"

void shellchat::Host::sendToAll(net::Client *Client, shellchat::UserData_t UserData)
{
    size_t size = AllClients.size();

    for (size_t i = 0; i < size; ++i)
    {
        if (AllClients[i].ClientData.socket_client != Client->ClientData.socket_client)
        {
            std::cout << "sending to " << AllClients[i].ClientData.socket_client << std::endl;
            send(AllClients[i].ClientData.socket_client, &UserData, sizeof(UserData), 0);
        }
    }
}