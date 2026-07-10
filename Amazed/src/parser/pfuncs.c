/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** pfuncs
*/

#include <stdio.h>
#include "amazed.h"
#include "utils.h"

int am_parser_pfuncs(am_parser_state_t state, am_parser_t *parser,
    char *line)
{
    if (state == ST_UNKN || line == NULL)
        return FALSE;
    if (am_entries[state].parse_fnc != NULL)
        return am_entries[state].parse_fnc(parser, line);
    return FALSE;
}
