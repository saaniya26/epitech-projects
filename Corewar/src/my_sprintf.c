/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** my_sprintf.c
*/

#include "../include/my.h"

void my_byte_to_hex(unsigned char byte, char *buffer)
{
    char hex_chars[] = "0123456789abcdef";

    buffer[0] = hex_chars[(byte >> 4) & 0xF];
    buffer[1] = hex_chars[byte & 0xF];
    buffer[2] = '\0';
}

static int fill_digits(char *buffer, int nbr)
{
    int i = 0;
    int digit = 0;

    while (nbr > 0) {
        digit = nbr % 10;
        buffer[i] = digit + '0';
        i += 1;
        nbr /= 10;
    }
    return i;
}

static void add_sign(char *buffer, int *i, bool is_neg)
{
    if (is_neg == true) {
        buffer[*i] = '-';
        *i += 1;
    }
    buffer[*i] = '\0';
}

static void reverse_buffer(char *buffer, int len)
{
    int left = 0;
    int right = len - 1;
    char tmp;

    while (left < right) {
        tmp = buffer[left];
        buffer[left] = buffer[right];
        buffer[right] = tmp;
        left += 1;
        right -= 1;
    }
}

char *my_sprintf(int nbr, char *buffer)
{
    int i = 0;
    bool is_neg = false;

    if (nbr == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }
    if (nbr < 0) {
        is_neg = true;
        nbr = -nbr;
    }
    i = fill_digits(buffer, nbr);
    add_sign(buffer, &i, is_neg);
    reverse_buffer(buffer, i);
    return buffer;
}
