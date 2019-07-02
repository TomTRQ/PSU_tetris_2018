/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** program that counts and returns the number of characters
** found in the string passed as parameter.
*/
#include "my.h"

int my_strlen(char const *str)
{
    int  i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
            i++;
    }
    return (i);
}
