#pragma once

//#include "MYCPP/string.hpp"
#include "network.hpp"
#include "shellchat.hpp"

namespace shellchat
{
    const unsigned int CONNECTED    = 1;
    const unsigned int DISCONNECTED = -1;

    class User
    {
        private:
            unsigned short MAX_MSG_LENGTH         = 400;
            unsigned short MAX_USERNAME_LENGTH    = 30;

        public:
            typedef struct Data_s {
                char user_msg[400];
                char username[30];
                char *color;
                //my_cpp::COLOR_FLAG color;
                // int status;
            } Data_t;
            Data_t UserData;
            Data_t ExternUserData;

            void changeUsername(void);
            void getUserColor(void);
            void getUserData(void);
            void getUserMsg(void);
            void getUsername(void);
            void sendUserMsg(void);

            net::Client Client;
            bool stop_chat;

            User() { /*get_user_data();*/}
            ~User() {/*free what to free*/}
    }; // class User

    char            *create_random_username(void);
    void            chat_room(User *User);
    unsigned int    get_server_verification(net::Client *Client);
    void            recv_msg_thread(User *User);
    void            send_msg_thread(User *User);
} // namespace shellchat
