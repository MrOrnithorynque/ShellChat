#include "network.hpp"

void net::Server::waitClientConnection(Client::Data_t *ClientData)
{
    socklen_t csize = sizeof(SOCKADDR_IN);

    check(ClientData->socket_client = accept(ServerData.socket_server, (SOCKADDR *) &ClientData->addr_client, &csize), "Accept error\n");
}