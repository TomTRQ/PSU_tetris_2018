/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** my_free.c
*/

#include <stdlib.h>

void free_tab(char **str)
{
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
}