/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** read_in_file.c
*/

#include "tetris.h"

int get_nb_piece(option_t *option)
{
    DIR *rep;
    struct dirent *lecture = malloc(sizeof(lecture));

    rep = opendir("tetriminos");
    if (rep == NULL) {
        free(lecture);
        my_putstr("error: tetriminos not found");
        return (84);
    }
    while ((lecture = readdir(rep))) {
        if (lecture->d_name[0] != '.' && check_name(lecture) == 0)
            option->nb_piece++;
    }
    free(lecture);
    closedir(rep);
    if (option->nb_piece == 0) {
        my_putstr("error: tetriminos not found");
        return (84);
    }
    return (0);
}

static char *get_size_name(struct dirent *lecture)
{
    int counter = 0;
    char *tmp_str;

    for (int i = 0; lecture->d_name[i] != '\0'; i++) {
        counter++;
    }
    tmp_str = malloc(sizeof(char) * counter + 1);
    for (int i = 0; i != counter + 1; i++)
        tmp_str[i] = '\0';
    return (tmp_str);
}

static char *get_name(struct dirent *lecture, char *name)
{
    for (int i = 0; lecture->d_name[i] != '\0'; i++) {
        name[i] = lecture->d_name[i];
    }
    return (name);
}

static char **malloc_name(struct dirent *lecture, DIR *rep, char **file)
{
    int counter = 0;

    while ((lecture = readdir(rep))) {
        if (lecture->d_name[0] != '.' && check_name(lecture) == 0) {
            file[counter] = get_size_name(lecture);
            file[counter] = get_name(lecture, file[counter]);
            counter++;
        }
    }
    return (file);
}

char **get_name_file(option_t *option)
{
    char **name_file;
    struct dirent *lecture = malloc(sizeof(*lecture));
    DIR *rep;

    name_file = malloc(sizeof(char *) * option->nb_piece + 2);
    if (!name_file)
        return (NULL);
    for (int i = 0; i != option->nb_piece; i++)
        name_file[i] = NULL;
    rep = opendir("tetriminos");
    if (rep == NULL) {
        my_putstr("error: tetriminos not found");
        return (NULL);
    }
    name_file = malloc_name(lecture, rep, name_file);
    free(lecture);
    closedir(rep);
    return (name_file);
}