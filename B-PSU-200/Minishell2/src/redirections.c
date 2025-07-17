/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** redirections
*/

#include "../include/my.h"

static char *style(char **args, int i)
{
    if (args[i + 1] == NULL) {
        my_putstr("Missing name for redirect.\n");
        return NULL;
    }
}

char *find_redirection_file(char **args, const char *symbol)
{
    for (int i = 0; args[i]; i++) {
        if (my_strcmp(args[i], symbol) == 0) {
            style(args, i);
            args[i] = NULL;
            return args[i + 1];
        }
    }
    return NULL;
}

static void clean_args(char **args)
{
    int write_count = 0;

    for (int read_count = 0; args[read_count]; read_count++) {
        if (my_strcmp(args[read_count], "<") == 0 ||
            my_strcmp(args[read_count], ">") == 0 ||
            my_strcmp(args[read_count], ">>") == 0) {
            read_count++;
            continue;
        }
        args[write_count] = args[read_count];
        write_count++;
    }
    args[write_count] = NULL;
}

static int open_redirection_file(const char *filename,
    int is_output, int append)
{
    int flags;

    if (is_output) {
        if (append)
            flags = O_WRONLY | O_CREAT | O_APPEND;
        else
            flags = O_WRONLY | O_CREAT | O_TRUNC;
    } else {
        flags = O_RDONLY;
    }
    return open(filename, flags, 0644);
}

static int do_redirection(int std_fd, const char *filename,
    int is_output, int append)
{
    int fd = open_redirection_file(filename, is_output, append);

    if (fd < 0) {
        my_putstr("Redirection error\n");
        return -1;
    }
    if (dup2(fd, std_fd) < 0) {
        my_putstr("dup2 error\n");
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

redirection_t parse_redirections(char **args)
{
    redirection_t redir = {0};
    char *out_append = find_redirection_file(args, ">>");
    char *out = find_redirection_file(args, ">");
    char *in = find_redirection_file(args, "<");

    if (out_append) {
        redir.out_file = out_append;
        redir.append_out = 1;
    } else if (out) {
        redir.out_file = out;
        redir.append_out = 0;
    }
    redir.in_file = in;
    clean_args(args);
    return redir;
}

int init_redirections(redirection_t *redir)
{
    if (redir->in_file &&
        do_redirection(0, redir->in_file, 0, 0) < 0)
        return -1;
    if (redir->out_file &&
        do_redirection(1, redir->out_file, 1, redir->append_out) < 0)
        return -1;
    return 0;
}

static void launch_redir_command(char **args,
    redirection_t *redir, const char *path, env_t *env)
{
    if (args[0] == NULL || init_redirections(redir) < 0)
        exit(84);
    if (is_builtin(args[0])) {
        handle_builtin(args, env);
        exit(0);
    }
    execute_command(args, path, env->env_vars);
    exit(0);
}

static void handle_redir_child(char **args,
    const char *path, env_t *env)
{
    redirection_t redir = parse_redirections(args);

    launch_redir_command(args, &redir, path, env);
}

void handle_redirections(char **args,
    const char *path, env_t *env)
{
    pid_t pid = fork();

    if (pid == 0)
        handle_redir_child(args, path, env);
    else if (pid > 0)
        wait(NULL);
}
