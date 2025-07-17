/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** states
*/

#include <stdio.h>
#include "amazed.h"

const am_entry_t am_entries[] = {
    {ST_PRE_START, am_pre_start_id, am_pre_start_parse},
    {ST_START, am_rooms_id, am_rooms_parse},
    {ST_ROOMS, am_rooms_id, am_rooms_parse},
    {ST_END, am_rooms_id, am_rooms_parse},
    {ST_LINKS, am_links_id, am_links_parse},
    {ST_UNKN, NULL, NULL},
};
