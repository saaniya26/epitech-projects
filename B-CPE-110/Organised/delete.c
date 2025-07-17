/*
** EPITECH PROJECT, 2024
** organized
** File description:
** delete
*/

#include "my.h"

int check_error_del(hardware_t *delete)
{
    int error = 0;

    if (delete->type == NULL || delete->name == NULL) {
        error = 84;
    } else {
        error = 0;
    }
    if (error != 0)
        return 84;
    return 0;
}

int update(identity_t *id, int count)
{
    hardware_t **prev = &id->line;
    hardware_t *current = id->line;
    int error = 84;

    if (id == NULL || id->line == NULL)
        error = 84;
    while (current != NULL) {
        if (current->num == count) {
            error = check_error_del(current);
            *prev = current->next;
            mini_printf("%s n°%d - \"%s\" deleted.\n",
            current->type, current->num, current->name);
            free(current->type);
            free(current->name);
            free(current);
        }
        prev = &current->next;
        current = current->next;
    }
    return error;
}

int del(void *data, char **args)
{
    identity_t *id = (identity_t *)data;
    int count;
    int error = 0;

    if (args == NULL || args[0] == NULL)
        exit(84);
    for (int i = 0; args[i] != NULL; i++) {
        count = my_getnbr(args[i]);
        if (update(id, count) != 0)
            error = 84;
    }
    return error;
}
