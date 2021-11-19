#
# ShellChat sources Makefile
#

CC			=	g++

EXEC_NAME	=	ShellChat_client
EXEC_PATH	=	../../Binaries/

CFLAGS 		= 	-Wall -Wextra -g
CPPFLAGS	= 	-I../../Includes/ -I../Server
LDFLAGS 	= 	-L../../Libraries/
LDLIBS 		=	-lmy_cpp -lnetwork -pthread -lncurses

SRCS		=	main.cpp								\
				chat_room.cpp							\
				get_client_data.cpp 					\
				create_random_username.cpp 				\
				get_server_verification.cpp 			\
				recv_msg_thread.cpp						\
				send_msg_thread.cpp						\
				Games/CityBomber/main.cpp 				\
				Games/CityBomber/recv_game_data.cpp 	\
				Games/CityBomber/render_game.cpp 		\
				Games/CityBomber/send_input.cpp 		\
				Games/ConNet4/main.cpp 					\
				Games/ConNet4/recv_game_data.cpp 		\
				Games/ConNet4/render_game.cpp 			\
				Games/ConNet4/send_input.cpp 			\
				Games/NeTron/main.cpp 					\
				Games/NeTron/recv_game_data.cpp 		\
				Games/NeTron/render_game.cpp 			\
				Games/NeTron/send_input.cpp 			\

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