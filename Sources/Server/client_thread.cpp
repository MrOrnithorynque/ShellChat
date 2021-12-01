#include <string.h>
#include <vector>

#include "my_cpp.hpp"
#include "shellchat.hpp"
#include "server.hpp"
#include "client.hpp"

void slct::client_thread(slct::Host *Host, net::Client Client)
{
    size_t c_size = Host->AllClients.size();
    slct::UserData_t UserData;
    int recv_value;

    Host->AllClients.push_back(Client);
    Host->displayClientsSocket();

    // std::thread client_verification_thread(client_verification, &AllClients);
    // client_verification_thread.join();

    while (!Host->stop_server)
    {
        recv_value = Host->recvClientMsg(&Client, &UserData);
 
        if (recv_value > 0)
        {
            // if (!command(UserData.client_msg)) {
            std::cout << UserData.username << " : " << UserData.client_msg << std::endl;
            Host->sendToAll(Client.ClientData.socket_client, &UserData);
        }
        else if (recv_value == 0)
        {
            std::cout << UserData.username << " left\n";

            std::swap(Host->AllClients[c_size], Host->AllClients[Host->AllClients.size() - 1]);
            Host->AllClients.pop_back();
            return;
        }
    }
}