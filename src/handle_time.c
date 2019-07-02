/*
** EPITECH PROJECT, 2019
** file that handles time of game_clock_t struct
** File description:
** tetris
*/

#include "tetris.h"

game_clock_t *initiate_time_struct(void)
{
    game_clock_t *game_clock = malloc(sizeof(game_clock_t));

    game_clock->minutes = 0;
    game_clock->seconds = 0;
    game_clock->s_seconds = 0;
    game_clock->milliseconds = 0;
    game_clock->only_sec = 0;
    return (game_clock);
}

int handle_time(game_clock_t *game_clock, option_t *option)
{
    static int count = 0;

    count = count + option->clock;
    if (count < 250000 || option->pause == 1)
        return (0);
    game_clock->s_seconds += 1;
    game_clock->only_sec += 1;
    if (game_clock->s_seconds > 9) {
        game_clock->s_seconds = 0;
        game_clock->seconds += 1;
        game_clock->milliseconds = 0;
    }
    if (game_clock->seconds >= 6) {
        game_clock->milliseconds = 0;
        game_clock->seconds = 0;
        game_clock->minutes += 1;
    }
    count = 0;
    return (0);
}