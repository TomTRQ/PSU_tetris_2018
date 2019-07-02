/*
** EPITECH PROJECT, 2019
** file that displays the gameboard
** File description:
** tetris
*/

#include "tetris.h"

void print_colored_stars(int *tab, option_t *option, int **colors)
{
    if (colors[tab[0]][tab[1]] >= 0) {
        init_pair(TETRI2, colors[tab[0]][tab[1]], COLOR_BLACK);
        attron(COLOR_PAIR(TETRI2));
        mvprintw(tab[2] + tab[0], option->lenght / 3 + 1 + tab[1], "*");
        attroff(COLOR_PAIR(TETRI2));
    }
}

void print_map_on_board(char **map, option_t *option, int **colors)
{
    int tab[3] = {0, 0, option->height / 2 - 9};

    while (map[tab[0]] != NULL) {
        while (map[tab[0]][tab[1]] != '\0') {
            print_colored_stars(tab, option, colors);
            tab[1] = tab[1] + 1;
        }
        tab[1] = 0;
        tab[0] = tab[0] + 1;
    }
}