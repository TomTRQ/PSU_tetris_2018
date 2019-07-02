/*
** EPITECH PROJECT, 2019
** int
** File description:
** to array
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *int_to_array(int nb)
{
    int i = 1;
    int buff = nb;
    char *new = NULL;

    for (; buff >= 10; i++) {
        buff = buff / 10;
    }
    new = malloc(sizeof(char) * (i + 1));
    new[i] = '\0';
    if (new == NULL)
        return (NULL);
    for (; nb >= 10; ) {
        i = i - 1;
        new[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    i = i - 1;
    new[i] = nb + '0';
    return (new);
}