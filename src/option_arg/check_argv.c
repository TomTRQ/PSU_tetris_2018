/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** check_argv.c
*/

#include "tetris.h"

int check_argv_basic(option_t *option, char *arg, char *value)
{
    int error_value = 0;
    int (*listFonctions[9])(option_t *option, char *) = {set_level,
        set_key_left, set_key_right, set_key_turn, set_key_drop, set_key_quit,
        set_key_pause, set_hide_tetriminos, set_debug_mode};
    char *order_list[10] = {"-L", "-l", "-r", "-t", "-d", "-q", "-p",
                            "-w", "-D", NULL};

    for (int i = 0; order_list[i] != NULL; i++) {
        if (my_strcmp(arg, order_list[i]) == 0) {
            error_value = listFonctions[i](option, value);
            return (error_value);
        }
    }
    return (0);
}

int check_argv_complex(option_t *option, char *arg)
{
    int error_value = 0;
    int (*listFonctions[10])(option_t *option, char *) = {set_level,
        set_key_left, set_key_right, set_key_turn, set_key_drop, set_key_quit,
        set_key_pause, set_map_size, set_hide_tetriminos, set_debug_mode};
    char **commande_set = my_strsplit(arg, '=');
    char *order_list[11] = {"--level", "--key-left", "--key-right",
                            "--key-turn", "--key-drop", "--key-quit",
                            "--key-pause", "--map-size", "--without-next",
                            "--debug", NULL};

    for (int i = 0; order_list[i] != NULL; i++) {
        if (my_strcmp(commande_set[0], order_list[i]) == 0) {
            error_value = listFonctions[i](option, commande_set[1]);
            free_tab(commande_set);
            return (error_value);
        }
    }
    free_tab(commande_set);
    return (0);
}

list_t *get_id_piece(list_t *piece)
{
    list_t *tmp = piece;
    int counter_id = 0;

    while (tmp != NULL) {
        tmp->id = counter_id;
        counter_id++;
        tmp = tmp->next;
    }
    return (piece);
}

int check_argv(option_t *option, list_t *piece, char **arg)
{
    int error_value = 0;

    for (int i = 0; arg[i]; i++) {
        if (arg[i][0] == '-' && arg[i][1] == '-')
            error_value = check_argv_complex(option, arg[i]);
        if (arg[i][0] == '-' && arg[i][1] != '-')
            error_value = check_argv_basic(option, arg[i], arg[i + 1]);
        if (error_value != 0)
            return (84);
    }
    if (option->debug_mode == 1)
        display_debug_mode(option, piece);
    piece = get_id_piece(piece);
    return (0);
}