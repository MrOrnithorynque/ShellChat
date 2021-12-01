#pragma once

#include <vector>

#include "network.hpp"
#include "shellchat.hpp"
#include "client.hpp"

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
				unsigned int MAX_MSG_LENGTH;
			} Data_t;
			Data_t HostData;

			net::Server Server; // do the friend thing where you can call the Server class method directly in Host class
			std::vector<net::Client> AllClients;

			void bindTo(void);
			void getHostIp(void);
			void generatePort(void);
			void hostSettings(int flag);
			void listenTo(void);
			void sendToAll(SOCKET sender_socket, UserData_t *UserData);
			void displayClientsSocket(void);
			int recvClientMsg(net::Client *Client, shellchat::UserData_t *UserData);

			bool stop_server;

			Host() { stop_server = false; }
			~Host() {/*free what to free*/}
	}; // class Host

	void client_thread(Host *Host, net::Client Client);
	void error_handling(int const argc, char **argv, Host::Data_t *HostData);
	void handle_client(Host *Host);
	void host_settings(Host::Data_t *Host);
	bool command(Host *Host, net::Client *Client, UserData_s *UserData);
} // namespace shellchat