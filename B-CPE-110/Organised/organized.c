/*
** EPITECH PROJECT, 2024
** organized
** File description:
** organized
*/

#include "my.h"

int disp(void *data, char **args)
{
    identity_t *id = (identity_t *)data;
    hardware_t *temp = id->line;

    while (temp != NULL) {
        mini_printf("%s n°%d - \"%s\"\n", temp->type, temp->num, temp->name);
        temp = temp->next;
    }
    return 0;
}

int sort(void *data, char **args)
{
    return 0;
}
