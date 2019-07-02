/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** display_debug_mode.c
*/

#include "tetris.h"

void display_special_char(int key)
{
    switch (key) {
        case KEY_UP:
            my_putstr("^EOA\n");
            break;
        case KEY_DOWN:
            my_putstr("^EOB\n");
            break;
        case KEY_RIGHT:
            my_putstr("^EOC\n");
            break;
        case KEY_LEFT:
            my_putstr("^EOD\n");
            break;
        case ' ':
            my_putstr("(space)\n");
            break;
        default:
            my_putchar(key);
            my_putchar('\n');
    }
}

void display_key(option_t *option)
{
    write(1, "*** DEBUG MODE ***\n", 19);
    write(1, "Key Left :  ", 12);
    display_special_char(option->k->key_left);
    write(1, "Key Right :  ", 13);
    display_special_char(option->k->key_right);
    write(1, "Key Turn :  ", 12);
    display_special_char(option->k->key_turn);
    write(1, "Key Drop :  ", 12);
    display_special_char(option->k->key_drop);
    write(1, "Key Quit :  ", 12);
    display_special_char(option->k->key_quit);
    write(1, "Key Pause :  ", 13);
    display_special_char(option->k->key_pause);
    write(1, "Next :  ", 8);
}

void display_tetriminos_name(char *name)
{
    char **tmp = my_strsplit(name, '.');

    my_putstr("Tetriminos :  Name ");
    my_putstr(tmp[0]);
    my_putstr(" :  ");
    free_tab(tmp);
}

void display_tetriminos(list_t *piece)
{
    display_tetriminos_name(piece->name);
    if (piece->error_value == 1) {
        my_putstr("Error\n");
        return;
    }
    my_putstr("Size ");
    my_put_nbr(piece->size[0]);
    my_putchar('*');
    my_put_nbr(piece->size[1]);
    my_putstr(" :  Color ");
    my_put_nbr(piece->color);
    my_putstr(" :\n");
    for (int i = 0; piece->piece[i]; i++) {
        display_line(piece->piece[i]);
        my_putchar('\n');
    }
}

void display_debug_mode(option_t *option, list_t *piece)
{
    list_t *tmp = piece;

    display_key(option);
    if (option->hide_tetrimino == 0)
        my_putstr("Yes\n");
    else
        my_putstr("No\n");
    display_basic_option(option);
    while (tmp != NULL) {
        display_tetriminos(tmp);
        if (tmp->next != NULL)
            my_putchar('\n');
        tmp = tmp->next;
    }
    wait_for_input(option);
}