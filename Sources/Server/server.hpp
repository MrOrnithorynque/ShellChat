#pragma once

#include <vector>

#include "network.hpp"

namespace shellchat
{
	class Host
	{
		private:

		public:
			typedef struct Data_s {
				char *IP_ADRESS;
				unsigned int PORT;
				unsigned int MAX_CLIENT; // = 50;
			} Data_t;

			net::Server Server; // do the friend thing where you can call the Server class method directly in Host class
			Data_t HostData;

			Host() {/**/}
			~Host() {/*free what to free*/}
	}; // class Host

	void client_thread(net::Client Client);
	void error_handling(int const argc, char **argv, Host::Data_t *HostData);
	void handle_client(net::Server *Server);
	void host_settings(Host::Data_t *Host);
} // namespace shellchat