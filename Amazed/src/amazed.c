/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** amazed
*/

#include <stdio.h>
#include "my.h"
#include "amazed.h"
#include "utils.h"

static bool_t print_error_false(const char *msg)
{
    if (msg == NULL)
        return FALSE;
    my_putstr_fd(msg, STDERR);
    return FALSE;
}

static bool_t check_parse_status(am_parser_t *parser)
{
    if (parser == NULL)
        return print_error_false("No parser detected.\n");
    if (parser->n_robots <= 0)
        return print_error_false("How about you add some robots?\n");
    if (parser->links_char == NULL)
        return print_error_false("There is no valid path from start to"
            "exit.\n");
    if (parser->rooms_start == NULL)
        return print_error_false("There is no starting room.\n");
    if (parser->rooms_end == NULL)
        return print_error_false("There is no ending room.\n");
    if (parser->state == ST_UNKN)
        return print_error_false("Status unknown.\n");
    return TRUE;
}

static int free_dijikstra(am_matrix_t *matrix, graph_t *graph)
{
    if (matrix == NULL || graph == NULL)
        return FUNC_FAILED;
    am_matrix_free(matrix);
    am_free_dijikstra_mem(&graph->data);
    return FUNC_FAILED;
}

static int do_dijikstra(am_parser_t *parser)
{
    graph_t graph;
    int num_rooms = 0;
    am_matrix_t *matrix = NULL;

    if (parser == NULL)
        return FUNC_FAILED;
    num_rooms = am_get_room_length(parser->rooms_start);
    matrix = am_matrix_create(num_rooms, num_rooms);
    if (am_init_graph(&graph, matrix, num_rooms))
        return free_dijikstra(matrix, &graph);
    if (am_dijikstra_calculate(&graph, am_get_start_room_index(
        parser->rooms_start))
        == FUNC_FAILED)
        return free_dijikstra(matrix, &graph);
    free_dijikstra(matrix, &graph);
    return FUNC_SUCCESS;
}

int am_main(void)
{
    am_parser_t parser = {ST_PRE_START, -1, NULL, NULL, NULL,
        (am_parser_lines_t) {-1, -1, -1, -1, -1}};
    char **data = am_reader();

    if (data == NULL)
        return FUNC_FAILED;
    if (am_parse(&parser, data) == FUNC_FAILED
        && check_parse_status(&parser) == FALSE) {
        am_rooms_free(parser.rooms_start);
        my_tabfree((void **) data);
        return FUNC_FAILED;
    }
    am_printer(&parser);
    do_dijikstra(&parser);
    am_rooms_free(parser.rooms_start);
    my_tabfree((void **) data);
    return FUNC_SUCCESS;
}
