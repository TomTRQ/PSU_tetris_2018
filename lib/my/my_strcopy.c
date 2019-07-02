/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** my_strcopy.c
*/

#include <stdlib.h>

char *my_strcopy(char *str)
{
    char *str_f;
    int counter = 0;

    for (int i = 0; str[i]; i++)
        counter++;
    str_f = malloc(sizeof(char) * counter + 2);
    if (str_f == NULL)
        return (NULL);
    for (int i = 0; i != counter + 2; i++)
        str_f[i] = '\0';
    for (int i = 0; str[i]; i++) {
        str_f[i] = str[i];
        str_f[i + 1] = '\0';
    }
    return (str_f);
}