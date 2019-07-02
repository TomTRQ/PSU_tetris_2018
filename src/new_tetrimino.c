/*
** EPITECH PROJECT, 2019
** file that changes the tetrimino
** File description:
** tetris
*/

#include "tetris.h"

void lower_tetrimino(option_t *option, list_t *pieces, int *modif)
{
    int first_x = get_start_position(option, pieces);
    int a = 0;
    int b = 0;

    remove_previous_positions(option, pieces, modif);
    while (pieces->piece[a] != NULL) {
        while (pieces->piece[a][b] != '\0') {
            if (pieces->piece[a][b] == '*') {
                option->colors[a + modif[0]][b + first_x + modif[1]] = \
                pieces->color;
            }
            b = b + 1;
        }
        b = 0;
        a = a + 1;
    }
}

int collision_tetrimino(option_t *option, int *modif, list_t *pieces)
{
    int first_x = get_start_position(option, pieces);
    int i = 0;

    while (i < pieces->size[0]) {
        if (option->colors[modif[0] + pieces->size[1]] != NULL && \
        option->colors[modif[0] + pieces->size[1]]\
        [i + modif[1] + first_x] >= 0) {
            lower_tetrimino(option, pieces, modif);
            return (1);
        }
        i = i + 1;
    }
    return (0);
}

int change_to_new_tetrimino(option_t *option, list_t *root, \
int *modif, list_t *pieces)
{
    if (modif[0] > option->size_map[1] - pieces->size[1] || \
    collision_tetrimino(option, modif, pieces) == 1) {
        option->falling = option->to_fall;
        option->to_fall = get_new_random_tetrimino(root, option);
        if (option->to_fall == NULL)
            option->to_fall = root;
        modif[0] = 0;
        modif[1] = 0;
        return (1);
    }
    return (0);
}

int remove_full_line(int i, int **colors, option_t *option)
{
    int line = i;

    while (line != 0) {
        if (colors[line] != NULL && colors[line - 1] != NULL) {
            colors[line] = my_intcpy(colors[line], \
            colors[line - 1]);
            line = line - 1;
        }
    }
    for (int a = 0; colors[0][a] != -2; a++)
        colors[0][a] = -1;
    option->score += 100;
    option->lines += 1;
    if (option->lines % 10 == 0)
        option->level += 1;
    if (option->score >= option->highest_score)
        option->highest_score = option->score;
    return (1);
}

int check_if_full_line(int **colors, option_t *option)
{
    int i = 0;
    int j = 0;

    while (colors[i] != NULL) {
        while (colors[i][j] >= 0)
            j = j + 1;
        if (colors[i][j] == -2)
            return (remove_full_line(i, colors, option));
        j = 0;
        i = i + 1;
    }
    return (0);
}