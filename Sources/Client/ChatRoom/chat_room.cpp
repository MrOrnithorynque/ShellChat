/*
** SHELLCHAT PROJECT NOVEMBER 2021
** chat_room.cpp
**   Start all threads.
*/

#include <thread>

#include "shellchat.hpp"
#include "client.hpp"

void shellchat::chat_room(shellchat::User *User)
{
    std::thread SendMsgThread(shellchat::send_msg_thread, User);
    SendMsgThread.detach();

    std::thread RecvMsgThread(shellchat::recv_msg_thread, User);
    RecvMsgThread.detach();

    // std::thread GetServerVerification(shellchat::get_server_verification, User)
    // GetServerVerification.detach();
}