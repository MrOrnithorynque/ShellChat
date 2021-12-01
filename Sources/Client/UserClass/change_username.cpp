#include <iostream>
#include <cstring>

#include "client.hpp"

void slct::User::changeUsername(void)
{
    char *old_username = strdup(UserData.username);

    getUsername();
    if (strcmp(old_username, UserData.username) == 0)
    {
        std::cout << "Your username didn't change.\n";
    }
}