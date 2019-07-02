/*
** EPITECH PROJECT, 2019
** file that contains the structs
** File description:
** tetris
*/

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef struct key_list_s {
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
} key_list_t;

typedef struct option_s {
    int level;
    int lines;
    int *size_map;
    int nb_arg;
    int hide_tetrimino;
    int debug_mode;
    int clock;
    int nb_piece;
    int score;
    int height;
    int lenght;
    int kb_event;
    int pause;
    int highest_score;
    key_list_t *k;
    int **colors;
    struct list_s *falling;
    struct list_s *to_fall;
    struct game_clock_t *game_clock;
} option_t;

typedef struct game_clock_t {
    int minutes;
    int only_sec;
    int seconds;
    int s_seconds;
    int milliseconds;
}game_clock_t;

typedef struct list_s {
    int id;
    char *name;
    char **piece;
    int *size;
    int color;
    int error_value;
    struct list_s *next;
} list_t;

#endif