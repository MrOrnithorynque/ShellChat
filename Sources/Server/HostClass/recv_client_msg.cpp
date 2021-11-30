#include "server.hpp"

int shellchat::Host::recvClientMsg(net::Client *Client, shellchat::UserData_t *UserData)
{
    return recv(Client->ClientData.socket_client, UserData, sizeof(UserData_t), 0);
}