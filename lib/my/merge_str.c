/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** merge_str.c
*/

#include <stdbool.h>
#include <stdlib.h>

static int my_strlen(char const *str)
{
    int  i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
            i++;
    }
    return (i);
}

char *merge_str(char *str_1, char *str_2)
{
    int size_str_f = my_strlen(str_1) + my_strlen(str_2);
    int counter = 0;
    char *str_f = malloc(sizeof(char) * size_str_f + 2);

    if (!str_f)
        return (NULL);
    for (int i = 0; i != size_str_f + 2; i++)
        str_f[i] = '\0';
    for (int i = 0; str_1[i]; i++) {
        str_f[counter] = str_1[i];
        counter++;
    }
    for (int i = 0; str_2[i]; i++) {
        str_f[counter] = str_2[i];
        counter++;
    }
    return (str_f);
}

char *merge_str_with_c(char *str_1, char *str_2, char stop)
{
    int size_str_f = my_strlen(str_1) + my_strlen(str_2);
    int counter = 0;
    char *str_f = malloc(sizeof(char) * size_str_f + 2);

    if (!str_f)
        return (NULL);
    for (int i = 0; i != size_str_f + 2; i++)
        str_f[i] = '\0';
    for (int i = 0; str_1[i]; i++) {
        str_f[counter] = str_1[i];
        counter++;
    }
    str_f[counter] = stop;
    counter++;
    for (int i = 0; str_2[i]; i++) {
        str_f[counter] = str_2[i];
        counter++;
    }
    return (str_f);
}