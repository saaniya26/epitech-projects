/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>

typedef struct hashtable_node_s {
    char *key;
    char *value;
    struct hashtable_node_s *next;
} hashtable_node_t;

typedef struct hashtable_s {
    int (*hash)(char *, int);
    int size;
    struct hashtable_node_s **table;
} hashtable_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_short(int nb);
int my_put_nbr_long(long int nb);
int my_putstr(char const *str);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_switch(char ac, va_list arg);
int mini_printf(const char *format, ...);
int hash(char *key, int len);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int ht_insert(hashtable_t *ht, char *key, char *value);
hashtable_node_t *find_node(hashtable_node_t *head, char *key);
hashtable_node_t *create_node(char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
int cut_out(hashtable_node_t *node, char *value);
int cut(hashtable_node_t *current, hashtable_node_t *prev,
    hashtable_t *ht, int index);
#endif
