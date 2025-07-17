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

void am_rooms_free(am_rooms_t *chain)
{
    am_rooms_t *next_chain = NULL;

    if (chain == NULL)
        return;
    for (; chain != NULL; chain = next_chain) {
        next_chain = chain->next;
        my_tabfree((void **) chain->connections);
        free(chain->name);
        free(chain);
    }
    return;
}
