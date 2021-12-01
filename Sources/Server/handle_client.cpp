/*
**
*/

#include <thread>

#include "server.hpp"

void slct::handle_client(slct::Host *Host)
{
    net::Client Client;

    while (true)
    {
        std::cout << "Waiting for connections ...\n";
        Host->Server.waitClientConnection(&Client.ClientData);
        std::cout << "Accept client : " << Client.ClientData.socket_client << "\n";

        std::thread ClientThread(slct::client_thread, Host, Client);
        ClientThread.detach();
    }
}