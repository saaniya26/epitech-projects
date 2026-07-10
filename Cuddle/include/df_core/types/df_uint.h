/*
** EPITECH PROJECT, 2025
** df_uint
** File description:
** Cuddle
*/

#ifndef DF_TYPES_UINT_H
    #define DF_TYPES_UINT_H

void *df_uint_create(const void *v_value);
bool_t df_uint_id(const char *string);
void *df_uint_convert(const char *string);
int df_uint_write(void *value, FILE *file);
char *df_uint_string(const void *value);

#endif
