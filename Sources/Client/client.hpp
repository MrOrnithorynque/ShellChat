#pragma once

//#include "MYCPP/string.hpp"
#include "network.hpp"

namespace shellchat
{
    const unsigned char MAX_MSG_LENGTH      = 400;
    const unsigned char MAX_USERNAME_LENGTH = 30;

    typedef struct UserData_s {
        char client_msg[MAX_MSG_LENGTH];
        char username[MAX_USERNAME_LENGTH];
        //my_cpp::COLOR_FLAG color;
    } UserData_t;

    class User
    {
        private:
            typedef struct Data_s {
                char client_msg[MAX_MSG_LENGTH];
                char username[MAX_USERNAME_LENGTH];
                //my_cpp::COLOR_FLAG color;
                char *color;
            } Data_t;

        public:
            void getUserData(void);
            void getUsername(void);
            void getUserColor(void);
            //void send_msg(void);
            // void print_username(void) { std::cout << UserData.color << UserData.username << my_cpp::WHITE; }

            net::Client Client;
            Data_t UserData;

            User() { /*get_user_data();*/}
            ~User() {/*free what to free*/}
    }; // class User

    char            *create_random_username(void);
    void            chat_room(net::Client *Client);
    unsigned int    get_server_verification(net::Client *Client);
    void            recv_msg_thread(net::Client *Client);
    void            send_msg_thread(net::Client *Client, UserData_t *MyClientData);
} // namespace shellchat
