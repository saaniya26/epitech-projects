/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** create
*/

#include <stdlib.h>
#include "amazed.h"
#include "my.h"
#include "utils.h"

am_rooms_t *am_room_create(am_rooms_type_t type, char *name)
{
    am_rooms_t *new_room = NULL;

    new_room = malloc(sizeof(am_rooms_t));
    if (new_room == NULL)
        return NULL;
    new_room->name = my_strdup(name);
    new_room->type = type;
    new_room->room_id = -1;
    new_room->connections = malloc(sizeof(char *) * 1);
    if (new_room->connections == NULL) {
        free(new_room->name);
        free(new_room);
        return NULL;
    }
    new_room->connections[0] = NULL;
    new_room->next = NULL;
    return new_room;
}
