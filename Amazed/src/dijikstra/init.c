/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** init
*/

#include "amazed.h"
#include "unistd.h"
#include "limits.h"
#include "stdbool.h"
#include <stdlib.h>

int am_init_graph(graph_t *graph, am_matrix_t *matrix, int num_rooms)
{
    if (matrix == NULL)
        return FUNC_FAILED;
    graph->adj_matrix = matrix;
    graph->num_rooms = num_rooms;
    graph->data.dist = NULL;
    graph->data.prev = NULL;
    graph->data.visited = NULL;
    return FUNC_SUCCESS;
}

int alloc_djikstra_mem(int num_rooms, dijkstra_t *djikstra)
{
    djikstra->dist = malloc(sizeof(int) * num_rooms);
    djikstra->prev = malloc(sizeof(int) * num_rooms);
    djikstra->visited = malloc(sizeof(int) * num_rooms);
    if (djikstra->dist == NULL) {
        return FUNC_FAILED;
    }
    if (djikstra->prev == NULL) {
        free(djikstra->dist);
        return FUNC_FAILED;
    }
    if (djikstra->visited == NULL) {
        free(djikstra->dist);
        free(djikstra->prev);
        return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}

static int init_dijkstra_values(int num_rooms,
    int start_room, dijkstra_t *dijkstra)
{
    for (int i = 0; i < num_rooms; i++) {
        if (i == start_room) {
            dijkstra->dist[i] = 0;
        } else {
            dijkstra->dist[i] = INT_MAX;
        }
        dijkstra->prev[i] = -1;
        dijkstra->visited[i] = false;
    }
    return FUNC_SUCCESS;
}

int init_dijkstra_arrays(int num_rooms, int start_room, dijkstra_t *dijkstra)
{
    if (alloc_djikstra_mem(num_rooms, dijkstra) == FUNC_FAILED)
        return FUNC_FAILED;
    init_dijkstra_values(num_rooms, start_room, dijkstra);
    return FUNC_SUCCESS;
}

int find_min_distance_vertex(int *dist, bool *visited, int num_rooms)
{
    int min_dist = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < num_rooms; v++) {
        if (visited[v] == FALSE && dist[v] < min_dist) {
            min_dist = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

static void style_dist(int new_dist, graph_t *graph, int u, int v)
{
    if (new_dist < graph->data.dist[v]) {
        graph->data.dist[v] = new_dist;
        graph->data.prev[v] = u;
    }
}

void update_distances(graph_t *graph, int u)
{
    int new_dist = 0;

    for (int v = 0; v < graph->num_rooms; v++) {
        if (graph->data.visited[v] == FALSE &&
            graph->adj_matrix->matrix[u][v] > 0 &&
            graph->data.dist[u] != INT_MAX) {
            new_dist = graph->data.dist[u] + graph->adj_matrix->matrix[u][v];
            style_dist(new_dist, graph, u, v);
        }
    }
}
