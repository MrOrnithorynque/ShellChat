#include <iostream>

#include "client.hpp"

int main(int argc, char **argv)
{
    slct::User User;

    User.getUserData();
	std::cout << "Hello \"" << User.UserData.username << "\" welcome to ShellChat.\n";
    User.Client.connectClient();
    slct::chat_room(&User);
    User.Client.exitClient();

    return 0;
}