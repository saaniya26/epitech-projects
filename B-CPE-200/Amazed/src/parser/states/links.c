/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** links
*/

#include <stdio.h>
#include "amazed.h"
#include "my.h"
#include "utils.h"

static int establish_link(am_parser_t *parser, char *data[3])
{
    am_rooms_t *origin = NULL;
    int origin_len = 0;
    am_rooms_t *target = NULL;

    if (parser == NULL || data == NULL)
        return FUNC_FAILED;
    origin = am_rooms_find(parser->rooms_start, data[0]);
    target = am_rooms_find(parser->rooms_start, data[1]);
    if (origin == NULL || target == NULL)
        return FUNC_FAILED;
    origin_len = my_tablen((const void **) origin->connections);
    origin->connections = (char **) my_realloc_tab((void **)
        origin->connections, origin_len + 1, origin_len + 2, sizeof(char *));
    if (origin->connections == NULL)
        return FUNC_FAILED;
    origin->connections[origin_len] = my_strdup(target->name);
    return FUNC_SUCCESS;
}

int am_links_parse(am_parser_t *parser, char *line)
{
    char **tab = NULL;

    if (parser == NULL || line == NULL)
        return FUNC_FAILED;
    tab = my_sepstr(line, "-");
    if (tab == NULL)
        return FUNC_FAILED;
    if (establish_link(parser, tab) == FUNC_FAILED) {
        my_tabfree((void **) tab);
        return FUNC_FAILED;
    }
    my_tabfree((void **) tab);
    return FUNC_SUCCESS;
}
