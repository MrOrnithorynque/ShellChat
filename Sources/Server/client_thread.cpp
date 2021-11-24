#include <string.h>
#include <vector>

#include "my_cpp.hpp"
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

void shellchat::client_thread(net::Client Client)
{
    shellchat::UserData_t MyClientData;
    int recv_value;
    size_t vector_size = AllClients.size();

    AllClients.push_back(Client);

    // std::thread client_verification_thread(client_verification, &AllClients);
    // client_verification_thread.join();

    while (!stop_server)
    {
        recv_value = recv(Client.ClientData.socket_client, &MyClientData, sizeof(UserData_t), 0);

        if (recv_value > 0)
        {
            // if (!command(MyClientData.client_msg)) {
            std::cout << MyClientData.username << " : " << MyClientData.client_msg << std::endl;

            send_to_all(&Client, &MyClientData);
            bzero(&MyClientData.client_msg, 200);
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