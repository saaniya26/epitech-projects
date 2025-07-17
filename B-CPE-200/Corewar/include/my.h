/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** my.h
*/

#ifndef MYLIST
    #define MYLIST
    #define EXIT_FAILURE 84
    #define EXIT_SUCCESS 0
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include "op.h"

typedef struct process_s {
    int id;
    int pc;
    int registers[REG_NUMBER];
    bool carry;
    bool is_alive;
    int wait_cycles;
    int current_opcode;
    struct process_s *next;
} process_t;
typedef struct champion_s {
    char *name;
    char *comment;
    int id;
    unsigned char *code;
    int code_size;
    int load_address;
    int last_live_cycle;
    int lives_in_period;
    bool alive;
    process_t *processes;
    struct champion_s *next;
} champion_t;

typedef struct vm_s {
    unsigned char memory[MEM_SIZE];
    champion_t *champions;
    int nb_champions;
    int cycles;
    int cycles_to_die;
    int checks;
    int num_lives;
    int dump_cycle;
    process_t *processes;
    int last_live_id;
} vm_t;

typedef struct champ_opt_s {
    int id;
    int address;
    bool has_id;
    bool has_address;
} champ_opt_t;

typedef struct {
    vm_t *vm;
    process_t *p;
    int *offset;
} op_context_t;

typedef struct value_ctx_s {
    int value;
    int offset;
} value_ctx_t;

//tools.c
int my_puterror(const char *msg);
int my_strlen(char const *str);
int my_strcmp(char const *str, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
void my_putstr(char const *str);
void my_putchar(char c);
int swap_oct(int value);
void my_byte_to_hex(unsigned char byte, char *buffer);
//tools2.c
int my_getnbr(char const *str);
bool is_number(const char *str);
int ends_with_cor(const char *str);
//my_sprintf.c
void my_byte_to_hex(unsigned char byte, char *buffer);
char *my_sprintf(int nbr, char *buffer);
//handle_vm.c
void clear_vm(vm_t *vm);
int init_vm(vm_t *vm, int ac, char **av);
int read_byte(vm_t *vm, int address, int size);
void write_bytes(vm_t *vm, int addr, int value);
void run_vm(vm_t *vm);
void dump_memory(vm_t *vm);
int fetch_opcode(vm_t *vm, process_t *process);
void instructions(vm_t *vm, process_t *process, int opcode);
//parsing.c
int parse_args(vm_t *vm, int ac, char **av);
int handle_arg(vm_t *vm, champ_opt_t *opt, int *i, char **av);
//champions_check
int handle_champion(vm_t *vm, const char *path, champ_opt_t *opt);
//instructions.c
void op_live(vm_t *vm, process_t *process);
void op_ld(vm_t *vm, process_t *process);
void op_st(vm_t *vm, process_t *process);
void op_add(vm_t *vm, process_t *process);
void op_sub(vm_t *vm, process_t *process);
void op_and(vm_t *vm, process_t *process);
void op_or(vm_t *vm, process_t *process);
void op_xor(vm_t *vm, process_t *process);
void op_zjmp(vm_t *vm, process_t *process);
void op_ldi(vm_t *vm, process_t *process);
void op_sti(vm_t *vm, process_t *process);
void op_fork(vm_t *vm, process_t *process);
void op_lld(vm_t *vm, process_t *process);
void op_lldi(vm_t *vm, process_t *process);
void op_lfork(vm_t *vm, process_t *process);
void op_aff(vm_t *vm, process_t *process);
#endif
