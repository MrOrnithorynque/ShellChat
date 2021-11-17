
SERVER_PATH	=	Server/
CLIENT_PATH	=	Client/

all:
	@echo "\n\033[34m\n--- SOURCES MAKEFILE ShellChat ---\n\n\033[0m"
	make -C $(SERVER_PATH)
	make -C $(CLIENT_PATH)

clean:
	make clean -C $(SERVER_PATH)
	make clean -C $(CLIENT_PATH)

fclean:
	make fclean -C $(SERVER_PATH)
	make fclean -C $(CLIENT_PATH)

re:
	make re -C $(SERVER_PATH)
	make re -C $(CLIENT_PATH)

run:
	make run-C $(SERVER_PATH)

.PHONY: all make_libs clean fclean re run