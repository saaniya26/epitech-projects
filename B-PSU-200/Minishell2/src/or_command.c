/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** or_command
*/

#include "../include/my.h"

char **split_or_commands(char *command)
{
    int cmd_count = 1;
    char *temp = command;
    char **result;
    int i = 0;

    while ((temp = strstr(temp, "||"))) {
        cmd_count++;
        temp += 2;
    }
    result = malloc(sizeof(char *) * (cmd_count + 1));
    if (!result)
        return NULL;
    temp = command;
    char *start = command;
    for (i = 0; i < cmd_count; i++) {
        char *end = strstr(start, "||");
        if (end) {
            *end = '\0';
            result[i] = my_strdup(start);
            *end = '|';
            start = end + 2;
        } else {
            result[i] = my_strdup(start);
        }
    }
    result[i] = NULL;
    return result;
}

void handle_or_commands(char *command, env_t *env, const char *path)
{
    char **commands = split_or_commands(command);
    int i;

    if (!commands)
        return;
    for (i = 0; commands[i]; i++) {
        char *cmd = commands[i];
        while (*cmd && (*cmd == ' ' || *cmd == '\t'))
            cmd++;
        instruction(cmd, env, path);
        if (env->last_status == 0)
            break;
    }
    for (i = 0; commands[i]; i++)
        free(commands[i]);
    free(commands);
}
