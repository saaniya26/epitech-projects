/*
** EPITECH PROJECT, 2024
** Documents
** File description:
** parcourrir
*/

#include "settingup.h"

int print_map(square_t *square)
{
    int i;
    int j;

    for (i = 0; i < square->row; i++) {
        for (j = 0; j < square->col; j++) {
            my_putchar(square->map[i][j]);
        }
        my_putchar('\n');
    }
}

int change(square_t *square)
{
    int i;
    int j;

    for (i = 0; i < square->max; i++) {
        for (j = 0; j < square->max; j++) {
            square->map[square->max_i + i][square->max_j + j] = 'x';
        }
    }
}

int find_smallest(int a, int b, int c)
{
    if (a < b) {
        if (a < c)
            return a;
        else
            return c;
    } else if (b < c)
        return b;
    else
        return c;
}

void find_square(int i, int j, square_t *square, int **matrice)
{
    int smallest = 0;

    if (square->map[i][j] == 'o') {
        matrice[i][j] = 0;
    } else if (i == 0 || j == 0) {
        matrice[i][j] = 1;
    } else {
        matrice[i][j] = find_smallest(matrice[i - 1][j - 1], matrice[i - 1][j],
        matrice[i][j - 1]) + 1;
    }
    if (matrice[i][j] > square->max) {
        square->max = matrice[i][j];
        square->max_i = i - square->max + 1;
        square->max_j = j - square->max + 1;
    }
}

int check(square_t *square)
{
    int i;
    int j;
    int **matrice = malloc(sizeof(int *) * (square->row));

    for (i = 0; i < square->row; i++) {
        matrice[i] = malloc(sizeof(int) * square->col);
        for (j = 0; j < square->col; j++) {
            find_square(i, j, square, matrice);
        }
    }
    change(square);
    print_map(square);
    free(matrice);
}
