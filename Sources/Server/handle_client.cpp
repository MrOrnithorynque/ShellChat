/*
**
*/

#include <thread>

#include "server.hpp"

void shellchat::handle_client(net::Server *Server)
{
    net::Client Client;

    while (true)
    {
        std::cout << "Waiting for connections ...\n";
        Server->waitClientConnection(&Client.ClientData);
        std::cout << "Accept client : " << Client.ClientData.socket_client << "\n";

        std::thread c_thread(shellchat::client_thread, Client);
        c_thread.detach();
    }
}