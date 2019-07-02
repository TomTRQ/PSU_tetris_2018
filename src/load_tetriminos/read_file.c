/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** read_file.c
*/

#include "tetris.h"

static int size_file(char *name)
{
    FILE *fd;
    char *line = NULL;
    size_t len;
    int counter = 0;

    fd = fopen(name, "r");
    if (!fd)
        return (84);
    for (int i = 0; getline(&line, &len, fd) != -1; i++) {
        counter++;
    }
    free(line);
    fclose(fd);
    return (counter);
}

char **clear_file(char *line, FILE *fd, char **file)
{
    free(line);
    fclose(fd);
    if (!file[0])
        return (file);
    file[0] = clean_str(file[0]);
    return (file);
}

char **read_file(char *name)
{
    FILE *fd;
    char *line = NULL;
    size_t len;
    char **tmp = malloc(sizeof(char *) * (size_file(name) + 1));

    fd = fopen(name, "r");
    if (!fd)
        return (NULL);
    for (int i = 0; getline(&line, &len, fd) != -1; i++) {
        tmp[i] = my_strcopy(line);
        if (tmp[i][my_strlen(tmp[i]) - 1] == '\n')
            tmp[i][my_strlen(tmp[i]) - 1] = '\0';
    }
    tmp = clear_file(line, fd, tmp);
    tmp[size_file(name)] = NULL;
    if (!tmp[0]) {
        free_tab(tmp);
        return (NULL);
    }
    return (tmp);
}