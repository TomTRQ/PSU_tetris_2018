##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile for the my_defender  project
##

SRC_PATH =	src/

SRC =		$(SRC_PATH)main.c 							\
		$(SRC_PATH)start_game.c							\
		$(SRC_PATH)basic_option.c						\
		$(SRC_PATH)tetris.c								\
		$(SRC_PATH)colors.c								\
		$(SRC_PATH)wrong_window_size.c					\
		$(SRC_PATH)display_map.c						\
		$(SRC_PATH)create_empty_map.c					\
		$(SRC_PATH)load_tetriminos/check_piece.c		\
		$(SRC_PATH)load_tetriminos/read_file.c			\
		$(SRC_PATH)load_tetriminos/get_name_file.c		\
		$(SRC_PATH)load_tetriminos/list_tetriminos.c	\
		$(SRC_PATH)load_tetriminos/check_name.c			\
		$(SRC_PATH)load_tetriminos/check_error_piece.c	\
		$(SRC_PATH)load_tetriminos/check_number.c		\
		$(SRC_PATH)get_highest_score.c  				\
		$(SRC_PATH)print_tetriminos_ingame.c    		\
		$(SRC_PATH)display_tetris_top_left.c    		\
		$(SRC_PATH)handle_time.c    					\
		$(SRC_PATH)option_arg/check_argv.c				\
		$(SRC_PATH)option_arg/set_key_option.c			\
		$(SRC_PATH)option_arg/set_option.c				\
		$(SRC_PATH)rotate_tetrimino.c					\
		$(SRC_PATH)option_arg/display_debug_mode.c		\
		$(SRC_PATH)option_arg/display_basic_option.c	\
		$(SRC_PATH)option_arg/display_line.c			\
		$(SRC_PATH)pause_and_exit.c                     \
		$(SRC_PATH)print_gameboard.c                    \
		$(SRC_PATH)new_tetrimino.c                      \
		$(SRC_PATH)wait_for_input.c                     \
		$(SRC_PATH)get_random_tetrimino.c               \
		$(SRC_PATH)remove_line.c                        \
		$(SRC_PATH)clean_str.c				\

OBJ =		$(SRC:.c=.o)

BINNAME = 	tetris

CFLAGS +=	-W -Wall -Wextra -pedantic -I ./include

LFLAGS =	-L lib -lmy -lncurses

all:		 $(NAME) $(BINNAME)

$(BINNAME):	$(OBJ)
			make -C lib/my/ re
			$(CC) -o $(BINNAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
			make -C lib/my/ clean
			rm -f $(OBJ)

fclean:		clean
			make -C lib/my/ fclean
			rm -f $(BINNAME)

debug:	CFLAGS += -g3
debug:	clean all

rclean:		all clean

re:			fclean all
