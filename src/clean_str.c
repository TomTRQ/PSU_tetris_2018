/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** clean_str.c
*/

#include "tetris.h"

char *clean_special_c(char *str)
{
    int counter = 0;
    char *new_str = NULL;
    int counter_char = 0;

    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++)
        if (str[i] == '\t' || str[i] == '\n')
            counter++;
    new_str = malloc(sizeof(char) * (my_strlen(str) - counter + 2));
    for (int i = 0; i != my_strlen(str) - counter + 2; i++)
        new_str[i] = '\0';
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\t' || str[i] == '\n')
            continue;
        new_str[counter_char] = str[i];
        counter_char++;
    }
    free(str);
    return (new_str);
}

char *clean_space_start(char *str)
{
    int nb_space = 0;
    char *new_str = NULL;
    int counter;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            nb_space++;
            continue;
        }
        break;
    }
    new_str = malloc(sizeof(char) * (my_strlen(str) - nb_space + 2));
    for (int i = 0; i != (my_strlen(str) - nb_space + 2); i++)
        new_str[i] = '\0';
    counter = nb_space;
    for (int i = 0; i != my_strlen(str) - counter; i++, nb_space++) {
        new_str[i] = str[nb_space];
    }
    free(str);
    return (new_str);
}

char *clean_space_end(char *str)
{
    int nb_char = 0;
    char *new_str = NULL;
    int counter = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ')
            nb_char++;
    }
    new_str = malloc(sizeof(char) * (my_strlen(str) + 2));
    for (int i = 0; i != (my_strlen(str) + 2); i++)
        new_str[i] = '\0';
    for (int i = 0; str[i]; i++) {
        if (counter >= nb_char)
            break;
        if (str[i] != ' ')
            counter++;
        new_str[i] = str[i];
    }
    free(str);
    return (new_str);
}

char *clean_str(char *str)
{
    str = clean_special_c(str);
    str = clean_space_start(str);
    str = clean_space_end(str);
    return (str);
}