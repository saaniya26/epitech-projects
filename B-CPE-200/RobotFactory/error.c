/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-robotfactory-saaniya.perally
** File description:
** error
*/

#include "include/my.h"

static int validate_args(char **args, int expected)
{
    int arg_count = 0;

    for (int j = 1; args[j] != NULL; j++)
        arg_count++;
    if (arg_count != expected) {
        return 84;
    }
    return 0;
}

int check_instruction_validity(char **args)
{
    char *valid_instr[] = {"live", "ld", "st", "add", "sub", "and", "or",
    "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff", NULL};
    int valid_args[] = {1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};

    for (int i = 0; valid_instr[i] != NULL; i++) {
        if (my_strcmp(args[0], valid_instr[i]) == 0)
            return validate_args(args, valid_args[i]);
    }
    return 84;
}

int check_parse_errors(file_t *file)
{
    char **args;

    if (!file) {
        return 84;
    }
    if (!file->file_info) {
        return 84;
    }
    for (int i = 0; file->file_info[i] != NULL; i++) {
        args = my_str_to_word_array(file->file_info[i], ' ');
        if (check_instruction_validity(args) == 84) {
            liberez_lakrim(args);
            return 84;
        }
        liberez_lakrim(args);
    }
    return 0;
}

int check_file_extension(char *filename)
{
    int len = my_strlen(filename);

    if (filename[len - 2] != '.' || filename[len - 1] != 's') {
        return 84;
    }
    return 0;
}

static int error_handling(int ac, char **av)
{
    struct stat file;

    return (ac != 2 || stat(av[1], &file) != 0 || file.st_size == 0) ? -1 : 0;
}

static int initialize_file(file_t **file)
{
    *file = malloc(sizeof(file_t));
    if (!*file)
        return 84;
    return 0;
}

int handle_errors(int ac, char **av, file_t *file)
{
    if (initialize_file(&file) == 84)
        return 84;
    if (error_handling(ac, av) == -1)
        return 84;
    if (check_file_extension(av[1]) == 84)
        return 84;
    if (check_parse_errors(file) == 84)
        return 84;
    return 0;
}
