#
# ShellChat sources Makefile
#

CC			=	g++

EXEC_NAME	=	ShellChat_client
EXEC_PATH	=	../../Binaries/

CFLAGS 		= 	-Wall -Wextra -g
CPPFLAGS	= 	-I../../Includes/ -I../Server -I./ -I../Includes/
LDFLAGS 	= 	-L../../Libraries/
LDLIBS 		=	-lmy_cpp -lnetwork -pthread -lncurses

SRCS		=	main.cpp								\
				create_random_username.cpp 				\
				get_server_verification.cpp 			\
				ChatRoom/chat_room.cpp					\
				ChatRoom/recv_msg_thread.cpp			\
				ChatRoom/send_msg_thread.cpp			\
				Games/game_main.cpp 					\
				Games/get_input.cpp 					\
				Games/render_game.cpp 					\
				Games/send_input.cpp 					\
				UserClass/change_username.cpp			\
				UserClass/get_user_color.cpp			\
				UserClass/get_user_data.cpp 			\
				UserClass/get_user_msg.cpp 				\
				UserClass/get_username.cpp				\
				UserClass/send_user_msg.cpp				\

OBJ			=	$(SRCS:.cpp=.o)

all:
	@echo "\n\033[34m\n--- CLIENT MAKEFILE ShellChat ---\n\n\033[0m"
	make make_srcs
	@echo "\n\033[34mCompilation successful.\n\033[32m./$(EXEC_NAME) created.\033[0m\n"

make_srcs:	$(OBJ)
	$(CC) -o $(EXEC_NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	mv $(EXEC_NAME) $(EXEC_PATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXEC_PATH)$(EXEC_NAME)

re:		fclean all

run:	re
	@echo "\033[34mExecuting \"$(EXEC_NAME)\" ...\n\033[0m"
	@./$(EXEC_PATH)$(EXEC_NAME)
	@echo "\033[34m\n\"$(EXEC_NAME)\" executed ...\033[0m"

.PHONY: all make_srcs clean fclean re run