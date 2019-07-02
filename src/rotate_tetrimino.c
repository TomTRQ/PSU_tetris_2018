/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** rotate_tetrimino.c
*/

#include "tetris.h"

char **malloc_rotation(char **tetriminos)
{
    char **new;
    int counter_x = 0;
    int counter_y = 0;

    for (int i = 0; tetriminos[i]; i++) {
        for (int j = 0; tetriminos[i][j]; j++) {
            if (j > counter_x)
                counter_x = j;
        }
        counter_y++;
    }
    counter_x++;
    new = malloc(sizeof(char *) * (counter_x + 1));
    for (int i = 0; i < counter_x; i++) {
        new[i] = malloc(sizeof(char) * counter_y + 1);
        for (int j = 0; j != counter_y + 1; j++)
            new[i][j] = '\0';
    }
    new[counter_x] = NULL;
    return (new);
}

char **rotate_tetriminos(char **tetrimino)
{
    char **new_tetrimino = malloc_rotation(tetrimino);
    int size_x = 0;
    int size_y = 0;

    for (int i = 0; tetrimino[i]; i++) {
        for (int j = 0; tetrimino[i][j]; j++) {
            if (j > size_x)
                size_x = j;
        }
        size_y++;
    }
    for (int i = 0; i != size_x + 1; i++) {
        for (int j = 0; j != size_y; j++) {
            new_tetrimino[i][j] = tetrimino[size_y - j - 1][i];
            new_tetrimino[i][j + 1] = '\0';
        }
    }
    return (new_tetrimino);
}