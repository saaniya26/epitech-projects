/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** builtin
*/

#include "../include/my.h"

int handle_builtin(char **args, env_t *env)
{
    int status = 0;

    if (my_strcmp(args[0], "42") == 0)
        status = builtin_four(args);
    if (my_strcmp(args[0], "cd") == 0)
        status = builtin_cd(args, env);
    if (my_strcmp(args[0], "env") == 0)
        status = builtin_env(args, env);
    if (my_strcmp(args[0], "exit") == 0)
        status = builtin_exit(args, env);
    if (my_strcmp(args[0], "setenv") == 0)
        status = builtin_setenv(args, env);
    if (my_strcmp(args[0], "unsetenv") == 0)
        status = builtin_unsetenv(args, env);
    env->last_status = status;
    return status;
}

int builtin_four(char **args)
{
    my_putstr("life, the universe and Everything.\n");
    exit(42);
}

int builtin_cd(char **args, env_t *env)
{
    char *path = NULL;
    char cwd[1024];

    if (!args[1] || (args[1][0] == '~' && args[1][1] == '\0')) {
        path = get_env_var(env, "HOME");
        if (path == NULL) {
            my_putstr("cd: No home directory.\n");
            return 84;
        }
    } else {
        path = args[1];
    }
    if (chdir(path) != 0) {
        write(2, args[1], my_strlen(args[1]));
        my_putstr(": No such file or directory.\n");
        return 84;
    }
    getcwd(cwd, sizeof(cwd));
    return 0;
}

int builtin_env(char **args, env_t *env)
{
    for (int i = 0; env->env_vars[i] != NULL; i++) {
        my_putstr(env->env_vars[i]);
        my_putstr("\n");
    }
    return 0;
}

int builtin_exit(char **args, env_t *env)
{
    int status = 0;

    if (args[1])
        status = my_getnbr(args[1]);
    free_env(env);
    my_putstr("exit\n");
    exit(status);
    return status;
}

int is_builtin(char *command)
{
    const char *builtins[] = {"cd", "env", "setenv",
    "unsetenv", "exit", NULL};

    for (int i = 0; builtins[i]; i++) {
        if (my_strcmp(command, builtins[i]) == 0)
            return 1;
    }
    return 0;
}
