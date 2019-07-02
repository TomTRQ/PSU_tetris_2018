/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header file for library
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef MY_H_
#define MY_H_

char *int_to_array(int nb);
int *my_intcpy(int *dest, int *src);
int my_strlen(char const *str);
void my_putchar(char c);
int my_put_nbr(long int nb);
int my_check_nbr(char *str);
void my_put_nbr_hexa(long int nb);
void my_put_nbr_hexa_too(long int nb);
void my_put_nbr_bin(long int nb);
void my_put_nbr_oct(long int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcopy(char *str);
char **my_strsplit(char *str, char stop);
char **my_str_one_split(char *str, char stop);
char *merge_str(char *str_1, char *str_2);
char *merge_str_with_c(char *str_1, char *str_2, char stop);
char **make_alphab_order(char **list_of_name, int nb_file);
void free_tab(char **str);

#endif
