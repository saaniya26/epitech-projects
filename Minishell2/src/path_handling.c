/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** path_handling
*/

#include "../include/my.h"

char *concat_path(char *token, char *full_path, char *command)
{
    int i = 0;
    int j = 0;

    for (; token[i]; i++){
        full_path[i] = token[i];
    }
    full_path[i] = '/';
    i++;
    for (; command[j] != '\0'; j++) {
        full_path[i] = command[j];
        i++;
    }
    full_path[i] = '\0';
}

static int path_type(char *command)
{
    return (command[0] == '/' ||
        (command[0] == '.' && command[1] == '/') ||
        (command[0] == '.' && command[1] == '.' && command[2] == '/'));
}

char *search_path(char *command, char *copy_path)
{
    char *token = strtok(copy_path, ":");
    char *full;
    int len;

    while (token) {
        len = strlen(token) + strlen(command) + 2;
        full = malloc(len);
        if (!full)
            return NULL;
        concat_path(token, full, command);
        if (access(full, X_OK) == 0)
            return full;
        free(full);
        token = strtok(NULL, ":");
    }
    return NULL;
}

char *find_executable(char *command, const char *path)
{
    char *copy_path;
    char *result;

    if (path_type(command) && access(command, X_OK) == 0)
        return my_strdup(command);
    if (!path)
        return NULL;
    copy_path = my_strdup(path);
    if (!copy_path)
        return NULL;
    result = search_path(command, copy_path);
    free(copy_path);
    return result;
}
