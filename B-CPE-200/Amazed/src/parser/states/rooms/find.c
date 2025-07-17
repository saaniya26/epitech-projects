/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** chain
*/

#include <stdlib.h>
#include "amazed.h"
#include "my.h"
#include "utils.h"

am_rooms_t *am_rooms_find(am_rooms_t *chain, const char *name)
{
    if (chain == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next)
        if (my_strcmp(chain->name, name) == CMP_EXACT)
            return chain;
    return NULL;
}

am_rooms_t *am_rooms_find_start(am_rooms_t *chain)
{
    if (chain == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next)
        if (chain->type == START_ROOM)
            return chain;
    return NULL;
}

am_rooms_t *am_rooms_find_end(am_rooms_t *chain)
{
    if (chain == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next)
        if (chain->type == END_ROOM)
            return chain;
    return NULL;
}
