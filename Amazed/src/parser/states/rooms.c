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

static am_rooms_type_t get_type_from_state(am_parser_t *parser)
{
    if (parser == NULL)
        return UNKNOWN_ROOM;
    if (parser->state == ST_UNKN)
        return UNKNOWN_ROOM;
    if (parser->state == ST_START)
        return START_ROOM;
    if (parser->state == ST_END)
        return END_ROOM;
    return NORMAL_ROOM;
}

static int make_room(am_parser_t *parser, char *data[4])
{
    am_rooms_t *room = NULL;

    if (parser == NULL || data == NULL)
        return FUNC_FAILED;
    room = am_room_create(get_type_from_state(parser), data[0]);
    if (room == NULL)
        return FUNC_FAILED;
    if (am_rooms_chain(&parser->rooms_start, &parser->rooms_end,
        room) == FUNC_FAILED) {
            am_rooms_free(room);
            return FUNC_FAILED;
        }
    room->position.x = my_getnbr(data[1]);
    room->position.y = my_getnbr(data[2]);
    return FUNC_SUCCESS;
}

int am_rooms_parse(am_parser_t *parser, char *line)
{
    char **tab = NULL;

    if (line == NULL)
        return FUNC_FAILED;
    tab = my_sepstr(line, " ");
    if (tab == NULL)
        return FUNC_FAILED;
    if (make_room(parser, tab) == FUNC_FAILED)
        return FUNC_FAILED;
    if (parser->state == ST_START)
        parser->state = ST_ROOMS;
    if (parser->state == ST_END)
        parser->state = ST_ROOMS;
    my_tabfree((void **) tab);
    return FUNC_SUCCESS;
}
