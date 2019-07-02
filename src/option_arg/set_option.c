/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** set_option.c
*/

#include "tetris.h"

int set_key_pause(option_t *option, char *str)
{
    if (!str)
        return (0);
    option->k->key_pause = ' ';
    if (my_strcmp(str, "EOA") == 0)
        option->k->key_pause = 273;
    if (my_strcmp(str, "EOB") == 0)
        option->k->key_pause = 274;
    if (my_strcmp(str, "EOC") == 0)
        option->k->key_pause = 275;
    if (my_strcmp(str, "EOD") == 0)
        option->k->key_pause = 276;
    if (option->k->key_pause == ' ' && my_strlen(str) == 1) {
        option->k->key_pause = str[0];
    }
    return (0);
}

int set_map_size(option_t *option, char *str)
{
    char **tmp_str = my_strsplit(str, ',');

    if (!tmp_str[1] || tmp_str[2])
        return (84);
    for (int i = 0; tmp_str[0][i]; i++) {
        if (tmp_str[0][i] < '0' || tmp_str[0][i] > '9')
            return (84);
    }
    for (int i = 0; tmp_str[1][i]; i++) {
        if (tmp_str[1][i] < '0' || tmp_str[1][i] > '9')
            return (84);
    }
    option->size_map[0] = my_getnbr(tmp_str[0]);
    option->size_map[1] = my_getnbr(tmp_str[1]);
    if (option->size_map[0] < 3 || option->size_map[1] < 3)
        return (84);
    return (0);
}

int set_hide_tetriminos(option_t *option, char *str)
{
    if (!str)
        option->hide_tetrimino = 1;
    option->hide_tetrimino = 1;
    return (0);
}

int set_debug_mode(option_t *option, char *str)
{
    if (!str)
        option->debug_mode = 1;
    option->debug_mode = 1;
    return (0);
}

int set_level(option_t *option, char *str)
{
    int nb = 0;

    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (84);
    }
    nb = my_getnbr(str);
    if (nb < 1)
        return (84);
    option->level = nb;
    return (0);
}