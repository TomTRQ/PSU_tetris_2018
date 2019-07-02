/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** check_piece.c
*/

#include "tetris.h"

void free_name_file(option_t *option, char **name)
{
    for (int i = 0; i != option->nb_piece; i++)
        free(name[i]);
    free(name);
}

list_t *check_piece(option_t *option, list_t *piece)
{
    char **name_file;

    if (get_nb_piece(option) == 84)
        return (NULL);
    name_file = get_name_file(option);
    if (!name_file)
        return (NULL);
    name_file = make_alphab_order(name_file, option->nb_piece);
    piece = set_list(piece, name_file[0]);
    if (!piece)
        return (NULL);
    for (int i = 1; i != option->nb_piece; i++) {
        piece = push_in_list(piece, name_file[i]);
    }
    free_name_file(option, name_file);
    return (piece);
}