/*
** EPITECH PROJECT, 2025
** df_string
** File description:
** Cuddle
*/

#ifndef DF_TYPES_STRING_H
    #define DF_TYPES_STRING_H

void *df_string_create(const void *v_value);
bool_t df_string_id(const char *string);
void *df_string_convert(const char *string);
int df_string_write(void *value, FILE *file);
char *df_string_string(const void *value);

#endif
