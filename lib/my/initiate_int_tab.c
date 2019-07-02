/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header file for library
*/

#include "../../include/tetris.h"

int **initiate_int_tab(option_t *option)
{
    int **colors =  malloc(sizeof(int *) * (option->size_map[1] + 1));
    int a = 0;
    int b = 0;

    while (a < option->size_map[1]) {
        colors[a] = malloc(sizeof(int) * (option->size_map[0] + 1));
        while (b < option->size_map[0]) {
            colors[a][b] = -1;
            b = b + 1;
        }
        colors[a][b] = -2;
        b = 0;
        a = a + 1;
    }
    colors[a] = NULL;
    return (colors);
}