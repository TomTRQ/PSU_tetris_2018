/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** file that waits for an input to start game
*/

#include <termios.h>
#include "tetris.h"

void wait_for_input(option_t *option)
{
    struct termios info;
    char *buffer = malloc(sizeof(char) * 1);

    my_putstr("Press any key to start Tetris");
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &info);
    read(STDIN_FILENO, buffer, 1);
    free (buffer);
}