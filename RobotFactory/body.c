/*
** EPITECH PROJECT, 2024
** raz
** File description:
** dstock dans struct
*/

#include "include/my.h"

static void condition(char *arg, int prog_size)
{
    if (arg[0] == 'r')
        prog_size += 1;
    else if (arg[0] == '%')
        prog_size += (arg[1] == ':') ? IND_SIZE : DIR_SIZE;
    else
        prog_size += IND_SIZE;
}

int number_params(char **array, int_fast8_t mnemonic)
{
    char *arg;
    int prog_size = (mnemonic != 0x01 && mnemonic != 0x09 &&
                    mnemonic != 0x0c && mnemonic != 0x0f) ? 1 : 0;

    for (int i = 0; array[i] != NULL; i++) {
        arg = array[i];
        condition(arg, prog_size);
        if (arg[0] == '%' && arg[1] != ':' &&
            (mnemonic == 0x0b || mnemonic == 0x03 ||
            mnemonic == 0x09 || mnemonic == 0x0a))
            prog_size -= 2;
    }
    return prog_size;
}

void add_information(command_t *command, char **array, char *label)
{
    int i = 0;

    command->label = NULL;
    command->mnemonic = mnemonic(array[0]);
    if (label) {
        change_letters(label, ':', 0);
        command->label = my_strdup(label);
    }
    for (i = 0; i < MAX_ARGS_NUMBER && array[i + 1] != NULL; i++)
        command->args[i] = my_strdup(array[i + 1]);
    command->args[i] = NULL;
    command->next = NULL;
}

void command_add(file_t *file, char **array, char *label)
{
    command_t *command = malloc(sizeof(command_t));
    command_t *prev;

    if (!command)
        return;
    add_information(command, array, label);
    if (!file->command) {
        command->offset = 0;
        file->command = command;
        return;
    }
    prev = file->command;
    while (prev->next)
        prev = prev->next;
    command->offset = prev->offset +
    number_params(prev->args, prev->mnemonic) + 1;
    prev->next = command;
}

int check_commands(file_t *file)
{
    int prog_size = 0;

    for (command_t *c = file->command; c != NULL; c = c->next) {
        prog_size = c->offset;
        if (!c->next)
            prog_size += number_params(c->args, c->mnemonic) + 1;
    }
    return prog_size;
}

void change_int(char *str, size_t size)
{
    char temp;

    for (size_t i = 0; i < size / 2; i++) {
        temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }
}
