/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instruct_five
*/

#include "../include/my.h"
#include "../include/op.h"

void op_fork(vm_t *vm, process_t *process)
{
    int offset = read_byte(vm, process->pc + 1, 2);
    process_t *new_process = malloc(sizeof(process_t));

    if (new_process == NULL)
        return;
    *new_process = *process;
    new_process->pc = (process->pc + (offset % IDX_MOD)) % MEM_SIZE;
    if (new_process->pc < 0)
        new_process->pc += MEM_SIZE;
    new_process->is_alive = true;
    new_process->wait_cycles = 0;
    new_process->current_opcode = 0;
    new_process->next = vm->processes;
    vm->processes = new_process;
    process->pc = (process->pc + 3) % MEM_SIZE;
}

void op_aff(vm_t *vm, process_t *process)
{
    int reg = vm->memory[(process->pc + 1) % MEM_SIZE];
    char c;

    if (reg < 1 || reg > REG_NUMBER) {
        process->pc = (process->pc + 2) % MEM_SIZE;
        return;
    }
    c = process->registers[reg - 1] % 256;
    write(1, &c, 1);
    process->pc = (process->pc + 2) % MEM_SIZE;
}

void op_lfork(vm_t *vm, process_t *process)
{
    int offset = read_byte(vm, process->pc + 1, 2);
    process_t *new_process = malloc(sizeof(process_t));

    if (!new_process)
        return;
    *new_process = *process;
    new_process->pc = (process->pc + offset) % MEM_SIZE;
    if (new_process->pc < 0)
        new_process->pc += MEM_SIZE;
    new_process->next = vm->processes;
    vm->processes = new_process;
    process->pc = (process->pc + 3) % MEM_SIZE;
}
