#include "server.hpp"

int slct::Host::recvClientMsg(net::Client *Client, slct::UserData_t *UserData)
{
    return recv(Client->ClientData.socket_client, UserData, sizeof(UserData_t), 0);
}