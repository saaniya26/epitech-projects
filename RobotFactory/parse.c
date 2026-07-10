/*
** EPITECH PROJECT, 2025
** raz
** File description:
** saniy
*/
#include "include/my.h"

int comment(file_t *fl)
{
    char **array = NULL;
    int j = 0;
    int i = 0;
    int z = 0;

    for (i = 0; fl->file_info[i] != NULL; i++) {
        array = my_str_to_word_array(fl->file_info[i], ' ');
        if (array[0] != NULL && my_strcmp(array[0], COMMENT_CMD_STRING) == 0)
            break;
        liberez_lakrim(array);
        array = NULL;
    }
    if (array == NULL || array[1] == NULL || array[1][0] != '"')
        return 84;
    for (z = prems(fl->file_info[i], '"') + 1;
        fl->file_info[i][z] != '"'; z++) {
        fl->header->comment[j] = fl->file_info[i][z];
        j++;
    }
    return check_rest(j, fl->file_info[i] + z, 1);
}

static char *getfile(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file_info;
    char *buffer = NULL;

    if (fd == -1 || stat(filepath, &file_info) == -1 || file_info.st_size == 0)
        return (fd != -1) ? close(fd), NULL : NULL;
    buffer = malloc(file_info.st_size + 1);
    if (!buffer)
        return close(fd), NULL;
    if (read(fd, buffer, file_info.st_size) != file_info.st_size)
        return free(buffer), close(fd), NULL;
    buffer[file_info.st_size] = '\0';
    return close(fd), buffer;
}

int get_size(file_t *file)
{
    char **array = NULL;
    int sp_case = -1;

    for (int i = 0; file->file_info[i] != NULL; i++) {
        change_letters(file->file_info[i], ',', ' ');
        sp_case = cases(file, i);
        if (sp_case != -1) {
            i = i + ((sp_case == 0) ? 0 : 1);
            continue;
        }
        array = my_str_to_word_array(file->file_info[i], ' ');
        if (mnemonic(array[0]) == -1 && mnemonic(array[1]) != -1) {
            command_add(file, array + 1, array[0]);
        } else
            command_add(file, array, NULL);
        liberez_lakrim(array);
    }
    file->header->prog_size = check_commands(file);
    return 0;
}

int write_head(file_t *file)
{
    file->header = (header_t *)my_calloc(1, sizeof(header_t));
    file->header->prog_size = 0;
    file->header->magic = COREWAR_EXEC_MAGIC;
    file->header->magic = swap_32(file->header->magic);
    if (!file->header) {
        return 84;
    }
    if (get_name(file) == 84) {
        return 84;
    }
    if (comment(file) == 84) {
        return 84;
    }
    if (get_size(file) == 84) {
        return 84;
    }
    file->header->prog_size = swap_32(file->header->prog_size);
    return 0;
}

int parse(file_t *file, char *filepath)
{
    char *copy_filepath = my_strdup(filepath);
    char *buffer = getfile(copy_filepath);

    file->command = NULL;
    file->status = 0;
    file->file_info = get_array(copy_filepath, buffer);
    if (!file->file_info) {
        free(file);
        return 84;
    }
    for (int i = 0; file->file_info[i] != NULL; i++)
        clean(file->file_info[i]);
    file->filename = get_filename(copy_filepath);
    file->status = write_head(file);
    change_int((char *)&file->header->prog_size, 4);
    free(copy_filepath);
    free(buffer);
    return file->status;
}
