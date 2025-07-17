/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** builtin2
*/

#include "../include/my.h"

static char *create_env_entry(const char *name, const char *value)
{
    size_t name_len = my_strlen(name);
    size_t value_len = my_strlen(value);
    size_t len = name_len + value_len + 2;
    char *entry;

    entry = malloc(len);
    if (!entry)
        return NULL;
    my_strcpy(entry, name);
    entry[name_len] = '=';
    my_strcpy(entry + name_len + 1, value);
    return entry;
}

int update_entry(char **temp, env_t *env, char *new_entry)
{
    temp = malloc(sizeof(char *) * (env->size + 2));
    if (!temp) {
        free(new_entry);
        return 84;
    }
    for (int i = 0; i < env->size; i++)
        temp[i] = env->env_vars[i];
    temp[env->size] = new_entry;
    temp[env->size + 1] = NULL;
    free(env->env_vars);
    env->env_vars = temp;
    env->size++;
}

void static check_no_arg(char **args)
{
    if (!args[2]) {
        args[2] = malloc(sizeof(char));
        args[2] = '\0';
    }
}

int builtin_setenv(char **args, env_t *env)
{
    char *new_entry;
    char **temp;

    if (!check_setenv(args, env))
        return 84;
    if (!check_valid_var(args[1]))
        return 84;
    check_no_arg(args);
    new_entry = create_env_entry(args[1], args[2]);
    for (int i = 0; env->env_vars[i]; i++) {
        if (my_strncmp(env->env_vars[i], args[1], my_strlen(args[1])) == 0 &&
            env->env_vars[i][my_strlen(args[1])] == '=') {
            free(env->env_vars[i]);
            env->env_vars[i] = new_entry;
            return 0;
        }
    }
    update_entry(temp, env, new_entry);
    return 0;
}

void condition1(int i, env_t *env)
{
    for (int j = i; env->env_vars[j]; j++)
        env->env_vars[j] = env->env_vars[j + 1];
}

int builtin_unsetenv(char **args, env_t *env)
{
    size_t len;

    if (!args[1]) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return 84;
    }
    len = my_strlen(args[1]);
    for (int i = 0; env->env_vars[i]; i++) {
        if (my_strncmp(env->env_vars[i], args[1], len) == 0 &&
            env->env_vars[i][len] == '=') {
            free(env->env_vars[i]);
            condition1(i, env);
            env->size--;
            return 0;
        }
    }
    return 0;
}
