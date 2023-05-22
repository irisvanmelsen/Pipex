FROM debian:latest

ENV CC="gcc" CFLAGS="-Wall -Wextra -Werror"

RUN apt-get -y update \
&& \
	apt-get install \
	gcc \
	vim \
	make \
	git \
	lldb \
	valgrind \
	libcriterion-dev \
	libreadline-dev \
	strace \
	manpages \
	less \
	-y \
&& \
	apt-get clean \
&& \
	rm -rf /var/lib/apt/lists/*


#	
#	start up docker application
#
#	to build image:
#	docker build ./ -f Dockerfile
#
#	to find image_ID:
#	docker image list
#
#	to run docker container:
#	docker run -it --rm -v $PWD:/pipex [image_tag/image_ID]
#
#	cd marsh
#	make fclean
#	make dock DEBUG=1 (executable = "marshell")
#
#	to run valgrind:
#	valgrind --leak-check=full --show-leak-kinds=all ./[EXE]
#	valgrind --leak-check=full --traces-children=yes ./pipex (OPTIONIAL: --show-leak-kinds=all)
#	leaks shown at exit (or ctrl-D)
#