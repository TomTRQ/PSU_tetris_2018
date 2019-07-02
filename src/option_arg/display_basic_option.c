/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** display_basic_option.c
*/

#include "tetris.h"

void display_basic_option(option_t *option)
{
    my_putstr("level :  ");
    my_put_nbr(option->level);
    my_putchar('\n');
    my_putstr("size :  ");
    my_put_nbr(option->size_map[0]);
    my_putchar('*');
    my_put_nbr(option->size_map[1]);
    my_putchar('\n');
    my_putstr("Tetriminos :  ");
    my_put_nbr(option->nb_piece);
    my_putchar('\n');
}