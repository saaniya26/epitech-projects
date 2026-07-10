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

void am_matrix_free(am_matrix_t *matrix)
{
    if (matrix == NULL)
        return;
    if (matrix->matrix == NULL) {
        free(matrix);
        return;
    }
    for (int i = 0; matrix->matrix[i]; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}
