#pragma once

//#include "MYCPP/string.hpp"
#include "network.hpp"
#include "shellchat.hpp"

namespace shellchat
{
    const unsigned short MAX_MSG_LENGTH      = 400;
    const unsigned short MAX_USERNAME_LENGTH = 30;

    class User
    {
        private:
            unsigned short MAX_USERNAME_LENGTH  = 30;
            unsigned short MAX_MSG_LENGTH       = 400;

        public:
            typedef struct Data_s {
                char user_msg[MAX_MSG_LENGTH];
                char username[MAX_USERNAME_LENGTH];
                //my_cpp::COLOR_FLAG color;
                char *color;
            } Data_t;
            Data_t UserData;

            void getUserColor(void);
            void getUserData(void);
            void getUserMsg(void);
            void getUsername(void);
            void sendUserMsg(void);

            net::Client Client;

            User() { /*get_user_data();*/}
            ~User() {/*free what to free*/}
    }; // class User

    char            *create_random_username(void);
    void            chat_room(net::Client *Client);
    unsigned int    get_server_verification(net::Client *Client);
    void            recv_msg_thread(net::Client *Client);
    void            send_msg_thread(net::Client *Client, UserData_t *MyClientData);
} // namespace shellchat
