/*
** EPITECH PROJECT, 2025
** my_vfree
** File description:
** libmy
*/

#include <stdarg.h>
#include <stdlib.h>

void my_vfree(int n_free, ...)
{
    va_list args;
    void *value = NULL;

    if (n_free <= 0)
        return;
    va_start(args, n_free);
    for (int i = 0; i < n_free; i++) {
        value = va_arg(args, void *);
        free(value);
    }
    va_end(args);
}

void *my_vfree_null(int n_free, ...)
{
    va_list args;
    void *value = NULL;

    if (n_free <= 0)
        return NULL;
    va_start(args, n_free);
    for (int i = 0; i < n_free; i++) {
        value = va_arg(args, void *);
        free(value);
    }
    va_end(args);
    return NULL;
}
