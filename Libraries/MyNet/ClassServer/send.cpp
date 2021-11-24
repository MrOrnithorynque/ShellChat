#include "network.hpp"

template <T>
int net::Server::send(SOCKET socket, T *buf, int flag = 0)
{
	return send(socket, buf, sizeof(*bof), 0);
}