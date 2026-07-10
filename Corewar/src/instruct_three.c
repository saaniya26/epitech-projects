/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instruct_three
*/

#include "../include/my.h"
#include "../include/op.h"

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

void op_xor(vm_t *vm, process_t *proc)
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
    proc->registers[reg - 1] = val1 ^ val2;
    proc->carry = ((val1 ^ val2) == 0);
    proc->pc = (proc->pc + offset + 1) % MEM_SIZE;
}

static int get_short_value(vm_t *vm, process_t *proc, int *offset, int type)
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
        arg = read_byte(vm, proc->pc + *offset, 2);
        *offset += 2;
        return arg;
    }
    if (type != 3)
        return -1;
    addr = read_byte(vm, proc->pc + *offset, 2);
    *offset += 2;
    return read_byte(vm, (proc->pc + (addr % IDX_MOD)) % MEM_SIZE, 4);
}

void op_ldi(vm_t *vm, process_t *proc)
{
    int cb = vm->memory[(proc->pc + 1) % MEM_SIZE];
    int type1 = (cb >> 6) & 0x3;
    int type2 = (cb >> 4) & 0x3;
    int offset = 2;
    int val1 = get_short_value(vm, proc, &offset, type1);
    int val2 = get_short_value(vm, proc, &offset, type2);
    int reg = vm->memory[(proc->pc + offset) % MEM_SIZE];
    int addr = 0;
    int res = 0;

    if (val1 == -1 || val2 == -1 || reg < 1 || reg > REG_NUMBER) {
        proc->pc = (proc->pc + offset + 1) % MEM_SIZE;
        return;
    }
    addr = (proc->pc + ((val1 + val2) % IDX_MOD)) % MEM_SIZE;
    res = read_byte(vm, addr, 4);
    proc->registers[reg - 1] = res;
    proc->pc = (proc->pc + offset + 1) % MEM_SIZE;
}

void op_zjmp(vm_t *vm, process_t *process)
{
    int offset = read_byte(vm, process->pc + 1, 2);

    if (process->carry) {
        process->pc = (process->pc + (offset % IDX_MOD)) % MEM_SIZE;
        if (process->pc < 0)
            process->pc += MEM_SIZE;
    } else {
        process->pc = (process->pc + 3) % MEM_SIZE;
    }
}

static int get_reg_value(vm_t *vm, process_t *p, int *offset)
{
    int reg = vm->memory[(p->pc + *offset) % MEM_SIZE];

    if (reg < 1 || reg > REG_NUMBER)
        return -1;
    *offset += 1;
    return p->registers[reg - 1];
}

static int get_value2(vm_t *vm, process_t *p, int *offset, int type)
{
    int val = 0;
    int arg = 0;

    if (type == 1) {
        arg = vm->memory[(p->pc + *offset) % MEM_SIZE];
        if (arg < 1 || arg > REG_NUMBER)
            return -1;
        val = p->registers[arg - 1];
        *offset += 1;
    } else if (type == 2 || type == 3) {
        val = read_byte(vm, p->pc + *offset, 2);
        *offset += 2;
    } else {
        return -1;
    }
    return val;
}

static int validate_and_get(op_context_t *ctx, int type, int *result)
{
    int value = get_value2(ctx->vm, ctx->p, ctx->offset, type);

    if (value == -1)
        return -1;
    *result = value;
    return 0;
}

static void fail_and_advance(process_t *p)
{
    p->pc = (p->pc + 7) % MEM_SIZE;
}

void op_sti(vm_t *vm, process_t *p)
{
    int cb = vm->memory[(p->pc + 1) % MEM_SIZE];
    int offset = 2;
    int t1 = (cb >> 6) & 0x3;
    int t2 = (cb >> 4) & 0x3;
    int t3 = (cb >> 2) & 0x3;
    int v1 = 0;
    int v2 = 0;
    int v3 = 0;
    int addr = 0;
    op_context_t ctx = {vm, p, &offset};

    if (t1 != 1)
        return fail_and_advance(p);
    v1 = get_reg_value(vm, p, &offset);
    if (v1 == -1 || validate_and_get(&ctx, t2, &v2) == -1 ||
        validate_and_get(&ctx, t3, &v3) == -1)
        return fail_and_advance(p);
    addr = (p->pc + ((v2 + v3) % IDX_MOD)) % MEM_SIZE;
    write_bytes(vm, addr, v1);
    p->pc = (p->pc + offset) % MEM_SIZE;
}
