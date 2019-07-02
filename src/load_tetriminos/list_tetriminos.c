/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** list_tetriminos.c
*/

#include "tetris.h"

static char **copy_tetriminos(list_t *new, char **file)
{
    char **piece;

    piece = malloc(sizeof(char *) * (new->size[1] + 1));
    for (int i = 0; i != new->size[1]; i++) {
        piece[i] = malloc(sizeof(char) * new->size[0] + 1);
        for (int j = 0; j != new->size[0] + 1; j++)
            piece[i][j] = '\0';
        for (int j = 0; j != new->size[0]; j++)
            piece[i][j] = ' ';
    }
    if (!piece)
        return (NULL);
    piece[new->size[1]] = NULL;
    for (int i = 0; i < new->size[1]; i++) {
        for (int j = 0; file[i + 1][j]; j++) {
            if (file[i + 1][j] == '*')
                piece[i][j] = file[i + 1][j];
        }
    }
    return (piece);
}

static char **get_piece(list_t *new, char **file)
{
    if (check_error_piece(new, file) == 84) {
        new->error_value = 1;
        return (NULL);
    }
    return (copy_tetriminos(new, file));
}

static int fill_list(list_t *new, char **file)
{
    char **tmp = my_strsplit(file[0], ' ');

    new->size = malloc(sizeof(int) * 2);
    new->error_value = 0;
    if (check_tmp(tmp, new) == 84) {
        new->error_value = 1;
        return (1);
    }
    for (int i = 0; tmp[i]; i++) {
        if (check_number(tmp[i]) == 84) {
            new->error_value = 1;
            return (1);
        }
    }
    set_value(new, tmp);
    new->piece = get_piece(new, file);
    free_tab(tmp);
    if (!new->piece)
        return (1);
    return (0);
}

list_t *set_list(list_t *list, char *name)
{
    list_t *new = malloc(sizeof(list_t));
    char *adress = merge_str_with_c("tetriminos", name, '/');
    char **file;

    if (!new)
        return (NULL);
    file = read_file(adress);
    free(adress);
    if (!file || fill_list(new, file) == 84) {
        free(new);
        return (NULL);
    }
    new->name = my_strcopy(name);
    new->next = list;
    list = new;
    for (int i = 0; file[i]; i++)
        free(file[i]);
    free(file);
    return (list);
}

list_t *push_in_list(list_t *list, char *name)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *tmp = list;
    char *adress = merge_str_with_c("tetriminos", name, '/');
    char **file;

    if (!new)
        return (NULL);
    while (tmp->next != NULL)
        tmp = tmp->next;
    file = read_file(adress);
    free(adress);
    if (!file || fill_list(new, file) == 84) {
        free(new);
        return (NULL);
    }
    new->name = my_strcopy(name);
    new->next = tmp->next;
    tmp->next = new;
    free_tab(file);
    return (list);
}