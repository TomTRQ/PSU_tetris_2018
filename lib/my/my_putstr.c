/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** program that displays one by one the character of a string
*/
#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (1);
}
