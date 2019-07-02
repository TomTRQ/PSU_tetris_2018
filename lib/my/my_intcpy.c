/*
** EPITECH PROJECT, 2019
** file that displays the map
** File description:
** tetris
*/

int *my_intcpy(int *dest, int *src)
{
    int i = 0;

    while (src[i] != -2) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = -2;
    return (dest);
}