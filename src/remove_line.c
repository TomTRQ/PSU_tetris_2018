/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** display_debug_mode.c
*/

#include "tetris.h"

void remove_line(int *modif, int *tab, option_t *option, list_t *pieces)
{
    if (modif[0] > 0 && pieces->piece[tab[0]][tab[1]] == '*' && \
    modif[0] <= option->size_map[1] - pieces->size[1]) {
        option->colors[tab[0] + modif[0] - 1]\
        [tab[1] + tab[2] + tab[3]] = -1;
    }
    tab[1] = tab[1] + 1;
}

void remove_previous_positions(option_t *option, list_t *pieces, int *modif)
{
    static int tab[4] = {0, 0, 0, 0};

    tab[2] = get_start_position(option, pieces);
    while (pieces->piece[tab[0]] != NULL) {
        while (pieces->piece[tab[0]][tab[1]] != '\0')
            remove_line(modif, tab, option, pieces);
        tab[1] = 0;
        tab[0] = tab[0] + 1;
    }
    tab[3] = modif[1];
    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;
}