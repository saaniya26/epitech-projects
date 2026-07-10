/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** free
*/

#include <stdlib.h>
#include "amazed.h"
#include "utils.h"

void am_free_dijikstra_mem(dijkstra_t *dijikstra)
{
    if (dijikstra == NULL)
        return;
    free(dijikstra->dist);
    free(dijikstra->prev);
    free(dijikstra->visited);
}
