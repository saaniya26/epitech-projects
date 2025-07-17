/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** my_str_to_word_array2
*/

#include "../include/my.h"

static int is_delimiter_sep(char c, char sep)
{
    return (c == sep);
}

int my_strlen_sep(char const *str, int k, char sep)
{
    int j = 0;

    while (str[k] != '\0' && !(is_delimiter_sep(str[k], sep))) {
        k++;
        j++;
    }
    return j;
}

int my_count_word_sep(const char *str, char sep)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_delimiter_sep(str[i], sep) && !in_word) {
            in_word = 1;
            count++;
        }
        if (is_delimiter_sep(str[i], sep) && in_word) {
            in_word = 0;
        }
    }
    return count;
}

static void skip_delimiters_sep(const char *str, int *i, char sep)
{
    while (str[*i] != '\0' && is_delimiter_sep(str[*i], sep))
        (*i)++;
}

void copy_word_sep(char *dest, const char *src, int start, int len)
{
    for (int j = 0; j < len; j++) {
        dest[j] = src[start + j];
    }
    dest[len] = '\0';
}

char **my_str_to_word_array_sep(char const *str, char sep)
{
    int k = 0;
    int i = 0;
    char **src;
    int word_len = 0;
    int word_count = my_count_word_sep(str, sep);

    src = malloc(sizeof(char *) * (word_count + 1));
    while (str[i] != '\0') {
        skip_delimiters_sep(str, &i, sep);
        if (str[i] == '\0')
            break;
        word_len = my_strlen_sep(str, i, sep);
        src[k] = malloc(sizeof(char) * (word_len + 1));
        copy_word_sep(src[k], str, i, word_len);
        i += word_len;
        k++;
    }
    src[k] = NULL;
    return src;
}
