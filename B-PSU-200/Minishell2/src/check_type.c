/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** check_type
*/

#include "../include/my.h"

cmd_type_t get_cmd_type(char *command)
{
    if (my_strstr(command, "||"))
        return CMD_OR;
    if (my_strchr(command, ';') != NULL)
        return CMD_SEP;
    if (my_strchr(command, '|') != NULL)
        return CMD_PIPE;
    if (my_strstr(command, "&&") != NULL)
        return CMD_AND;
    if (my_strstr(command, ">>") != NULL)
        return CMD_APPEND_OUTPUT;
    if (my_strstr(command, "<<") != NULL)
        return CMD_HERE_DOC;
    if (my_strchr(command, '>') != NULL)
        return CMD_OUTPUT_REDIRECT;
    if (my_strchr(command, '<') != NULL)
        return CMD_INPUT_REDIRECT;
    return CMD_SIMPLE;
}

void check_cmd_pipe(char **commands, env_t *env)
{
    if (commands == NULL) {
        my_putstr("Invalid null command.\n");
        exit(1);
    }
    for (int j = 0; commands[j]; j++) {
        if (my_strlen(commands[j]) == 0) {
            my_putstr("Invalid null command.\n");
            exit(1);
        }
    }
}
