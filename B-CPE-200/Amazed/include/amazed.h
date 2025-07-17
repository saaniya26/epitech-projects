/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** Amazed
*/

#include "utils.h"
#include "stdbool.h"

#ifndef AMAZED_H
    #define AMAZED_H

int am_main(void);

#endif

#ifndef AM_PARSER_H
    #define AM_PARSER_H

typedef enum {
    UNKNOWN_ROOM = -1,
    NORMAL_ROOM,
    START_ROOM,
    END_ROOM
} am_rooms_type_t;

typedef struct am_rooms_s {
    int room_id;
    am_rooms_type_t type;
    char *name;
    vector_2i_t position;
    char **connections;
    struct am_rooms_s *next;
} am_rooms_t;

typedef enum {
    ST_UNKN = -1,
    ST_PRE_START,
    ST_START,
    ST_ROOMS,
    ST_END,
    ST_LINKS
} am_parser_state_t;

typedef struct {
    int robot_line;
    int st_rooms_line;
    int rooms_line;
    int end_rooms_line;
    int tunnels_line;
} am_parser_lines_t;

typedef struct {
    am_parser_state_t state;
    int n_robots;
    char **links_char;
    am_rooms_t *rooms_start;
    am_rooms_t *rooms_end;
    am_parser_lines_t positions;
} am_parser_t;

typedef struct {
    am_parser_state_t state_type;
    bool_t (*id_fnc)(char *);
    int (*parse_fnc)(am_parser_t *, char *);
} am_entry_t;

    #define AM_PARSER_DEFAULT  ST_PRE_START, -1, NULL, NULL, NULL

extern const am_entry_t am_entries[];

char **am_reader(void);
int am_parse(am_parser_t *parser, char **lines);
void am_printer(am_parser_t *parser);

am_rooms_t *am_room_create(am_rooms_type_t type, char *name);
int am_rooms_chain(am_rooms_t **start, am_rooms_t **end, am_rooms_t *chain);
am_rooms_t *am_rooms_find(am_rooms_t *chain, const char *name);
am_rooms_t *am_rooms_find_start(am_rooms_t *chain);
am_rooms_t *am_rooms_find_end(am_rooms_t *chain);
void am_rooms_free(am_rooms_t *chain);

bool_t am_pre_start_id(char *line);
bool_t am_rooms_id(char *line);
bool_t am_links_id(char *line);

int am_pre_start_parse(am_parser_t *parser, char *line);
int am_rooms_parse(am_parser_t *parser, char *line);
int am_links_parse(am_parser_t *parser, char *line);

bool_t am_parser_id(am_parser_state_t state, char *line);
int am_parser_pfuncs(am_parser_state_t state, am_parser_t *parser,
    char *line);

#endif


#ifndef AM_MAZER_H
    #define AM_MAZER_H

typedef struct {
    int x;
    int y;
    int **matrix;
} am_matrix_t;

typedef struct {
    int *dist;
    int *prev;
    bool *visited;
} dijkstra_t;
typedef struct {
    am_matrix_t *adj_matrix;
    int num_rooms;
    dijkstra_t data;
} graph_t;

int init_dijkstra_arrays(int num_rooms, int start_room, dijkstra_t *dijkstra);
int find_min_distance_vertex(int *dist, bool *visited, int num_rooms);
void update_distances(graph_t *graph, int u);
am_rooms_t *get_room_by_index(am_rooms_t *room_list, int index);
int get_room_index(am_rooms_t *room_list, am_rooms_t *target);
int am_get_room_length(am_rooms_t *room_list);
int am_init_graph(graph_t *graph, am_matrix_t *matrix, int num_rooms);
am_matrix_t *am_matrix_create(int x, int y);
void am_matrix_free(am_matrix_t *matrix);
int am_get_start_room_index(am_rooms_t *room_list);
int am_dijikstra_calculate(graph_t *graph, int start_room);
void am_free_dijikstra_mem(dijkstra_t *dijikstra);

#endif
