/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** path
*/

#include <errno.h>
#include "../include/my.h"

static void exec_external(char **args, const char *path, env_t *env)
{
    char *exec_path = find_executable(args[0], path);

    if (!exec_path) {
        my_putstr(args[0]);
        my_putstr(": Command not found\n");
        free_array(args);
        exit(1);
    }
    execve(exec_path, args, env->env_vars);
    my_putstr("execve failed\n");
    exit(84);
}

static void pipe_parent(int *in_fd, int *fd, int *i, pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    check_status(status);
    close(fd[1]);
    if (*in_fd != 0)
        close(*in_fd);
    *in_fd = fd[0];
    (*i)++;
}

void pipe_child(char *cmd, pipe_t *pipex)
{
    char **args = my_str_to_word_array(cmd);

    if (args == NULL || args[0] == NULL) {
        my_putstr("Invalid null command.\n");
        exit(1);
    }
    if (pipex->in_fd != 0) {
        dup2(pipex->in_fd, 0);
        close(pipex->in_fd);
    }
    if (!pipex->last)
        dup2(pipex->fd[1], 1);
    close(pipex->fd[0]);
    close(pipex->fd[1]);
    if (is_builtin(args[0])) {
        handle_builtin(args, pipex->env);
        free_array(args);
        exit(0);
    }
    exec_external(args, pipex->path, pipex->env);
}

static int launch_pipe(char *cmd, pipe_t *pipe_struct,
    int *in_fd, int *i)
{
    pid_t pid;

    if (pipe(pipe_struct->fd) == -1)
        return 84;
    pid = fork();
    if (pid == -1)
        return 84;
    if (pid == 0)
        pipe_child(cmd, pipe_struct);
    else
        pipe_parent(in_fd, pipe_struct->fd, i, pid);
    return 0;
}

void execute_pipe(char **commands, env_t *env, const char *path)
{
    int i = 0;
    int in_fd = 0;
    int fd[2];
    pid_t pid;
    pipe_t pipe_struct;

    check_cmd_pipe(commands, env);
    while (commands[i] != NULL) {
        pipe_struct.in_fd = in_fd;
        pipe_struct.fd = fd;
        pipe_struct.last = (commands[i + 1] == NULL);
        pipe_struct.env = env;
        pipe_struct.path = path;
        if (launch_pipe(commands[i], &pipe_struct, &in_fd, &i) == 84) {
            if (in_fd != 0)
                close(in_fd);
            return;
        }
    }
}
