/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instruct_two
*/

#include "../include/my.h"
#include "../include/op.h"

void op_add(vm_t *vm, process_t *process)
{
    int coding_byte = vm->memory[(process->pc + 1) % MEM_SIZE];
    int reg1 = vm->memory[(process->pc + 2) % MEM_SIZE];
    int reg2 = vm->memory[(process->pc + 3) % MEM_SIZE];
    int reg3 = vm->memory[(process->pc + 4) % MEM_SIZE];
    int sum = 0;

    if (coding_byte != 0x54) {
        process->pc = (process->pc + 1) % MEM_SIZE;
        return;
    }
    if (reg1 < 1 || reg1 > REG_NUMBER || reg2 < 1 || reg2 > REG_NUMBER ||
    reg3 < 1 || reg3 > REG_NUMBER) {
        process->pc = (process->pc + 5) % MEM_SIZE;
        return;
    }
    sum = process->registers[reg1 - 1] + process->registers[reg2 - 1];
    process->registers[reg3 - 1] = sum;
    process->carry = (sum == 0);
    process->pc = (process->pc + 5) % MEM_SIZE;
}

void op_sub(vm_t *vm, process_t *process)
{
    int coding_byte = vm->memory[(process->pc + 1) % MEM_SIZE];
    int reg1 = vm->memory[(process->pc + 2) % MEM_SIZE];
    int reg2 = vm->memory[(process->pc + 3) % MEM_SIZE];
    int reg3 = vm->memory[(process->pc + 4) % MEM_SIZE];
    int result = 0;

    if (coding_byte != 0x54) {
        process->pc = (process->pc + 1) % MEM_SIZE;
        return;
    }
    if (reg1 < 1 || reg1 > REG_NUMBER || reg2 < 1 || reg2 > REG_NUMBER ||
        reg3 < 1 || reg3 > REG_NUMBER) {
        process->pc = (process->pc + 5) % MEM_SIZE;
        return;
    }
    result = process->registers[reg1 - 1] - process->registers[reg2 - 1];
    process->registers[reg3 - 1] = result;
    process->carry = (result == 0);
    process->pc = (process->pc + 5) % MEM_SIZE;
}

static int get_value(vm_t *vm, process_t *proc, int *offset, int type)
{
    int arg = 0;
    int addr = 0;

    if (type == 1) {
        arg = vm->memory[(proc->pc + *offset) % MEM_SIZE];
        if (arg < 1 || arg > REG_NUMBER)
            return -1;
        *offset += 1;
        return proc->registers[arg - 1];
    }
    if (type == 2) {
        arg = read_byte(vm, proc->pc + *offset, 4);
        *offset += 4;
        return arg;
    }
    if (type != 3)
        return -1;
    addr = read_byte(vm, proc->pc + *offset, 2);
    *offset += 2;
    return read_byte(vm, (proc->pc + (addr % IDX_MOD)) % MEM_SIZE, 4);
}

void op_and(vm_t *vm, process_t *proc)
{
    int cb = vm->memory[(proc->pc + 1) % MEM_SIZE];
    int t1 = (cb >> 6) & 0x3;
    int t2 = (cb >> 4) & 0x3;
    int off = 2;
    int v1 = get_value(vm, proc, &off, t1);
    int v2 = get_value(vm, proc, &off, t2);
    int reg = vm->memory[(proc->pc + off) % MEM_SIZE];

    if (v1 == -1 || v2 == -1 || reg < 1 || reg > REG_NUMBER) {
        proc->pc = (proc->pc + off + 1) % MEM_SIZE;
        return;
    }
    proc->registers[reg - 1] = v1 & v2;
    proc->carry = ((v1 & v2) == 0);
    proc->pc = (proc->pc + off + 1) % MEM_SIZE;
}

void op_or(vm_t *vm, process_t *proc)
{
    int cb = vm->memory[(proc->pc + 1) % MEM_SIZE];
    int type1 = (cb >> 6) & 0x3;
    int type2 = (cb >> 4) & 0x3;
    int offset = 2;
    int val1 = get_value(vm, proc, &offset, type1);
    int val2 = get_value(vm, proc, &offset, type2);
    int reg = vm->memory[(proc->pc + offset) % MEM_SIZE];

    if (val1 == -1 || val2 == -1 || reg < 1 || reg > REG_NUMBER) {
        proc->pc = (proc->pc + offset + 1) % MEM_SIZE;
        return;
    }
    proc->registers[reg - 1] = val1 | val2;
    proc->carry = ((val1 | val2) == 0);
    proc->pc = (proc->pc + offset + 1) % MEM_SIZE;
}
