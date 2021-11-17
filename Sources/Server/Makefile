#
# ShellChat sources Makefile
#

CC			=	g++

EXEC_NAME	=	ShellChat_server
EXEC_PATH	=	../../Binaries/

CFLAGS 		= 	-Wall -Wextra -g
CPPFLAGS	= 	-I../../Includes/ -I../Client
LDFLAGS 	= 	-L../../Libraries/
LDLIBS 		=	-lmy_cpp -lnetwork -pthread

SRCS		=	main.cpp							\
				client_thread.cpp 					\
				client_verification.cpp 			\
				command.cpp 						\
				get_host_informations.cpp			\
				handle_client.cpp					\
				server_setting.cpp 					\
				Games/ConNet4/main.cpp 				\
				Games/ConNet4/recv_input.cpp		\
				Games/ConNet4/render_game.cpp 		\
				Games/ConNet4/send_game_data.cpp 	\
				Games/NeTron/main.cpp 				\
				Games/NeTron/recv_input.cpp			\
				Games/NeTron/render_game.cpp 		\
				Games/NeTron/send_game_data.cpp 	\

OBJ			=	$(SRCS:.cpp=.o)

all:
	@echo "\n\033[34m\n--- SERVER MAKEFILE ShellChat ---\n\n\033[0m"
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

.PHONY: all clean fclean re run