/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** alphab_order.c
*/

#include <stdlib.h>

char **make_order(char **list_of_name, int nb_file)
{
    char *str = NULL;

    for (int i = 0; i != nb_file - 1; i++) {
        if (list_of_name[i][0] > list_of_name[i + 1][0] &&
            list_of_name[i][0] != list_of_name[i + 1][0] + 32) {
            str = list_of_name[i];
            list_of_name[i] = list_of_name[i + 1];
            list_of_name[i + 1] = str;
            str = NULL;
        }
    }
    return (list_of_name);
}

char **make_alphab_order(char **list_of_name, int nb_file)
{
    for (int i = 0; i != nb_file; i++)
        list_of_name =  make_order(list_of_name, nb_file);
    return (list_of_name);
}