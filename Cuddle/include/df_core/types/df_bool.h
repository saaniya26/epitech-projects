/*
** EPITECH PROJECT, 2025
** df_bool
** File description:
** Cuddle
*/

#ifndef DF_TYPES_BOOL_H
    #define DF_TYPES_BOOL_H

void *df_bool_create(const void *v_value);
bool_t df_bool_id(const char *string);
void *df_bool_convert(const char *string);
int df_bool_write(void *value, FILE *file);
char *df_bool_string(const void *value);

#endif
