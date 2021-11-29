#include "network.hpp"

template <typename T>
int net::Server::sendTo(SOCKET socket, T *buf)
{
	return send(socket, buf, sizeof(*buf), 0);
}