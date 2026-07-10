/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** printer
*/

#include <stdio.h>
#include "my.h"
#include "amazed.h"
#include "utils.h"

static void putstr_no_comments(const char *str)
{
    int i = 0;

    if (str == NULL)
        return;
    for (; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], " #", 2) == CMP_EXACT)
            return;
        if (str[i] == '#' || str[i] == '\n')
            break;
        my_putchar(str[i]);
    }
    if (i > 0)
        my_putchar('\n');
}

void am_printer(am_parser_t *parser)
{
    if (parser == NULL)
        return;
    for (int i = 0; parser->links_char[i] != NULL; i++) {
        if (parser->links_char[i][0] == '#'
            && my_strncmp(parser->links_char[i], "##", 2) != CMP_EXACT)
            continue;
        if (i == parser->positions.robot_line)
            my_putstr("#number_of_robots\n");
        if (i == parser->positions.rooms_line)
            my_putstr("#rooms\n");
        if (i == parser->positions.st_rooms_line)
            my_putstr("##start\n");
        if (i == parser->positions.end_rooms_line)
            my_putstr("##end\n");
        if (i == parser->positions.tunnels_line)
            my_putstr("#tunnels\n");
        putstr_no_comments(parser->links_char[i]);
    }
    my_putstr("#moves\n");
}
