#include "network.hpp"

void net::Client::connectClient(void)
{
    std::cout << "\033[92mConnecting...\n\033[0m";
    if (connect(ClientData.socket_client, (SOCKADDR *) &ClientData.addr_client, sizeof(ClientData.addr_client)) == -1)
    {
        print_err("The client failed to connect, please retry.");
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "\033[92mConnected!\n\033[0m";
    }
}