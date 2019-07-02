/*
** EPITECH PROJECT, 2019
** file that gets the highest score
** File description:
** tetris
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"

int my_convert_to_int(char *str, int option)
{
    int retenu = 1;
    int res = 0;
    int a = 0;

    if (str == NULL || str[0] == '-')
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    for (; str[a] >= 48 && str[a] <= 57; a++);
    a--;
    for (; a >= 0; a--) {
        res = res + ((str[a] - 48) * retenu);
        retenu = retenu * 10;
    }
    if (res <= 0 && option == 1)
        return (0);
    return (res);
}

void keep_highest_score(option_t *option)
{
    char *highest = NULL;
    int fd = open("highest_score.txt",  O_WRONLY | O_RDONLY);

    highest = int_to_array(option->highest_score);
    write(fd, highest, my_strlen(highest) + 1);
}

int get_highest_score_from_file(option_t *option, char *buffer)
{
    int fd = open("highest_score.txt", O_RDONLY);
    struct stat buff;
    int tab[2] = {0, 0};

    if (fd == -1) {
        option->highest_score = 0;
        return (0);
    }
    stat("highest_score.txt", &buff);
    tab[0] = buff.st_size;
    if (tab[0] == 0) {
        option->highest_score = 0;
        return (84);
    }
    buffer = malloc(sizeof(char) * (tab[0] + 1));
    tab[1] = read(fd, buffer, tab[0]);
    buffer[tab[1]] = '\0';
    option->highest_score = my_convert_to_int(buffer, 1);
    close(fd);
    return (0);
}