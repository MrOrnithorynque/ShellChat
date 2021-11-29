/*
**
*/

#include <thread>

#include "server.hpp"

void shellchat::handle_client(shellchat::Host *Host)
{
    net::Client Client;

    while (true)
    {
        std::cout << "Waiting for connections ...\n";
        Host->Server.waitClientConnection(&Client.ClientData);
        std::cout << "Accept client : " << Client.ClientData.socket_client << "\n";

        std::thread ClientThread(shellchat::client_thread, Host, Client);
        //std::thread ClientThread(Host->clientThread, Client);
        ClientThread.detach();
    }
}