/*
** EPITECH PROJECT, 2025
** B-PSU-200
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv, char **env)
{
    const char *path = get_path_from_env(env);
    const char *path_copy;

    if (!path) {
        my_putstr("Path not found\n");
        return 84;
    }
    path_copy = my_strdup(path);
    if (!path_copy)
        return 84;
    shell(path_copy, env);
    free((void *)path_copy);
    return 0;
}
