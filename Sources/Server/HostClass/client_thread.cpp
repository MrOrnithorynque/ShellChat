#include <string.h>
#include <vector>

#include "my_cpp.hpp"
#include "shellchat.hpp"
#include "server.hpp"
#include "client.hpp"

void shellchat::Host::clientThread(net::Client Client)
{
    size_t vector_size = AllClients.size();
    shellchat::UserData_t UserData;
    int recv_value;

    AllClients.push_back(Client);

    // std::thread client_verification_thread(client_verification, &AllClients);
    // client_verification_thread.join();

    while (!stop_server)
    {
        recv_value = recv(Client.ClientData.socket_client, &UserData, sizeof(UserData_t), 0);

        if (recv_value > 0)
        {
            // if (!command(UserData.client_msg)) {
            std::cout << UserData.username << " : " << UserData.client_msg << std::endl;

            sendToAll(Client.ClientData.socket_client, UserData);
            bzero(&UserData.client_msg, 200);
        }
        else if (recv_value == 0)
        {
            std::cout << "client left\n";
            stop_server = true;

            std::swap(AllClients[vector_size], AllClients[AllClients.size()]);
            AllClients.pop_back();
        }
        /*
        else
        {
            stop_server = true;
        }
        */
    }
}