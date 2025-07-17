/*
** EPITECH PROJECT, 2025
** B-PSU-200
** File description:
** check_error
*/

#include "../include/my.h"

void check_status(int status)
{
    int signal;

    if (!WIFSIGNALED(status))
        return;
    signal = WTERMSIG(status);
    if (signal == SIGSEGV)
        my_putstr("Segmentation fault");
    else if (signal == SIGFPE)
        my_putstr("Floating exception");
    else
        return;
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)");
    write(1, "\n", 1);
}

int check_setenv(char **args, env_t *env)
{
    if (!args[1]) {
        builtin_env(args, env);
        return 0;
    }
}

int check_error(char **args, const char *exec_path)
{
    if (!args || !args[0]) {
        write(2, "Empty command\n", 14);
        return 84;
    }
    if (!exec_path) {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Command not found.\n", 21);
        return 84;
    }
    return 0;
}

void remove_newline(char *str)
{
    int len = 0;

    if (!str)
        return;
    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int check_valid_var(char *var)
{
    if (!var || !my_isalpha(var[0])) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    for (int i = 1; var[i]; i++) {
        if (!my_isalnum(var[i]) && var[i] != '_') {
            write(2,
            "setenv: Variable name must contain alphanumeric characters.\n"
            , 60);
            return 0;
        }
    }
    return 1;
}
