#pragma once

#include "MYCPP/string.hpp"
#include "network.hpp"

namespace shellchat
{
    typedef struct UserData_s {
        char client_msg[MAX_MSG_LENGTH];
        char username[MAX_USERNAME_LENGTH];
        COLOR_FLAG color;
    } UserData_t;

    class User
    {
        private:
            const unsigned int MSG_LENGTH       = 200;
            const unsigned int USERNAME_LENGTH  = 20;

        public:
            typedef struct Data_s {
                char client_msg[MSG_LENGTH];
                char username[USERNAME_LENGTH];
                COLOR_FLAG color;
            } Data_t;

            net::Client Client;

            User() { /*get_user_data();*/}
            ~User() {/*free what to free*/}
    }; // class User

    const unsigned int MAX_MSG_LENGTH       = 200;
    const unsigned int MAX_USERNAME_LENGTH  = 20;

    void chat_room(net::Client *Client);
    char *create_random_username(void);
    void get_server_verification(net::Client *Client);
    void recv_msg_thread(net::Client *Client);
    void send_msg_thread(net::Client *Client, UserData_t *MyClientData);
} // namespace shellchat
