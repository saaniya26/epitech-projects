/*
** EPITECH PROJECT, 2023
** EPITECH PROJECT TEK1
** File description:
** c library
*/

#include "include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == 0)
            break;
        i++;
    }
    return (s1[i] - s2[i]);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int cont = 0;

    while (cont < n) {
        dest[cont] = src[cont];
        if (src[cont] == '\0') {
            break;
        }
        cont = cont + 1;
    }
    return (dest);
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    char *new_string = malloc((my_strlen(src) + 1) * sizeof(char));

    if (!new_string)
        return NULL;
    return my_strcpy(new_string, src);
}

void *my_calloc(size_t num_elems, size_t elem)
{
    void *ptr = malloc(num_elems * elem);

    if (!ptr)
        return NULL;
    return memset(ptr, 0, num_elems * elem);
}
