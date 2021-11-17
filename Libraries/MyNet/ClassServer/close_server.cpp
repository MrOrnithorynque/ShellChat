#include "network.hpp"

void net::Server::closeServer(void)
{
    closesocket(ServerData.socket_server);
    std::cout << "Sockets are closed.\n";
}