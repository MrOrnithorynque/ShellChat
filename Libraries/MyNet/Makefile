#
# EPITECH PROJECT, 2021
#

INCLUDES	=	Includes/network.hpp

INCLUDE_PATH=	../../Includes

RM 			=	rm -f

CPPFLAGS	= 	-I./Includes/

SRCS		=	Socket/create_socket.cpp 				\
				CheckReturn/check.cpp 					\
				ClassClient/connect_client.cpp			\
				ClassClient/exit_client.cpp				\
				ClassServer/close_server.cpp			\
				ClassServer/sendTo.cpp 					\
				ClassServer/wait_client_connection.cpp	\
				SendData/m_send.cpp 					\

OBJ 		= 	$(SRCS:.cpp=.o)

LIB_NAME	= 	libnetwork.a

all:
	@echo "\033[34m\n\n--- MYNET MAKEFLIE ShellChat ---\n\033[0m"
	make make_lib

make_lib: $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	cp $(LIB_NAME) ../
	cp -r $(INCLUDES) $(INCLUDE_PATH) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB_NAME)
	cd .. && $(RM) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean