/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** check_number.c
*/

#include "tetris.h"

void set_value(list_t *new, char **tmp)
{
    new->color = my_getnbr(tmp[2]);
    new->size[0] = my_getnbr(tmp[0]);
    new->size[1] = my_getnbr(tmp[1]);
}

int check_tmp(char **tmp, list_t *new)
{
    new->piece = NULL;
    if (!tmp[2] || tmp[3])
        return (84);
    return (0);
}

int check_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (84);
    }
    return (0);
}