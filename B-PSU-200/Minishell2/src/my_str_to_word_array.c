/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** splits str
*/

#include "../include/my.h"

static int is_delimiter(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

int my_strlen2(char const *str, int k)
{
    int j = 0;

    while (str[k] != '\0' && !(is_delimiter(str[k]))) {
        k++;
        j++;
    }
    return j;
}

int my_count_word(const char *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_delimiter(str[i]) && !in_word) {
            in_word = 1;
            count++;
        }
        if (is_delimiter(str[i]) && in_word) {
            in_word = 0;
        }
    }
    return count;
}

static void skip_delimiters(const char *str, int *i)
{
    while (str[*i] != '\0' && is_delimiter(str[*i]))
        (*i)++;
}

void copy_word(char *dest, const char *src, int start, int len)
{
    for (int j = 0; j < len; j++) {
        dest[j] = src[start + j];
    }
    dest[len] = '\0';
}

char **my_str_to_word_array(char const *str)
{
    int k = 0;
    int i = 0;
    char **src;
    int word_len = 0;
    int word_count = my_count_word(str);

    src = malloc(sizeof(char *) * (word_count + 1));
    while (str[i] != '\0') {
        skip_delimiters(str, &i);
        if (str[i] == '\0')
            break;
        word_len = my_strlen2(str, i);
        src[k] = malloc(sizeof(char) * (word_len + 1));
        copy_word(src[k], str, i, word_len);
        i += word_len;
        k++;
    }
    src[k] = NULL;
    return src;
}
