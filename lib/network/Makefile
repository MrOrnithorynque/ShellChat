##
## EPITECH PROJECT, 2021
## Lib
## File description:
## Makefile for lib/my
##

INCLUDE		=	network.h

INCLUDE_PATH=	../../includes

RM 			=	rm -f

LIB			=	create_socket.c 	\

OBJ 		= 	$(LIB:.c=.o)

NAME_LIB	= 	libnetwork.a

all: 	$(NAME_LIB)

$(NAME_LIB): $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	cp $(NAME_LIB) ../
	cp $(INCLUDE) $(INCLUDE_PATH)

clean:
	$(RM) vgcore*
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME_LIB)
	cd .. && $(RM) $(NAME_LIB)

.PHONY: all clean fclean