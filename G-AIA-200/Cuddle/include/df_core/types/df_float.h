/*
** EPITECH PROJECT, 2025
** df_float
** File description:
** Cuddle
*/

#ifndef DF_TYPES_FLOAT_H
    #define DF_TYPES_FLOAT_H

void *df_float_create(const void *v_value);
bool_t df_float_id(const char *string);
void *df_float_convert(const char *string);
int df_float_write(void *value, FILE *file);
char *df_float_string(const void *value);

#endif
