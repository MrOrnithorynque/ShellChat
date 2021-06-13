##
## EPITECH PROJECT, 2020
## root
## File description:
## Main Makefile
##

RM 			=	rm -f

LIB_PATH 	=	lib/my
SERVER_PATH =	server/
CLIENT_PATH =	client/

all:	make_lib make_project

make_lib:
	make -C $(LIB_PATH)

make_project:
	make -C $(SERVER_PATH)
	make -C $(CLIENT_PATH)

clean:
	make clean -C $(LIB_PATH)
	make clean -C $(SERVER_PATH)
	make clean -C $(CLIENT_PATH)
	$(RM) vgcore*

fclean:	clean
	make fclean -C $(LIB_PATH)
	make fclean -C $(SERVER_PATH)
	make fclean -C $(CLIENT_PATH)

re: 	fclean all

.PHONY: all clean fclean re make_lib