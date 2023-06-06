##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## for SBML parser
##

CC		=	gcc -Wall -Wextra -g

CFLAGS		=	-I include

NAME		=	SBMLparser

SRC		=	./src/main.c		\
			./src/display_usage.c	\
			./src/file_to_array.c	\
			./src/in_list_condition.c	\
			./src/list_utils.c	\
			./src/utils.c		\
			./src/my_strstr.c	\
			./src/sbml_parser.c

INC		=	include/my.h

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) Makefile~
	$(RM) src/*.c~
	$(RM) include/*.h~

re: fclean all
