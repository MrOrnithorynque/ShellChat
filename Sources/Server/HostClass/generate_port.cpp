#include "server.hpp"

void shellchat::Host::generatePort(void)
{
	unsigned int test_port = 1;

	for ( ; /*while port not valid || test_port < 100000*/test_port <= 50000 ; ++test_port);

	if (test_port > 50000)
	{
		exit(EXIT_FAILURE);
	}
	HostData.PORT = test_port;
}