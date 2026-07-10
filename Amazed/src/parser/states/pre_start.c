/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** pre_start
*/

#include <stdio.h>
#include "amazed.h"
#include "my.h"
#include "utils.h"

int am_pre_start_parse(am_parser_t *parser, char *line)
{
    if (line == NULL)
        return FUNC_FAILED;
    parser->n_robots = my_getnbr(line);
    parser->state = ST_ROOMS;
    return FUNC_SUCCESS;
}
