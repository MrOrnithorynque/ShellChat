#
# ShellChat sources Makefile
#

CC			=	g++

EXEC_NAME	=	ShellChat_server
EXEC_PATH	=	../../Binaries/

CFLAGS 		= 	-Wall -Wextra -g
CPPFLAGS	= 	-I../../Includes/ -I../Client -I./ -I../
LDFLAGS 	= 	-L../../Libraries/
LDLIBS 		=	-lmy_cpp -lnetwork -pthread -lncurses

SRCS		=	main.cpp								\
				client_thread.cpp 						\
				client_verification.cpp 				\
				command.cpp 							\
				error_handling.cpp 						\
				handle_client.cpp						\
				host_settings.cpp 						\
				Games/CityBomber/main.cpp 				\
				Games/CityBomber/recv_input.cpp			\
				Games/CityBomber/render_game.cpp 		\
				Games/CityBomber/send_game_data.cpp 	\
				Games/ConNet4/main.cpp 					\
				Games/ConNet4/recv_input.cpp			\
				Games/ConNet4/render_game.cpp 			\
				Games/ConNet4/send_game_data.cpp 		\
				Games/NeTron/main.cpp 					\
				Games/NeTron/recv_input.cpp				\
				Games/NeTron/render_game.cpp 			\
				Games/NeTron/send_game_data.cpp 		\
				HostClass/bind.cpp 						\
				HostClass/generate_port.cpp 			\
				HostClass/get_host_ip.cpp 				\
				HostClass/host_settings.cpp				\
				HostClass/listen.cpp 					\
				HostClass/send_to_all.cpp				\

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