##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/cd.c	\
		src/cd_2.c	\
		src/env.c	\
		src/exit.c	\
		src/path.c	\
		src/my_getenv.c	\
		src/setenv.c	\
		src/tool_box.c	\
		src/unsetenv.c	\
		src/anti_spaces.c

NAME	=	mysh

FLAG = -Wall -Wextra -ggdb -g3

all:	$(NAME)

$(NAME):
	make re -C lib/my
	gcc $(SRC) -L. -lmy -o $(NAME)

clean:
	rm -rf *~ \#*\# .\#*

fclean:
	rm -f $(NAME)

re:	fclean all clean