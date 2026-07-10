/*
** EPITECH PROJECT, 2025
** B-PSU-200
** File description:
** minishell1
*/

#include <errno.h>
#include "../include/my.h"

void execute_command(char **args, const char *line, env_t *env)
{
    const char *exec_path = find_executable(args[0], line);
    pid_t pid;
    int status;

    if (check_error(args, exec_path) == 84) {
        env->last_status = 84;
        return;
    }
    pid = fork();
    if (pid == 0) {
        execve(exec_path, args, env->env_vars);
        my_putstr(args[0]);
        my_putstr(": Permission denied.\n");
        exit(84);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        check_status(status);
    } else {
        my_putstr("Fork failed\n");
        env->last_status = 84;
    }
    free((void *)exec_path);
}

char *read_command(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

char *change_line_sep(const char *command)
{
    char *line = my_strdup(command);

    if (line == NULL)
        return NULL;
    for (int i = 0; line[i]; i++) {
        if (line[i] == ';')
            line[i] = '\n';
    }
    return line;
}

static void handle_with_args(char *command,
    const char *path, env_t *env, int type)
{
    if (type == CMD_SIMPLE) {
        char **args = my_str_to_word_array(command);
        if (args[0] && is_builtin(args[0]))
            handle_builtin(args, env);
        else
            execute_command(args, path, env);
        free_array(args);
    } else if (type == CMD_PIPE) {
        char **args = my_str_to_word_array_sep(command, '|');
        execute_pipe(args, env, path);
        free_array(args);
    } else if (type == CMD_OUTPUT_REDIRECT ||
              type == CMD_APPEND_OUTPUT ||
              type == CMD_INPUT_REDIRECT) {
        char **args = my_str_to_word_array(command);
        handle_redirections(args, path, env);
        free_array(args);
    }
}

static void select_type(cmd_type_t type, char *command,
    const char *path, env_t *env)
{
    handle_with_args(command, path, env, type);
}

void instruction(char *command, env_t *env, const char *path)
{
    cmd_type_t type = get_cmd_type(command);
    char **commands;

    if (type == CMD_SEP) {
        command = change_line_sep(command);
        commands = my_str_to_word_array_sep(command, '\n');
        for (int i = 0; commands[i] != NULL; i++) {
            type = CMD_SIMPLE;
            instruction(commands[i], env, path);
        }
        return;
    }
    if (type == CMD_AND) {
        handle_and_commands(command, env, path);
        return;
    }
    if (type == CMD_OR) {
        handle_or_commands(command, env, path);
        return;
    }
    select_type(type, command, path, env);
}

void shell(const char *path, char **env1)
{
    char *command;
    env_t *env = init_env(env1);

    while (1) {
        write(1, "$> ", 3);
        command = read_command();
        if (!command)
            break;
        remove_newline(command);
        if (command[0] == '\0') {
            free(command);
            continue;
        }
        instruction(command, env, path);
        free(command);
    }
}
