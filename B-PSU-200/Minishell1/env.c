/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** env
*/

#include "my.h"

char *get_env_var(env_t *env, const char *name)
{
    int name_len = my_strlen(name);

    for (int i = 0; env->env_vars[i]; i++) {
        if (my_strncmp(env->env_vars[i], name, name_len) == 0 &&
            env->env_vars[i][name_len] == '=')
            return &env->env_vars[i][name_len + 1];
    }
    return NULL;
}

env_t *init_env(char **envp)
{
    env_t *env = malloc(sizeof(env_t));
    int size = 0;

    if (!env)
        return NULL;
    while (envp[size])
        size++;
    env->env_vars = malloc(sizeof(char *) * (size + 2));
    if (!env->env_vars) {
        free(env);
        return NULL;
    }
    env->size = size + 1;
    for (int i = 0; i < size; i++)
        env->env_vars[i] = my_strdup(envp[i]);
    env->env_vars[size] =
    my_strdup("NLSPATH=/usr/share/locale/%L/LC_MESSAGES/%N.cat:/usr/share/locale/%l/LC_MESSAGES/%N.cat");
    env->env_vars[size + 1] = NULL;
    return env;
}

char *get_path_from_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return env[i] + 5;
        }
    }
    return NULL;
}

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
}

void free_env(env_t *env)
{
    free_array(env->env_vars);
    free(env);
}
