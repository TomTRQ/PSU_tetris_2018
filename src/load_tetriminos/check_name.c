/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** chech_name.c
*/

#include "tetris.h"

static int cmp_name(char **tmp_split)
{
    int counter = 0;
    int result_value = 1;

    for (int i = 0; tmp_split[i]; i++)
        counter++;
    if (my_strcmp(tmp_split[counter - 1], "tetrimino") == 0)
        result_value = 0;
    free_tab(tmp_split);
    return (result_value);
}

int check_name(struct dirent *lecture)
{
    int counter = 0;
    char *tmp_str;
    char **tmp_split;

    for (int i = 0; lecture->d_name[i] != '\0'; i++)
        counter++;
    tmp_str = malloc(sizeof(char) * counter + 2);
    for (int i = 0; i != counter + 2; i++)
        tmp_str[i] = '\0';
    for (int i = 0; lecture->d_name[i] != '\0'; i++) {
        tmp_str[i] = lecture->d_name[i];
    }
    tmp_split = my_strsplit(tmp_str, '.');
    free(tmp_str);
    return (cmp_name(tmp_split));
}