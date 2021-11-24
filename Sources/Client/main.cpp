#include <iostream>

#include "client.hpp"

int main(int argc, char **argv)
{
    shellchat::User User;

    User.getUserData();
	std::cout << "Hello " << User.UserData.username << " welcome to ShellChat.\n";
    User.Client.connectClient();
    shellchat::chat_room(&User);
    User.Client.exitClient();

    return 0;
}