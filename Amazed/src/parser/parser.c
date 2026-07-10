/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** parser
*/

#include <stdlib.h>
#include "my.h"
#include "amazed.h"
#include "utils.h"

static bool_t identify_type(am_parser_t *parser, char *line)
{
    if (parser == NULL || line == NULL)
        return FALSE;
    if (am_parser_id(parser->state, line) == TRUE)
        return TRUE;
    if (parser->state == ST_ROOMS)
        if (am_parser_id(ST_LINKS, line) == TRUE) {
            parser->state = ST_LINKS;
            return TRUE;
        }
    return FALSE;
}

static int assign_room_pos(am_parser_t *parser, int i)
{
    if (parser == NULL || i < 0)
        return FUNC_FAILED;
    if ((parser->state == ST_START || parser->state == ST_END)
        && parser->positions.rooms_line == -1)
        parser->positions.rooms_line = i;
    if (parser->state == ST_START && parser->positions.st_rooms_line == -1)
        parser->positions.st_rooms_line = i + 1;
    if (parser->state == ST_END && parser->positions.end_rooms_line == -1)
        parser->positions.end_rooms_line = i + 1;
    if (parser->state == ST_ROOMS && parser->positions.rooms_line == -1)
        parser->positions.rooms_line = i;
    if (parser->state == ST_START || parser->state == ST_END ||
        parser->state == ST_ROOMS)
        return FUNC_SUCCESS;
    return FUNC_FAILED;
}

static int find_positions(am_parser_t *parser, int i)
{
    if (parser == NULL || i < 0)
        return FUNC_FAILED;
    if ((parser->state == ST_START || parser->state == ST_END ||
        parser->state == ST_ROOMS))
            return assign_room_pos(parser, i);
    if (parser->state == ST_PRE_START && parser->positions.robot_line == -1) {
            parser->positions.robot_line = i;
            return FUNC_SUCCESS;
        }
    if (parser->state == ST_LINKS && parser->positions.tunnels_line == -1) {
            parser->positions.tunnels_line = i;
            return FUNC_SUCCESS;
        }
    return FUNC_SEMFAIL;
}

static int parse_line(am_parser_t *parser, char **lines, int i)
{
    if (parser == NULL || lines == NULL || i < 0)
        return FUNC_FAILED;
    if (my_strcmp(lines[i], "##start") == CMP_EXACT) {
        parser->state = ST_START;
        if (parser->n_robots <= 0)
            return FUNC_FAILED;
        return find_positions(parser, i);
    }
    if (my_strcmp(lines[i], "##end") == CMP_EXACT) {
        parser->state = ST_END;
        if (parser->n_robots <= 0)
            return FUNC_FAILED;
        return find_positions(parser, i);
    }
    if (identify_type(parser, lines[i]) == FALSE)
        return FUNC_FAILED;
    find_positions(parser, i);
    if (am_parser_pfuncs(parser->state, parser, lines[i]) == FUNC_FAILED)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}

int am_parse(am_parser_t *parser, char **lines)
{
    if (lines == NULL || parser == NULL)
        return FUNC_FAILED;
    parser->links_char = lines;
    for (int i = 0; lines[i] != NULL; i++) {
        if (lines[i][0] == '#' && my_strncmp(lines[i], "##", 2) != CMP_EXACT)
            continue;
        if (parser->state == ST_START || parser->state == ST_END) {
            i++;
            parser->state = ST_ROOMS;
        }
        if (parse_line(parser, lines, i) == FUNC_FAILED)
            return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}
