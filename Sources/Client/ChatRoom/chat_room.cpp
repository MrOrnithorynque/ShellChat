/*
** SHELLCHAT PROJECT NOVEMBER 2021
** chat_room.cpp
**   Start all threads.
*/

#include <thread>

#include "shellchat.hpp"
#include "client.hpp"

void slct::chat_room(slct::User *User)
{
    User->stop_chat = false;

    std::thread SendMsgThread(slct::send_msg_thread, User);
    SendMsgThread.detach();

    std::thread RecvMsgThread(slct::recv_msg_thread, User);
    RecvMsgThread.detach();

    // std::thread GetServerVerification(slct::get_server_verification, User)
    // GetServerVerification.detach();
    while (!User->stop_chat) {}
}