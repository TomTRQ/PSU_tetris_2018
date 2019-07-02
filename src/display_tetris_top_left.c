/*
** EPITECH PROJECT, 2019
** file that displays TETRIS at the top
** File description:
** tetris
*/

#include "tetris.h"

void print_vertical_lines_tetris(int beg, int end, int x)
{
    int a = beg;

    while (a < end) {
        mvprintw(a, x, "*");
        a = a + 1;
    }
}

void print_second_line_tetris(void)
{
    attron(COLOR_PAIR(R));
    print_vertical_lines_tetris(7, 12, 5);
    print_vertical_lines_tetris(10, 12, 9);
    mvprintw(7, 6, "****");
    mvprintw(8, 9, "*");
    mvprintw(9, 6, "***");
    attron(COLOR_PAIR(I));
    mvprintw(7, 13, "*");
    print_vertical_lines_tetris(9, 12, 13);
    mvprintw(7, 14, "*");
    print_vertical_lines_tetris(9, 12, 14);
    attron(COLOR_PAIR(S));
    mvprintw(7, 18, "*****");
    print_vertical_lines_tetris(7, 10, 18);
    mvprintw(9, 18, "****");
    print_vertical_lines_tetris(9, 12, 22);
    mvprintw(11, 18, "****");
    attroff(COLOR_PAIR(S));
}

void print_tetris(void)
{
    attron(COLOR_PAIR(T));
    mvprintw(1, 2, "*********");
    print_vertical_lines_tetris(2, 6, 6);
    attron(COLOR_PAIR(E));
    print_vertical_lines_tetris(2, 5, 12);
    mvprintw(1, 12, "****");
    mvprintw(3, 12, "****");
    mvprintw(5, 12, "****");
    attron(COLOR_PAIR(S_RED));
    mvprintw(1, 17, "*********");
    print_vertical_lines_tetris(2, 6, 21);
    print_second_line_tetris();
}