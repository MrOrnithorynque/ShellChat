#
# ShellChat main Makefile
#

SRCS_PATH	=	Sources/

LIBS_PATH	=	Libraries/

all:
	@echo "\n\033[34m\n--- MAIN MAKEFILE ShellChat---\n\n\033[0m"
	make make_libs
	make make_srcs

make_libs:
	mkdir -p Includes Binaries
	make -C $(LIBS_PATH)

make_srcs:
	make -C $(SRCS_PATH)

clean:
	make clean -C $(LIBS_PATH)
	make clean -C $(SRCS_PATH)

fclean:
	rm -r Includes Binaries
	make fclean -C $(LIBS_PATH)
	make fclean -C $(SRCS_PATH)

re:
	make re -C $(LIBS_PATH)
	make re -C $(SRCS_PATH)

run:
	make run -C $(SRCS_PATH)

docker:
	make build_docker
	make run_docker

build_docker:
	docker build -t shellchat-docker .

run_docker:
	docker run shellchat-docker

.PHONY: all make_libs clean fclean re run docker build_docker run_docker