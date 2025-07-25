/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** op.h
*/

#ifndef _OP_H_
    #define _OP_H_

    #define MEM_SIZE (6* 1024)
    #define CHAMP_MAX_SIZE 682
    #define IDX_MOD 512
    #define MAX_ARGS_NUMBER 4
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"
    #define REG_NUMBER 16
    #define T_REG 1
    #define T_DIR 2
    #define T_IND 4
    #define T_LAB 8
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3
    #define CYCLE_TO_DIE 1536
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40
typedef char args_type_t;
typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;
extern const op_t op_tab[];
typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;
#endif
