/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** id
*/

#include <stdio.h>
#include "amazed.h"
#include "utils.h"

bool_t am_parser_id(am_parser_state_t state, char *line)
{
    if (state == ST_UNKN || line == NULL)
        return FALSE;
    if (am_entries[state].id_fnc != NULL)
        return am_entries[state].id_fnc(line);
    return FALSE;
}
