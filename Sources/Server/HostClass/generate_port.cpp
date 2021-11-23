#include "server.hpp"

void shellchat::Host::generatePort(void)
{
	unsigned int test_port = 1;

	for ( ; /*test if port valid*/ ; ++test_port);
	HostData.PORT = test_port;
}