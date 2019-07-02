/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** displays the argument of the function by using my_putchar
*/
#include "my.h"

int  my_put_nbr(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}

void my_put_nbr_bin(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb >= 2)
        my_put_nbr_bin(nb / 2);
    my_putchar(nb % 2 + '0');
}

void my_put_nbr_oct(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb >= 8)
        my_put_nbr_oct(nb / 8);
    my_putchar(nb % 8 + '0');
}

void my_put_nbr_hexa(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb >= 16)
        my_put_nbr_hexa(nb / 16);
    if ((nb % 16) >= 10)
        my_putchar((nb % 16) - 10 + 'a');
    else
        my_putchar(nb % 16 + '0');
}

void my_put_nbr_hexa_too(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -1 * nb;
    }
    if (nb >= 16)
        my_put_nbr_hexa_too(nb / 16);
    if ((nb % 16) >= 10)
        my_putchar((nb % 16) - 10 + 'A');
    else
        my_putchar(nb % 16 + '0');
}