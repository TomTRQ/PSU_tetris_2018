/*
** EPITECH PROJECT, 2019
** main file for the project
** File description:
** Tetris
*/

#include "tetris.h"

void display_name(char *name_bin)
{
    my_putstr("Usage:  ");
    my_putstr(name_bin);
    my_putstr(" [options]\n");
}

void display_help(char *name_bin)
{
    display_name(name_bin);
    my_putstr("Options:\n");
    my_putstr(" --help\t\t      Display this help\n");
    my_putstr(" -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr(" -l --key-left={K}    Move the tetrimino LEFT");
    my_putstr(" using the K key (def: left arrow)\n");
    my_putstr(" -r --key-right={K}   Move the tetrimino RIGHT");
    my_putstr(" using the K key (def: right arrow)\n");
    my_putstr(" -t --key-turn={K}    TURN the tetrimino clockwise 90d");
    my_putstr(" using the K key (def: top arrow)\n");
    my_putstr(" -d --key-drop={K}    DROP the tetrimino");
    my_putstr(" using the K key (def: down arrow)\n");
    my_putstr(" -q --key-quit={K}    QUIT the game");
    my_putstr(" using the K key (def: 'q' key)\n");
    my_putstr(" -p --key-pause={K}   PAUSE/RESTART the game");
    my_putstr(" using the K key (def: space bar)\n");
    my_putstr(" --map-size={row,col} Set the numbers of rows and columns");
    my_putstr(" of the map (def: 20,10)\n");
    my_putstr(" -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr(" -D --debug\t      Debug mode (def: false)\n");
}

int main(int argc, char **argv, char **env)
{
    if (argv[1]) {
        if (my_strcmp(argv[1], "--help") == 0) {
            display_help(argv[0]);
            return (0);
        }
    }
    if (env[0] == NULL)
        return (84);
    if (tetris(argc, argv, NULL) == 84) {
        display_help(argv[0]);
        return (84);
    }
    return (0);
}
