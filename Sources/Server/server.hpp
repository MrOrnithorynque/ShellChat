#pragma once

#include <vector>

#include "network.hpp"

namespace shellchat
{
	class Host
	{
		private:

		public:
			net::Server Server;
			// do the firend thing where you can call the Server class method directly in Host class

			typedef struct Data_s {

			} Data_t;

			Host() {/**/}
			~Host() {/*free what to free*/}
	}; // class Host

	void client_thread(net::Client Client);
	void error_handling(int argc, char **argv);
	void handle_client(net::Server *Server);
	void host_settings(int argc, char **argv, shellchat::Host *Host);
} // namespace shellchat