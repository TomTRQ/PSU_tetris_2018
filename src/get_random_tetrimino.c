/*
** EPITECH PROJECT, 2019
** file that displays the map
** File description:
** tetris
*/

#include "tetris.h"

list_t *get_new_random_tetrimino(list_t *pieces, option_t *option)
{
    list_t *temp = pieces;
    int random = 0;

    random = rand() % option->nb_piece;
    while (temp->id != random) {
        temp = temp->next;
        if (temp == NULL)
            return (pieces);
    }
    return (temp);
}