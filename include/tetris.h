/*
** EPITECH PROJECT, 2019
** file that contains the prototype of files
** File description:
** tetris
*/

#ifndef _TETRIS_H_
#define _TETRIS_H_

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include "structs.h"
#include "my.h"

#define WHITE 1
#define RED   2
#define T     3
#define E     4
#define R     5
#define I     6
#define S     7
#define S_RED 8
#define ERROR 9
#define TETRI 10
#define TETRI2 11

//WAIT_FOR_INPUT.C
void wait_for_input(option_t *option);

//NEW_TETRIMINO
int collision_tetrimino(option_t *option, int *modif, list_t *pieces);
int change_to_new_tetrimino(option_t *option, list_t *root, \
int *modif, list_t *pieces);
int check_if_full_line(int **colors, option_t *option);

//PRINT_GAMEBOARD.C
void print_map_on_board(char **map, option_t *option, int **colors);

//PAUSE_AND_EXIT.C
int check_pause_exit(option_t *option);

//DISPLAY_TETRIS_TOP_LEFT.C
void print_tetris(void);

//HANDLE_TIME.C
int handle_time(game_clock_t *game_clock, option_t *option);
game_clock_t *initiate_time_struct(void);

//WRONG_WINDOW_SIZE.C
int wrong_window_size(option_t *option);

//COLORS.C
void initiate_colors(void);

//PRINT_TETRIMINOS_INGAME.C
int print_next_tetriminos_to_fall(option_t *option, list_t *pieces);
void remove_previous_positions(option_t *option, list_t *pieces, \
int *pos);
int display_and_move_falling_tetrimino(option_t *option, \
list_t *pieces, list_t *root);
list_t *get_new_random_tetrimino(list_t *pieces, option_t *option);

//DISPLAY_MAP.C
int display_map(option_t *option, list_t *pieces, char **map);
int get_start_position(option_t *option, list_t *pieces);

//CREATE_EMPTY_MAP.C
char **create_empty_map(option_t *option, char **map);

//READ_IN_FILE.C
char **get_name_file(option_t *option);
int get_nb_piece(option_t *option);
char **read_file(char *name);
int check_name(struct dirent *lecture);
int check_error_piece(list_t *new, char **file);

//GET_HIGHEST_SCORE.C
int get_highest_score_from_file(option_t *option, char *buffer);
void keep_highest_score(option_t *option);

//LIST_TETRIMINOS
list_t *push_in_list(list_t *list, char *name);
list_t *set_list(list_t *list, char *name);
char *clean_str(char *str);
int check_number(char *str);
int check_tmp(char **tmp, list_t *new);
void set_value(list_t *new, char **tmp);

//DISPLAY_DEBUG_MODE
void display_debug_mode(option_t *option, list_t *piece);
void display_basic_option(option_t *option);
void display_line(char *line);

//CHECK_ARGV.C
int check_argv(option_t *option, list_t *piece, char **arg);

//ROTATE_TETRIMINO.C
char **rotate_tetriminos(char **tetrimino);

//SET_OPTION
int set_key_left(option_t *option, char *str);
int set_key_right(option_t *option, char *str);
int set_key_turn(option_t *option, char *str);
int set_key_drop(option_t *option, char *str);
int set_key_quit(option_t *option, char *str);
int set_key_pause(option_t *option, char *str);
int set_map_size(option_t *option, char *str);
int set_hide_tetriminos(option_t *option, char *str);
int set_debug_mode(option_t *option, char *str);
int set_level(option_t *option, char *str);

int **initiate_int_tab(option_t *option);
int tetris(int argc, char **argv, list_t *list);
void create_basic_option(option_t *option);
int start_game(option_t *option, list_t *piece);
list_t *check_piece(option_t *option, list_t *piece);

#endif
