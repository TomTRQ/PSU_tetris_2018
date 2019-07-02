/*
** EPITECH PROJECT, 2019
** file that checks if the size of the window is too small
** File description:
** tetris
*/

#include "tetris.h"

void print_minimal_and_actual_size(option_t *option)
{
    clear();
    mvprintw(option->height / 2, option->lenght / 3, \
    "Enlarge your Terminal please");
    mvprintw(option->height / 2 + 3, option->lenght / 3, \
    "The minimum size should be:");
    mvprintw(option->height / 2 + 4, option->lenght / 3, \
    "%d in width and %d in height", \
    option->size_map[0] + 45, option->size_map[1] + 2);
    mvprintw(option->height / 2 + 6, option->lenght / 3 - 3, \
    "Your terminal size is %d/w and %d/h", option->lenght, option->height);
}

int wrong_window_size(option_t *option)
{
    if (option->lenght < option->size_map[0] + 10 || \
    option->height < option->size_map[1] + 5) {
        print_minimal_and_actual_size(option);
        attron(COLOR_PAIR(ERROR));
        if (option->lenght < option->size_map[0] + 45 && \
        option->height < option->size_map[1]+ 2)
            mvprintw(option->height / 2 + 8, option->lenght / 3 - 2, \
            "ENLARGE YOUR WIDTH AND YOUR HEIGHT");
        else if (option->height < option->size_map[1] + 2)
            mvprintw(option->height / 2 + 8, option->lenght / 3 + 4, \
            "ENLARGE YOUR HEIGHT");
        else
            mvprintw(option->height / 2 + 8, option->lenght / 3 + 4, \
            "ENLARGE YOUR WIDTH");
        attroff(COLOR_PAIR(ERROR));
        refresh();
        usleep(40000);
        return (0);
    }
    return (1);
}
