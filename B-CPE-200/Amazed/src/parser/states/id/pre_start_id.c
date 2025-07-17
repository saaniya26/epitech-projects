/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** pre_start
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

bool_t am_pre_start_id(char *line)
{
    if (line == NULL)
        return FALSE;
    if (my_str_isnum(line) != TRUE)
        return FALSE;
    return TRUE;
}
