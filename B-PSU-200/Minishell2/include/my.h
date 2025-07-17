/*
** EPITECH PROJECT, 2025
** B-PSU-200
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <fcntl.h>

typedef enum {
    CMD_SIMPLE,
    CMD_PIPE,
    CMD_INPUT_REDIRECT,
    CMD_OUTPUT_REDIRECT,
    CMD_APPEND_OUTPUT,
    CMD_HERE_DOC,
    CMD_SEP,
    CMD_AND,
    CMD_OR
} cmd_type_t;

typedef struct {
    char *in_file;
    char *out_file;
    int append_out;
} redirection_t;

typedef struct env_s {
    char **env_vars;
    int size;
    int last_status;
} env_t;

typedef struct pipe_s {
    int in_fd;
    int *fd;
    int last;
    env_t *env;
    const char *path;
} pipe_t;

char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_sep(char const *str, char sep);
int my_strcmp(char const *str, char const *src);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strchr(const char *str, const char to_find);
const char *my_strstr(const char *str, const char *to_find);
char *my_strdup(char const *src);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_isalpha(int c);
int my_isalnum(int c);
int check_setenv(char **args, env_t *env);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);
void free_env(env_t *env);
void free_array(char **array);
void shell(const char *path, char **env);
void execute_command(char **args, const char *line, env_t *env);
int check_error(char **args, const char *exec_path);
void check_cmd_pipe(char **commands, env_t *env);
void remove_newline(char *str);
char *read_command(void);
char *find_executable(char *command, const char *path);
char *concat_path(char *token, char *full_path, char *command);
char *get_path_from_env(char **env);
env_t *init_env(char **envp);
int check_valid_var(char *var);
void check_status(int status);
int builtin_cd(char **args, env_t *env);
int builtin_env(char **args, env_t *env);
int builtin_exit(char **args, env_t *env);
int handle_builtin(char **args, env_t *env);
int is_builtin(char *command);
char *get_env_var(env_t *env, const char *name);
static char *create_env_entry(const char *name, const char *value);
int update_entry(char **temp, env_t *env, char *new_entry);
int builtin_setenv(char **args, env_t *env);
int builtin_unsetenv(char **args, env_t *env);
cmd_type_t get_cmd_type(char *command);
void execute_pipe(char **commands, env_t *env, const char *path);
void handle_redirections(char **args, const char *path, env_t *env);
void instruction(char *command, env_t *env, const char *path);
void handle_and_commands(char *command, env_t *env, const char *path);
void handle_or_commands(char *command, env_t *env, const char *path);
int builtin_four(char **args);
#endif /* !MY_H_ */
