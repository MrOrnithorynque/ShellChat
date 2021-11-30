#include <string.h>
#include <vector>

#include "my_cpp.hpp"
#include "shellchat.hpp"
#include "server.hpp"
#include "client.hpp"

void shellchat::client_thread(shellchat::Host *Host, net::Client Client)
{
    size_t vector_size = Host->AllClients.size();
    shellchat::UserData_t UserData;
    int recv_value;

    Host->AllClients.push_back(Client);

    // std::thread client_verification_thread(client_verification, &AllClients);
    // client_verification_thread.join();

    while (!Host->stop_server)
    {
        recv_value = recv(Client.ClientData.socket_client, &UserData, sizeof(UserData_t), 0);

        if (recv_value > 0)
        {
            // if (!command(UserData.client_msg)) {
            std::cout << UserData.username << " : " << UserData.client_msg << std::endl;

            Host->sendToAll(Client.ClientData.socket_client, &UserData);
            bzero(&UserData.client_msg, 400);
        }
        else if (recv_value == 0)
        {
            std::cout << "client left\n";

            std::cout << Host->AllClients[vector_size].ClientData.socket_client << " " << Host->AllClients[Host->AllClients.size()- 1].ClientData.socket_client << std::endl;
            std::swap(Host->AllClients[vector_size], Host->AllClients[Host->AllClients.size() - 1]);
            std::cout << Host->AllClients[vector_size].ClientData.socket_client << " " << Host->AllClients[Host->AllClients.size()- 1].ClientData.socket_client << std::endl;
            Host->AllClients.pop_back();
            Host->stop_server = true;
        }
        else
        {
            Host->stop_server = true;
        }
    }
    std::terminate();
}