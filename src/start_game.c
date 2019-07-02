/*
** EPITECH PROJECT, 2019
** file that contains the function called by main
** File description:
** tetris
*/

#include "tetris.h"

void initiate_game_parameters(option_t *option, char **map, list_t *pieces)
{
    get_highest_score_from_file(option, NULL);
    map = create_empty_map(option, map);
    initscr();
    initiate_colors();
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);
    noecho();
    curs_set(FALSE);
    option->falling = pieces;
    option->to_fall = pieces->next;
    option->clock = 50000;
}

int start_game(option_t *option, list_t *pieces)
{
    char **map = malloc(sizeof(char *) * (option->size_map[1] + 1));
    option->colors = initiate_int_tab(option);
    int defeat = 0;

    initiate_game_parameters(option, map, pieces);
    option->game_clock = initiate_time_struct();
    while (defeat != 1) {
        getmaxyx(stdscr, option->height, option->lenght);
        if (wrong_window_size(option) == 0);
        else {
            handle_time(option->game_clock, option);
            defeat = display_map(option, pieces, map);
        }
    }
    endwin();
    keep_highest_score(option);
    return (0);
}
