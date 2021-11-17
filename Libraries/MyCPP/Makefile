
INCLUDES	=	Includes/

INCLUDE_PATH=	../../Includes

RM 			=	rm -f

CPPFLAGS	= 	-I./Includes/

SRCS		=	Array/array_2d_len.cpp 			\
				Array/malloc_2d_array.cpp 		\
				Array/malloc_3d_array.cpp 		\
				Array/malloc_array.cpp 			\
				Array/offset_array.cpp 			\
				String/get_floating_point.cpp 	\
				String/get_integer.cpp			\
				String/put_error.cpp			\
				String/rm_white_space.cpp		\
				String/str_to_array.cpp			\
				String/strdup.cpp 				\
				String/string.cpp 				\
				String/strlen.cpp 				\
				Utils/free_data.cpp 			\

OBJ 		= 	$(SRCS:.cpp=.o)

LIB_NAME	= 	libmy_cpp.a

all:
	@echo "\033[34m\n\n--- MYCPP MAKEFLIE ---\n\033[0m"
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