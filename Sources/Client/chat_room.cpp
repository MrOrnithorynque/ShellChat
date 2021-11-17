/*
**
*/

#include <thread>

#include "client.hpp"

void chat_room(net::Client *Client)
{
    shellchat::MsgData_t MyClientData;

    std::cout << "Username : ";
    std::cin >> MyClientData.username;

    std::thread SendMsgThread(shellchat::send_msg_thread, Client, &MyClientData);
    SendMsgThread.join();

    std::thread RecvMsgThread(shellchat::recv_msg_thread, Client);
    RecvMsgThread.join();

    // std::thread GetServerVerification(shellchat::get_server_verification)
    // GetServerVerification.join();

    while (true) {}
    // print by msg
}