#
# ShellChat libraries Makefile
#

MYCPP_PATH	= MyCPP/
MY_NET_PATH = MyNet/

all:
	@echo "\033[34m\n\n--- LIBRARIES MAKEFLIE ShellChat ---\n\033[0m"
	make make_libs

make_libs:
	make -C $(MYCPP_PATH)
	make -C $(MY_NET_PATH)

clean:
	make clean -C $(MYCPP_PATH)
	make clean -C $(MY_NET_PATH)

fclean:
	make fclean -C $(MYCPP_PATH)
	make fclean -C $(MY_NET_PATH)

re:
	make re -C $(MYCPP_PATH)
	make re -C $(MY_NET_PATH)

.PHONY: all make_libs clean fclean re