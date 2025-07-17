/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef LIB_LIST
    #define LIB_LIST
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include "shell.h"

typedef enum type {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE,
    INVALID
} type_t;

typedef struct hardware {
    type_t *type;
    char *name;
    int num;
    struct hardware *next;
} hardware_t;

typedef struct identity {
    int next_id;
    hardware_t *line;
} identity_t;

int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_strcmp(char const *str, char const *src);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int mini_printf(const char *format, ...);
int my_getnbr(char const *str);
int verification(int *nbr, char const *str, int i);
int number(int *nbr, char const *str, int i);
void display_add(identity_t *id, hardware_t *hardware);
hardware_t *store_add(int id, const char *type, const char *name);
int update(identity_t *id, int count);
int check_args(char **args, int i);
type_t check_type(const char *type);
#endif
