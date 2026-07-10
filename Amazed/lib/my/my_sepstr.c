/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** libmy
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

static bool_t is_a_separator(const char chr, const char *sep)
{
    if (chr == '\0' || sep == NULL)
        return FALSE;
    for (int i = 0; sep[i] != '\0'; i++)
        if (chr == sep[i])
            return TRUE;
    return FALSE;
}

static int count_separations(const char *str, const char *sep)
{
    int n_seps = 0;

    if (str == NULL || sep == NULL)
        return FUNC_FAILED;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_a_separator(str[i], sep) == TRUE
            && str[i + 1] != '\0')
            n_seps++;
    return n_seps;
}

static int process_wordarr(char **dest, char const *str, const char *sep)
{
    int index = 0;
    int i = 0;
    char *last_point = (char *) str;

    if (dest == NULL || str == NULL || sep == NULL)
        return FUNC_FAILED;
    for (; str[i] != '\0'; i++) {
        if (is_a_separator(str[i], sep) == TRUE) {
            dest[index] = my_strptrdup(last_point, &str[i]);
            index++;
            last_point = (char *) &str[i + 1];
        }
    }
    if (last_point != NULL)
        if (*last_point != '\0')
            dest[index] = my_strptrdup(last_point, &str[i]);
    return FUNC_SUCCESS;
}

static char **get_unitab(char const *str)
{
    char **tab = NULL;

    if (str == NULL)
        return NULL;
    tab = malloc(sizeof(tab) * 2);
    tab[1] = NULL;
    tab[0] = my_strdup(str);
    return tab;
}

char **my_sepstr(char const *str, const char *sep)
{
    int len = 0;
    char **dest = NULL;

    if (str == NULL || sep == NULL)
        return NULL;
    len = count_separations(str, sep);
    if (len <= 0) {
        if (len < 0)
            return NULL;
        return get_unitab(str);
    }
    dest = malloc(sizeof(char *) * (len + 2));
    if (dest == NULL)
        return NULL;
    dest[len + 1] = NULL;
    if (process_wordarr(dest, str, sep) == FUNC_FAILED)
        return NULL;
    return dest;
}
