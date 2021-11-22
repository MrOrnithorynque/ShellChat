#include <iostream>

#include "client.hpp"

int main(int argc, char **argv)
{
    shellchat::User User;

    User.get_user_data();
    User.Client.connectClient();
    shellchat::chat_room(&User.Client);
    User.Client.exitClient();

    return 0;
}