/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** create
*/

#include <stdlib.h>
#include "amazed.h"
#include "utils.h"
#include "my.h"

static int **create_int_matrix(int x, int y)
{
    int **matrix = NULL;

    if (x <= 0 || y <= 0)
        return NULL;
    matrix = malloc(sizeof(int *) * (y + 1));
    if (matrix == NULL)
        return NULL;
    matrix[y] = NULL;
    for (int i = 0; i < y; i++) {
        matrix[i] = malloc(sizeof(int) * (x + 1));
        if (matrix[i] == NULL)
            return my_vfree_null(1, matrix);
        matrix[i][x] = -1;
        for (int j = 0; j < x; j++)
            matrix[i][j] = 0;
    }
    return matrix;
}

am_matrix_t *am_matrix_create(int x, int y)
{
    am_matrix_t *new_matrix = NULL;

    if (x <= 0 || y <= 0)
        return NULL;
    new_matrix = malloc(sizeof(am_matrix_t));
    if (new_matrix == NULL)
        return NULL;
    new_matrix->x = x;
    new_matrix->y = y;
    new_matrix->matrix = create_int_matrix(x, y);
    return new_matrix;
}
