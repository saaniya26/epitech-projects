/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** my_getnbr.c
*/

#include "../include/my.h"

static int number(int *nbr, char const *str, int i)
{
    float test = *nbr;

    if (str[i] >= '0' && str[i] <= '9') {
        test = test * 10 + (str[i] - '0');
        if (test > 2147483647) {
            return 2;
        }
        *nbr = *nbr * 10 + (str[i] - '0');
        return 1;
    }
    return 0;
}

static int verification(int *nbr, char const *str, int i)
{
    int j = 0;

    j = number(&*nbr, str, i);
    if ((j == 1 && str[i + 1] < '0') || (str[i + 1] > '9' && j == 1)) {
        return 1;
    } else if (j == 2) {
        return 2;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; str[i] != '\0' && j < 1; i++) {
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') {
            k = 1;
        }
        j = verification(&nbr, str, i);
    }
    if (k == 1) {
        nbr = nbr * -1;
    }
    if (j == 2) {
        return 0;
    }
    return nbr;
}

bool is_number(const char *str)
{
    int i = 0;

    if (str == NULL || str[0] == '\0')
        return false;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

int ends_with_cor(const char *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    if (i < 4)
        return 0;
    if (str[i - 4] != '.' || str[i - 3] != 'c')
        return 0;
    if (str[i - 2] != 'o' || str[i - 1] != 'r')
        return 0;
    return 1;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *stock = malloc(sizeof(char) * (len + 1));

    if (!stock)
        return NULL;
    for (int i = 0; i < len; i++) {
        stock[i] = src[i];
    }
    stock[len] = '\0';
    return stock;
}
