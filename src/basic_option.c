/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** basic_option.c
*/

#include "tetris.h"

static void list_basic_key(option_t *option)
{
    option->k->key_drop = KEY_DOWN;
    option->k->key_left = KEY_LEFT;
    option->k->key_right = KEY_RIGHT;
    option->k->key_turn = KEY_UP;
    option->k->key_pause = ' ';
    option->k->key_quit = 'q';
}

static void basic_option(option_t *option)
{
    option->nb_piece = 0;
    option->debug_mode = 0;
    option->hide_tetrimino = 0;
    option->level = 1;
    option->size_map = malloc(sizeof(int) * 2);
    option->size_map[0] = 10;
    option->size_map[1] = 20;
}

void create_basic_option(option_t *option)
{
    list_basic_key(option);
    basic_option(option);
}
