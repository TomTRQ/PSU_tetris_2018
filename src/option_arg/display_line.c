/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** display_line.c
*/

#include "tetris.h"

void display_line(char *line)
{
    int counter_stars = 0;
    int counter = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '*')
            counter_stars++;
    }
    for (int i = 0; line[i]; i++) {
        my_putchar(line[i]);
        if (line[i] == '*')
            counter++;
        if (counter == counter_stars)
            break;
    }
}