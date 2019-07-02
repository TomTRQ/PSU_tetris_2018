/*
** EPITECH PROJECT, 2019
** file that handles colors
** File description:
** tetris
*/

#include "tetris.h"

void color_problems(void)
{
    if (has_colors() == FALSE) {
        endwin();
        printw("Your terminal does not support color\n");
        exit(84);
    }
}

void initiate_colors(void)
{
    color_problems();
    start_color();
    init_color(COLOR_BLACK, 063, 0, 0);
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_WHITE);
    init_pair(T, COLOR_BLUE, COLOR_BLUE);
    init_pair(E, COLOR_WHITE, COLOR_WHITE);
    init_pair(R, COLOR_GREEN, COLOR_GREEN);
    init_pair(I, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(S, COLOR_CYAN, COLOR_CYAN);
    init_pair(S_RED, COLOR_RED, COLOR_RED);
    init_pair(ERROR, COLOR_RED, COLOR_BLACK);
}
