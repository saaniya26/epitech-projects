/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** links
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

bool_t am_links_id(char *line)
{
    int seps = 0;

    if (line == NULL)
        return FALSE;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '-') {
            seps++;
            continue;
        }
    if (seps != 1)
        return FALSE;
    return TRUE;
}
