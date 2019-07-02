/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** set_key_option.c
*/

#include "tetris.h"

int set_key_left(option_t *option, char *str)
{
    if (!str)
        return (0);
    if (my_strcmp(str, "EOA") == 0)
        option->k->key_left = KEY_UP;
    if (my_strcmp(str, "EOB") == 0)
        option->k->key_left = KEY_DOWN;
    if (my_strcmp(str, "EOC") == 0)
        option->k->key_left = KEY_RIGHT;
    if (my_strcmp(str, "EOD") == 0)
        option->k->key_left = KEY_LEFT;
    if (option->k->key_left == KEY_LEFT && my_strlen(str) == 1) {
        option->k->key_left = str[0];
    }
    return (0);
}

int set_key_right(option_t *option, char *str)
{
    if (!str)
        return (0);
    if (my_strcmp(str, "EOA") == 0)
        option->k->key_right = KEY_UP;
    if (my_strcmp(str, "EOB") == 0)
        option->k->key_right = KEY_DOWN;
    if (my_strcmp(str, "EOC") == 0)
        option->k->key_right = KEY_RIGHT;
    if (my_strcmp(str, "EOD") == 0)
        option->k->key_right = KEY_LEFT;
    if (option->k->key_right == KEY_RIGHT && my_strlen(str) == 1) {
        option->k->key_right = str[0];
    }
    return (0);
}

int set_key_turn(option_t *option, char *str)
{
    if (!str)
        return (0);
    if (my_strcmp(str, "EOA") == 0)
        option->k->key_turn = KEY_UP;
    if (my_strcmp(str, "EOB") == 0)
        option->k->key_turn = KEY_DOWN;
    if (my_strcmp(str, "EOC") == 0)
        option->k->key_turn = KEY_RIGHT;
    if (my_strcmp(str, "EOD") == 0)
        option->k->key_turn = KEY_LEFT;
    if (option->k->key_turn == KEY_UP && my_strlen(str) == 1) {
        option->k->key_left = str[0];
    }
    return (0);
}

int set_key_drop(option_t *option, char *str)
{
    if (!str)
        return (0);
    if (my_strcmp(str, "EOA") == 0)
        option->k->key_drop = KEY_UP;
    if (my_strcmp(str, "EOB") == 0)
        option->k->key_drop = KEY_DOWN;
    if (my_strcmp(str, "EOC") == 0)
        option->k->key_drop = KEY_RIGHT;
    if (my_strcmp(str, "EOD") == 0)
        option->k->key_drop = KEY_LEFT;
    if (option->k->key_drop == KEY_DOWN && my_strlen(str) == 1) {
        option->k->key_drop = str[0];
    }
    return (0);
}

int set_key_quit(option_t *option, char *str)
{
    my_putstr(str);
    if (!str)
        return (0);
    if (my_strcmp(str, "{EOA}") == 0)
        option->k->key_quit = 273;
    if (my_strcmp(str, "{EOB}") == 0)
        option->k->key_quit = 274;
    if (my_strcmp(str, "{EOC}") == 0)
        option->k->key_quit = 275;
    if (my_strcmp(str, "{EOD}") == 0)
        option->k->key_quit = 276;
    if (option->k->key_quit == 'q' && my_strlen(str) == 1) {
        option->k->key_quit = str[0];
    }
    my_putchar(option->k->key_quit);
    return (0);
}