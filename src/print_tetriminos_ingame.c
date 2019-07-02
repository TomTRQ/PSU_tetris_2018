/*
** EPITECH PROJECT, 2019
** file that displays the map
** File description:
** tetris
*/

#include "tetris.h"

void handle_positions(int *modif, int *tab, option_t *option, \
list_t *pieces)
{
    int lenght = tab[2] + pieces->size[0] + modif[1];

    if (option->kb_event == option->k->key_left && \
    tab[1] + tab[2] + modif[1] > 0)
        modif[1] -= 1;
    else if (option->kb_event == option->k->key_right && \
    lenght < option->size_map[0])
        modif[1] += 1;
}

void print_new_tetrimino_position(int *tab, int *modif, \
list_t *pieces, option_t *option)
{
    if (pieces->piece[tab[0]][tab[1]] == '*') {
        option->colors[tab[0] + modif[0]][tab[1] + tab[2] + modif[1]] = \
        pieces->color;
    }
    tab[1] = tab[1] + 1;
}

int display_and_move_falling_tetrimino(option_t *option, list_t *pieces, \
list_t *root)
{
    int tab[3] = {0, 0, get_start_position(option, pieces)};
    static int modif[2] = {0, 0};

    if (modif[0] > option->size_map[1] - pieces->size[1] || \
    collision_tetrimino(option, modif, pieces) == 1)
        while (check_if_full_line(option->colors, option) == 1);
    else {
        handle_positions(modif, tab, option, pieces);
        remove_previous_positions(option, pieces, modif);
    }
    if (change_to_new_tetrimino(option, root, modif, pieces) == 1)
        return (1);
    while (pieces->piece[tab[0]] != NULL) {
        while (pieces->piece[tab[0]][tab[1]] != '\0')
            print_new_tetrimino_position(tab, modif, pieces, option);
        tab[1] = 0;
        tab[0] = tab[0] + 1;
    }
    modif[0] += 1;
    return (0);
}

int print_next_tetriminos_to_fall(option_t *option, list_t *pieces)
{
    int a = 0;

    if (pieces == NULL)
        return (84);
    if (option->hide_tetrimino == 0) {
        init_pair(TETRI, pieces->color, COLOR_BLACK);
        attron(COLOR_PAIR(TETRI));
        while (pieces->piece[a] != NULL) {
            mvprintw(option->height / 9 + a + 3, \
        option->lenght / 5 * 3.5 + 4, "%s", pieces->piece[a]);
            a = a + 1;
        }
        attroff(COLOR_PAIR(TETRI));
    }
    return (0);
}

