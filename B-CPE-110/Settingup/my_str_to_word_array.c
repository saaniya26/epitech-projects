/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** splits str
*/

#include "settingup.h"

int my_strlen_original(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strlen(char const *str, int k)
{
    int j = 0;

    while (str[k] != '\n' && str[k] != '\0') {
        k++;
        j++;
    }
    return j;
}

int my_count_word(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            j++;
        }
    }
    return j;
}

int exclude_num(int i, const char *str)
{
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
        if (str[i] == '\n') {
            i++;
            return i;
        }
    }
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **src;

    src = malloc(sizeof(char *) * (my_count_word(str) + 1));
    i = exclude_num(i, str);
    for (i; str[i] != '\0'; i++) {
        src[k] = malloc(sizeof(char *) * my_strlen(str, i));
        for (j = 0; str[i] != '\n' && str[i] != '\0'; j++) {
            src[k][j] = str[i];
            i++;
        }
        src[k][j] = '\0';
        k++;
        if (str[i] == '\0')
            break;
    }
    src[k] = NULL;
    return (src);
}
