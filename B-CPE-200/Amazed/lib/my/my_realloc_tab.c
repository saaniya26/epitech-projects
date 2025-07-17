/*
** EPITECH PROJECT, 2025
** my_realloc_tab
** File description:
** libmy
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

void **my_realloc_tab(void **src, int tab_size, int new_size,
    size_t type_size)
{
    void **new_tab = NULL;

    if (src == NULL || tab_size <= 0 || new_size <= 0) {
        free(src);
        return NULL;
    }
    new_tab = malloc(type_size * new_size);
    if (new_tab == NULL) {
        free(src);
        return NULL;
    }
    for (int i = 0; i < new_size; i++) {
        if (i < tab_size)
            new_tab[i] = src[i];
        else
            new_tab[i] = NULL;
    }
    free(src);
    return new_tab;
}
