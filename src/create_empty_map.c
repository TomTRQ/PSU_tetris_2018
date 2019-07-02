/*
** EPITECH PROJECT, 2019
** file that creates the empty map for the tetris
** File description:
** tetris
*/

#include "tetris.h"

char **create_empty_map(option_t *option, char **map)
{
    int a = 0;
    int b = 0;

    while (a < option->size_map[1]) {
        map[a] = malloc(sizeof(char) * (option->size_map[0] + 1));
        while (b < option->size_map[0]) {
            map[a][b] = ' ';
            b = b + 1;
        }
        map[a][b] = '\0';
        b = 0;
        a = a + 1;
    }
    map[a] = NULL;
    return (map);
}