/*
** EPITECH PROJECT, 2019
** file that displays the map
** File description:
** tetris
*/

#include "tetris.h"

void print_vertical_lines(int start, int end, int lenght)
{
    for (int a = start; a < end; a = a + 2) {
        mvprintw(a, lenght, "|");
        mvprintw(a + 1, lenght, " ");
    }
}

void print_middle_board(option_t *option)
{
    int count = 0;

    attron(COLOR_PAIR(E));
    for (; count < option->size_map[0] + 1; count++)
        mvprintw(option->height / 2 - 10, option->lenght / 3 + count, "-");
    mvprintw(option->height / 2 - 10, option->lenght / 3, "+");
    mvprintw(option->height / 2 - 10, option->lenght / 3 + count, "+");
    print_vertical_lines(option->height / 2 - 9, option->height / 2 - 3 + \
    option->size_map[1] - 6, option->lenght / 3);
    print_vertical_lines(option->height / 2 - 9, option->height / 2 - 3 + \
    option->size_map[1] - 6, option->lenght / 3 + option->size_map[0] + 1);
    count = 0;
    for (; count < option->size_map[0] + 1; count++)
        mvprintw(option->size_map[1] + option->height / 2 - 9, \
        option->lenght / 3 + count, "-");
    mvprintw(option->size_map[1] + option->height / 2 - 9, \
    option->lenght / 3, "+");
    mvprintw(option->size_map[1] + option->height / 2 - 9, \
    option->lenght / 3 + count, "+");
    attroff(COLOR_PAIR(E));
}

void draw_map(option_t *option, game_clock_t *game_clock)
{
    attron(COLOR_PAIR(WHITE));
    mvprintw(option->height / 4 + 6, 3, "/--------------------\\");
    print_vertical_lines(option->height / 4 + 8, option->height / 3 + 11, 24);
    mvprintw(option->height / 4 + 8, 5, "Highest Score  %d", \
    option->highest_score);
    mvprintw(option->height / 4 + 9, 5, "Score          %d", option->score);
    mvprintw(option->height / 4 + 11, 5, "Level          %d", option->level);
    mvprintw(option->height / 4 + 12, 5, "Lines          %d", option->lines);
    mvprintw(option->height / 4 + 14, 5, "Timer         %d:%d%d", \
    game_clock->minutes, game_clock->seconds, game_clock->s_seconds);
    print_vertical_lines(option->height / 4 + 8, option->height / 3 + 11, 3);
    mvprintw(option->height / 4 + 15, 3, "\\--------------------/");
    print_middle_board(option);
    mvprintw(option->height / 9, option->lenght / 5 * 3.5, "/---");
    attron(COLOR_PAIR(RED));
    mvprintw(option->height / 9, option->lenght / 5 * 3.5 + 4, "next");
    attroff(COLOR_PAIR(RED));
    mvprintw(option->height / 9, option->lenght / 5 * 3.5 + 8,"------\\");
    attroff(COLOR_PAIR(WHITE));
}

int get_start_position(option_t *option, list_t *pieces)
{
    int a = 0;
    int count = option->size_map[0] / 2;

    while (pieces->piece[0][a] != '\0')
        a = a + 1;
    count = count - a / 2;
    return (count);
}

int display_map(option_t *option, list_t *pieces, char **map)
{
    list_t *root = pieces;

    option->kb_event = getch();
    if (check_pause_exit(option) == 1) {
        return (0);
    }
    clear();
    print_tetris();
    draw_map(option, option->game_clock);
    print_next_tetriminos_to_fall(option, option->to_fall);
    display_and_move_falling_tetrimino(option, option->falling, root);
    print_map_on_board(map, option, option->colors);
    refresh();
    if (option->kb_event == option->k->key_drop)
        usleep(option->clock / option->level * 4.5 / 2);
    else
        usleep(option->clock / option->level * 4.5);
    return (0);
}