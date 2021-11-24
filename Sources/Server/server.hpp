#pragma once

#include <vector>

#include "network.hpp"

const int AUTO 		= 1;
const int MANUAL	= 0;

namespace shellchat
{
	class Host
	{
		private:

		public:
			typedef struct Data_s {
				char *IP_ADDRESS;
				unsigned int PORT;
				unsigned int MAX_CLIENT;
			} Data_t;
			Data_t HostData;

			net::Server Server; // do the friend thing where you can call the Server class method directly in Host class
			std::vector<net::Client> AllClients;

			void getHostIp(void);
			void generatePort(void);
			void hostSettings(void);
			void sendToAll(net::Client *Client);

			Host() {/**/}
			~Host() {/*free what to free*/}
	}; // class Host

	void client_thread(net::Client Client);
	void error_handling(int const argc, char **argv, Host::Data_t *HostData);
	void handle_client(net::Server *Server);
	void host_settings(Host::Data_t *Host);
} // namespace shellchat