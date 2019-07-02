/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my_strsplit.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char **get_size(char *str, char stop)
{
    int counter = 0;
    char **new_str = NULL;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != stop)
            counter++;
    new_str = malloc(sizeof(char *) * (counter + 1));
    for (int i = 0; i != counter + 1; i++)
        new_str[i] = NULL;
    return (new_str);
}

char **get_words(char *str, char stop)
{
    char **tab = get_size(str, stop);
    int pos = 1;
    int tab_pos = 0;
    int pos_written = 0;

    for (int i = 1; str[i - 1]; i++)
        if (str[i] && str[i] != stop)
            pos++;
        else {
            tab[tab_pos] = malloc(sizeof(char) * (pos + 1));
            tab[tab_pos][pos] = '\0';
            for (int j = 0; j < pos; j++)
                tab[tab_pos][j] = str[pos_written++];
            while (str[i + 1] == stop)
                i++;
            pos_written = i + 1;
            tab_pos++;
            pos = 0;
        }
    return tab;
}

char **my_strsplit(char *str, char stop)
{
    char **str_f;

    if (my_strlen(str) == 0)
        return (NULL);
    str_f = get_words(str, stop);
    return (str_f);
}

char **malloc_my_split(char *str, char stop)
{
    int counter = 0;
    char **str_f = malloc(sizeof(char *) * 3);

    if (!str_f)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if (str[i] == stop)
            break;
        counter++;
    }
    str_f[0] = malloc(sizeof(char) * counter + 1);
    str_f[1] = malloc(sizeof(char) * my_strlen(str) - counter);
    str_f[2] = NULL;
    if (!str_f[0] || !str_f[1])
        return (NULL);
    for (int i = 0; i != counter + 1; i++)
        str_f[0][i] = '\0';
    for (int i = 0; i != my_strlen(str) - counter; i++)
        str_f[1][i] = '\0';
    return (str_f);
}

char **my_str_one_split(char *str, char stop)
{
    char **str_f;
    int counter = 0;
    int j = 0;

    if (my_strlen(str) == 0)
        return (NULL);
    str_f = malloc_my_split(str, stop);
    if (!str_f)
        return (NULL);
    for (int i = 0; str[i]; i++, j++) {
        if (str[i] == stop && counter == 0) {
            i++;
            counter++;
            j = 0;
        }
        str_f[counter][j] = str[i];
    }
    return (str_f);
}