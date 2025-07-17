/*
** EPITECH PROJECT, 2025
** df_int
** File description:
** Cuddle
*/

#ifndef DF_TYPES_INT_H
    #define DF_TYPES_INT_H

void *df_int_create(const void *v_value);
bool_t df_int_id(const char *string);
void *df_int_convert(const char *string);
int df_int_write(void *value, FILE *file);
char *df_int_string(const void *value);

#endif
