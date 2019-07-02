/*
** EPITECH PROJECT, 2019
** file that displays the map
** File description:
** tetris
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"

int check_pause_exit(option_t *option)
{
    static int count = 0;

    if (option->kb_event == option->k->key_pause && option->pause == 0) {
        option->pause = 1;
        mvprintw(option->height / 7, option->lenght / 2.5, "GAME PAUSED");
        refresh();
    }
    if (option->kb_event == option->k->key_pause && \
    option->pause == 1 && count > 100) {
        option->pause = 0;
        count = 0;
    }
    if (option->kb_event == option->k->key_quit) {
        endwin();
        keep_highest_score(option);
        exit(0);
    }
    count += 1;
    return (option->pause);
}