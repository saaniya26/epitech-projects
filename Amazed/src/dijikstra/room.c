/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** room
*/

#include <stdio.h>
#include "amazed.h"

int get_room_index(am_rooms_t *room_list, am_rooms_t *target)
{
    int index = 0;
    am_rooms_t *current = room_list;

    while (current) {
        if (current == target)
            return index;
        index++;
    }
    return -1;
}

am_rooms_t *get_room_by_index(am_rooms_t *room_list, int index)
{
    int count = 0;
    am_rooms_t *current;

    current = room_list;
    while (current && count < index) {
        current = current->next;
        count++;
    }
    return current;
}

int am_get_start_room_index(am_rooms_t *room_list)
{
    int count = 0;

    if (room_list == NULL)
        return FUNC_FAILED;
    for (; room_list != NULL; room_list = room_list->next) {
        if (room_list->type == START_ROOM)
            return count;
        count++;
    }
    return FUNC_FAILED;
}

int am_get_room_length(am_rooms_t *room_list)
{
    int count = 0;
    am_rooms_t *current = NULL;

    if (room_list == NULL)
        return FUNC_FAILED;
    current = room_list;
    for (current = room_list; current != NULL; current = current->next)
        count++;
    return count;
}
