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

int am_rooms_chain(am_rooms_t **start, am_rooms_t **end, am_rooms_t *chain)
{
    if (start == NULL || end == NULL || chain == NULL)
        return FUNC_FAILED;
    if (*start == NULL && *end == NULL) {
        *start = chain;
        *end = chain;
        return FUNC_SUCCESS;
    }
    (*end)->next = chain;
    *end = chain;
    return FUNC_SUCCESS;
}
