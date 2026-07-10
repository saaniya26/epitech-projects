/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** rooms
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

static bool_t check_length(char **tab)
{
    int len = 0;

    if (tab == NULL)
        return FALSE;
    len = my_tablen((const void **) tab);
    if (len > 3) {
        if (tab[3][0] == '#')
            return TRUE;
        return FALSE;
    }
    if (len == 3)
        return TRUE;
    return FALSE;
}

bool_t am_rooms_id(char *line)
{
    char **tab = NULL;

    if (line == NULL)
        return FALSE;
    tab = my_sepstr(line, " ");
    if (tab == NULL)
        return FALSE;
    if (check_length(tab) == FALSE) {
        my_tabfree((void **) tab);
        return FALSE;
    }
    for (int i = 1; i < 3 && tab[i] != NULL; i++)
        if (my_str_isnum(tab[i]) != TRUE)
            return FALSE;
    my_tabfree((void **) tab);
    return TRUE;
}
