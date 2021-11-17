#include "network.hpp"

void net::Client::exitClient(void)
{
    std::cout << "\n\033[91mYou left the chat\033[0m\n";
    //send(socket_client, &user, sizeof(user), 0);
    closesocket(ClientData.socket_client);
    exit(EXIT_SUCCESS);
}