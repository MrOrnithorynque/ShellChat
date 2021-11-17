#
# EPITECH PROJECT, 2021
#

INCLUDES	=	Includes/my.hpp

INCLUDE_PATH=	../../Includes

RM 			=	rm -f

CPPFLAGS	= 	-I./Includes/

SRCS		=	String/print_err.cpp	\

OBJ 		= 	$(SRCS:.cpp=.o)

LIB_NAME	= 	libmy.a

all:
	@echo "\033[34m\n\n--- MYLIB MAKEFLIE ShellChat ---\n\033[0m"
	make make_lib

make_lib: $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	cp $(LIB_NAME) ../
	cp -t $(INCLUDE_PATH) $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB_NAME)
	cd .. && $(RM) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean