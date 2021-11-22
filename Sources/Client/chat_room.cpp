/*
** SHELLCHAT PROJECT NOVEMBER 2021
** chat_room.cpp
**   Start all threads.
*/

#include <thread>

#include "client.hpp"

// no client, net::client into UserData_t *MyClientData;
void shellchat::chat_room(net::Client *Client)
{
    shellchat::UserData_t MyClientData;


    std::cout << "Username : ";
    std::cin >> MyClientData.username;
    // get_client_username(&MyClientData);

    std::thread SendMsgThread(shellchat::send_msg_thread, Client, &MyClientData);
    SendMsgThread.detach();

    std::thread RecvMsgThread(shellchat::recv_msg_thread, Client);
    RecvMsgThread.detach();

    // std::thread GetServerVerification(shellchat::get_server_verification)
    // GetServerVerification.detach();

    while (true) {}
    // print by msg
}