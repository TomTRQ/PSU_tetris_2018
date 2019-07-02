/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** check_error_piece.c
*/

#include "tetris.h"

int check_error_char(list_t *new, char **file, int i)
{
    if (i > new->size[1] && file[i][0] != '\n') {
        return (84);
    }
    for (int j = 0; file[i][j]; j++) {
        if (j > new->size[0] - 1 && file[i][j] != ' '
            && file[i][j] != '\n') {
            return (84);
        }
        if (file[i][j] != ' ' && file[i][j] != '*' && file[i][j] != '\0' && file[i][j] != '\n')
            return (84);
    }
    if (i != new->size[1] && !file[i + 1])
        return (84);
    return (0);
}

int check_error_piece(list_t *new, char **file)
{
    if (!file[0] || !file[1])
        return (84);
    for (int i = 1; file[i]; i++) {
        if (check_error_char(new, file, i) == 84)
            return (84);
    }
    return (0);
}