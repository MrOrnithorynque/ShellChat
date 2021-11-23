#include <iostream>

#include "client.hpp"

int main(int argc, char **argv)
{
    shellchat::User User;

    User.getUserData();
    User.Client.connectClient();
    shellchat::chat_room(&User.Client);
    User.Client.exitClient();

    return 0;
}