/*
** EPITECH PROJECT, 2024
** razm
** File description:
** gestion d'erreur
*/

#include "include/my.h"

int add_label_case(file_t *file, int i, char **array)
{
    char *label = my_strdup(array[0]);
    int cont = i + 1;
    char **next_array = NULL;

    liberez_lakrim(array);
    while (file->file_info[cont] != NULL) {
        next_array = my_str_to_word_array(file->file_info[cont], ' ');
        if (mnemonic(next_array[0]) != -1) {
            command_add(file, next_array, label);
            liberez_lakrim(next_array);
            break;
        }
        liberez_lakrim(next_array);
        cont++;
    }
    free(label);
    return cont;
}

int cases(file_t *file, int i)
{
    char **array = my_str_to_word_array(file->file_info[i], ' ');
    int result;

    if (!array[0] || my_strcmp(array[0], NAME_CMD_STRING) == 0 ||
        my_strcmp(array[0], COMMENT_CMD_STRING) == 0) {
        liberez_lakrim(array);
        return 0;
    }
    if (mnemonic(array[0]) == -1 && array[1] == NULL) {
        result = add_label_case(file, i, array);
        return result;
    }
    liberez_lakrim(array);
    return -1;
}
