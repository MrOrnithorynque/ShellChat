##
## EPITECH PROJECT, 2020
## root
## File description:
## Main Makefile
##

RM 			=	rm -f

CC 			= 	gcc

LIB_PATH 	=	lib/my

CFLAGS 		= 	-Wall -Wextra -g
CPPFLAGS	= 	-I../includes/
LDFLAGS 	= 	-L../lib/
LDLIBS 		= 	-lmy -lnetwork -pthread

SRC 		= 	main.c			\

OBJ 		= 	$(SRC:.c=.o)

NAME 		= 	server

all:	$(NAME)
	@echo "\033[34mCompilation successful.\n\033[32m./$(NAME) created.\033[0m"

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

debug: 	CFLAGS += -g
debug: 	re

clean:
	$(RM) vgcore*
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all

run:	re
	./$(NAME)

.PHONY: all clean fclean re debug all run