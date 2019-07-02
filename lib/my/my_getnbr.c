/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** returns a number sent as a string
*/

int answer_return(int a, int count_minus)
{
    if (count_minus % 2 == 1)
        a = -1 * a;
    return (a);
}

int my_getnbr(char const *str)
{
    int a = 0;
    int count_minus = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            a = a * 10 + (str[i] - 48);
        } else {
            break;
        }
        if (str[i+1] < '0' || str[i+1] > '9')
            break;
    if (str[i] == '-')
            count_minus++;
    }
    a = answer_return(a, count_minus);
    return (a);
}
