/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** tetris.c
*/

#include "tetris.h"

void free_tetris(option_t *option, list_t *piece)
{
    list_t *tmp = piece;
    list_t *supp;

    while (tmp != NULL) {
        free(tmp->size);
        free(tmp->name);
        if (tmp->piece)
            free_tab(tmp->piece);
        supp = tmp;
        tmp = tmp->next;
        free(supp);
    }
    free(option->k);
    free(option->size_map);
    free(option);
}

int tetris(int argc, char **argv, list_t *piece)
{
    option_t *option = malloc(sizeof(option_t));

    option->k = malloc(sizeof(key_list_t));
    if (!option || !option->k)
        return (84);
    create_basic_option(option);
    piece = check_piece(option, piece);
    if (piece == NULL) {
        free_tetris(option, piece);
        return (84);
    }
    option->nb_arg = argc;
    if (check_argv(option, piece, argv) == 84) {
        free_tetris(option, piece);
        return (84);
    }
    start_game(option, piece);
    keep_highest_score(option);
    free_tetris(option, piece);
    return (0);
}
