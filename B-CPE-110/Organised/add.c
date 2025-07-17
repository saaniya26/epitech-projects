/*
** EPITECH PROJECT, 2024
** organized
** File description:
** add
*/

#include "my.h"

type_t check_type(const char *type)
{
    if (!type)
        return INVALID;
    if (my_strcmp(type, "ACTUATOR") == 0)
        return ACTUATOR;
    if (my_strcmp(type, "DEVICE") == 0)
        return DEVICE;
    if (my_strcmp(type, "PROCESSOR") == 0)
        return PROCESSOR;
    if (my_strcmp(type, "SENSOR") == 0)
        return SENSOR;
    if (my_strcmp(type, "WIRE") == 0)
        return WIRE;
    return INVALID;
}

int check_args(char **args, int i)
{
    type_t type = check_type(args[i]);

    if (type == INVALID)
        exit(84);
    if (args[i + 1] == NULL)
        exit(84);
    return 0;
}

hardware_t *store_add(int id, const char *type, const char *name)
{
    hardware_t *info = malloc(sizeof(hardware_t));

    if (info == NULL)
        exit(84);
    info->num = id;
    info->type = my_strdup(type);
    info->name = my_strdup(name);
    if (!info->type || !info->name) {
        mini_printf("Memory allocation failed");
        free(info->type);
        free(info->name);
        free(info);
        return NULL;
    }
    info->next = NULL;
    return info;
}

void display_add(identity_t *id, hardware_t *hardware)
{
    hardware->next = id->line;
    id->line = hardware;
    mini_printf("%s n°%d - \"%s\" added.\n",
    hardware->type, hardware->num, hardware->name);
}

int add(void *data, char **args)
{
    hardware_t *info;
    int error;
    identity_t *count = (identity_t *)data;

    for (int i = 0; args[i] != NULL; i = i + 2) {
        error = check_args(args, i);
        if (error == 84)
            continue;
        info = store_add(count->next_id, args[i], args[i + 1]);
        count->next_id++;
        if (!info)
            exit(84);
        display_add(count, info);
    }
    return 0;
}
