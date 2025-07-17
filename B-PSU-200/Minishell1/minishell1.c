/*
** EPITECH PROJECT, 2025
** B-PSU-200
** File description:
** minishell1
*/

#include <errno.h>
#include "my.h"

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

char *find_executable(char *command, const char *path)
{
    char *copy_path = my_strdup(path);
    char *token = strtok(copy_path, ":");
    char *full_path = NULL;
    int len = 0;

    while (token) {
        len = strlen(token) + strlen(command) + 2;
        full_path = malloc(len);
        if (!full_path) {
            return NULL;
        }
        concat_path(token, full_path, command);
        if (access(full_path, X_OK) == 0) {
            free(copy_path);
            return full_path;
        }
        token = strtok(NULL, ":");
    }
    free(copy_path);
    return NULL;
}

void execute_command(char **args, const char *line, char **env)
{
    const char *exec_path = find_executable(args[0], line);
    pid_t pid;
    int status;

    if (check_error(args, exec_path) == 84)
        return;
    pid = fork();
    if (pid == 0) {
        execve(exec_path, args, env);
        perror("execve failed");
        exit(84);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        write(2, "Fork failed\n", 12);
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

static void instruction(char **args, env_t *env, const char *path)
{
    if (args[0] && is_builtin(args[0])) {
        handle_builtin(args, env);
    } else {
        execute_command(args, path, env->env_vars);
    
    }
}

void shell(const char *path, char **env1)
{
    char *command;
    char **args;
    env_t *env = init_env(env1);

    while (1) {
        command = read_command();
        if (!command)
            break;
        remove_newline(command);
        if (command[0] == '\0') {
            free(command);
            continue;
        }
        args = my_str_to_word_array(command);
        instruction(args, env, path);
        free_array(args);
        free(command);
    }
}
