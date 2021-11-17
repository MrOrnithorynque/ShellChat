#include <iostream>

#include "client.hpp"

int main(int argc, char **argv)
{
    net::Client Client;

    Client.connectClient();
    shellchat::chat_room(&Client);
    Client.exitClient();

    return 0;
}