##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for the bsq lib
##

SRC =		my_put_nbr.c 	\
			my_putchar.c 	\
			my_putstr.c 	\
			my_strlen.c 	\
			my_getnbr.c 	\
			my_strcmp.c		\
			my_strsplit.c	\
			my_strcopy.c	\
			merge_str.c		\
			alphab_order.c	\
			my_free.c		\
			my_check_nbr.c  \
			int_to_array.c  \
			my_intcpy.c     \
			initiate_int_tab.c  \

OBJ =		$(SRC:.c=.o)

NAME =		libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc -o $(NAME) $(OBJ)
			cp my.h ../../include/
			cp $(NAME) ../

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)
			rm -f ../$(NAME)

re:			fclean all