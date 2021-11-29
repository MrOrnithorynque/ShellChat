#include <string.h>
#include <vector>

#include "my_cpp.hpp"
#include "shellchat.hpp"
#include "server.hpp"
#include "client.hpp"

bool stop_server = false;
std::vector<net::Client> AllClients;

static void send_to_all(net::Client *Client, shellchat::UserData_t *MyClientData)
{
    size_t size = AllClients.size();

    for (size_t i = 0; i < size; ++i)
    {
        if (AllClients[i].ClientData.socket_client != Client->ClientData.socket_client)
        {
            std::cout << "sending to " << AllClients[i].ClientData.socket_client << std::endl;
            send(AllClients[i].ClientData.socket_client, MyClientData, sizeof(*MyClientData), 0);
        }
    }
}

void shellchat::client_thread(shellchat::Host *Host, net::Client Client)
{
    size_t vector_size = Host->AllClients.size();
    shellchat::UserData_t UserData;
    int recv_value;

    Host->AllClients.push_back(Client);

    // std::thread client_verification_thread(client_verification, &AllClients);
    // client_verification_thread.join();

    while (!stop_server)
    {
        recv_value = recv(Client.ClientData.socket_client, &UserData, sizeof(UserData_t), 0);

        if (recv_value > 0)
        {
            // if (!command(UserData.client_msg)) {
            std::cout << UserData.username << " : " << UserData.client_msg << std::endl;

            Host->sendToAll(Client.ClientData.socket_client, UserData);
            bzero(&UserData.client_msg, 200);
        }
        else if (recv_value == 0)
        {
            std::cout << "client left\n";

            std::swap(Host->AllClients[vector_size], Host->AllClients[Host->AllClients.size()]);
            Host->AllClients.pop_back();
            stop_server = true;
        }
        /*
        else
        {
            stop_server = true;
        }
        */
    }
    std::terminate();
}