/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** dijikstra
*/

#include <stdio.h>
#include "amazed.h"
#include "utils.h"
#include "limits.h"

bool path_exists(graph_t *graph, int dest_index)
{
    return (graph->data.dist[dest_index] != INT_MAX);
}

int calculate_path(graph_t *graph, int src_index, int dest_index)
{
    int path_len;
    int curr;

    if (src_index == dest_index) {
        return 1;
    }
    if (path_exists(graph, dest_index) == FALSE)
        return 0;
    path_len = 0;
    curr = dest_index;
    while (curr != -1) {
        path_len++;
        if (curr == src_index)
            break;
        curr = graph->data.prev[curr];
    }
    if (curr == -1)
        return 0;
    return path_len;
}

int build_path(graph_t *graph, int src_index, int dest_index, int *path)
{
    int path_len = calculate_path(graph, src_index, dest_index);
    int curr;
    int index;

    if (path_len <= 0)
        return 0;
    if (path_len == 1) {
        path[0] = src_index;
        return 1;
    }
    index = path_len - 1;
    curr = dest_index;
    while (index >= 0) {
        path[index] = curr;
        index--;
        if (curr == src_index)
            break;
        curr = graph->data.prev[curr];
    }
    return path_len;
}

am_rooms_t *get_next_room(graph_t *graph, am_rooms_t *room_list,
    am_rooms_t *current, am_rooms_t *dest)
{
    int current_index = get_room_index(room_list, current);
    int dest_index = get_room_index(room_list, dest);
    int *path = NULL;
    int path_len = 0;
    am_rooms_t *next_room = NULL;

    if (current_index == -1 || dest_index == -1)
        return NULL;
    if (current_index == dest_index)
        return dest;
    if (path_exists(graph, dest_index) == false)
        return NULL;
    path = malloc(sizeof(int) * graph->num_rooms);
    if (path == NULL)
            return NULL;
    path_len = build_path(graph, current_index, dest_index, path);
    if (path_len < 2)
        return NULL;
    return get_room_by_index(room_list, path[1]);
}

int am_dijikstra_calculate(graph_t *graph, int start_room)
{
    int u = 0;

    if (graph->adj_matrix == NULL)
        return FUNC_FAILED;
    if (init_dijkstra_arrays(graph->num_rooms, start_room,
        &graph->data) == FUNC_FAILED)
        return FUNC_FAILED;
    for (int i = 0; i < graph->num_rooms - 1; i++) {
        u = find_min_distance_vertex(graph->data.dist, graph->data.visited,
            graph->num_rooms);
        if (u == -1)
            break;
        graph->data.visited[u] = true;
        update_distances(graph, u);
    }
    return FUNC_SUCCESS;
}
