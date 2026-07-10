/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instruct_four
*/

#include "../include/my.h"
#include "../include/op.h"

static int get_value_from_register(vm_t *vm, process_t *p, value_ctx_t *ctx)
{
    int reg = vm->memory[(p->pc + ctx->offset) % MEM_SIZE];

    if (reg < 1 || reg > REG_NUMBER) {
        p->pc = (p->pc + 7) % MEM_SIZE;
        return 0;
    }
    ctx->value = p->registers[reg - 1];
    ctx->offset += 1;
    return 1;
}

static int get_value_from_direct(vm_t *vm, process_t *p, value_ctx_t *ctx)
{
    ctx->value = read_byte(vm, p->pc + ctx->offset, 2);
    ctx->offset += 2;
    return 1;
}

static int get_value_from_indirect(vm_t *vm, process_t *p, value_ctx_t *ctx)
{
    int addr = read_byte(vm, p->pc + ctx->offset, 2);

    addr = (p->pc + addr) % MEM_SIZE;
    ctx->value = read_byte(vm, addr, 4);
    ctx->offset += 2;
    return 1;
}

static int get_value_type(vm_t *vm, process_t *p, int type, value_ctx_t *ctx)
{
    if (type == 1)
        return get_value_from_register(vm, p, ctx);
    if (type == 2)
        return get_value_from_direct(vm, p, ctx);
    if (type == 3)
        return get_value_from_indirect(vm, p, ctx);
    p->pc = (p->pc + 7) % MEM_SIZE;
    return 0;
}

static int get_valid_register(vm_t *vm, process_t *p, int offset)
{
    int reg = vm->memory[(p->pc + offset) % MEM_SIZE];

    if (reg < 1 || reg > REG_NUMBER) {
        p->pc = (p->pc + 7) % MEM_SIZE;
        return -1;
    }
    return reg;
}

static void execute_lldi(vm_t *vm, process_t *p, int t1, int t2)
{
    int addr = 0;
    int res = 0;
    int reg = 0;
    value_ctx_t ctx1 = {0, 2};
    value_ctx_t ctx2 = {0, 0};

    if (!get_value_type(vm, p, t1, &ctx1))
        return;
    ctx2.offset = ctx1.offset;
    if (!get_value_type(vm, p, t2, &ctx2))
        return;
    reg = get_valid_register(vm, p, ctx2.offset);
    if (reg == -1)
        return;
    addr = (p->pc + ctx1.value + ctx2.value) % MEM_SIZE;
    res = read_byte(vm, addr, 4);
    p->registers[reg - 1] = res;
    p->carry = (res == 0);
    p->pc = (p->pc + ctx2.offset + 1) % MEM_SIZE;
}

void op_lldi(vm_t *vm, process_t *p)
{
    int cb = vm->memory[(p->pc + 1) % MEM_SIZE];
    int t1 = (cb >> 6) & 0x3;
    int t2 = (cb >> 4) & 0x3;

    execute_lldi(vm, p, t1, t2);
}

static void store_if_valid(process_t *p, int reg, int value)
{
    if (reg >= 1 && reg <= REG_NUMBER)
        p->registers[reg - 1] = value;
    p->carry = (value == 0);
}

void op_lld(vm_t *vm, process_t *process)
{
    int coding_byte = vm->memory[(process->pc + 1) % MEM_SIZE];
    int value = 0;
    int reg = 0;
    int addr = 0;

    if (coding_byte == 0x90) {
        value = read_byte(vm, process->pc + 2, 4);
        reg = vm->memory[(process->pc + 6) % MEM_SIZE];
        process->pc = (process->pc + 7) % MEM_SIZE;
    } else if (coding_byte == 0xD0) {
        addr = read_byte(vm, process->pc + 2, 2);
        value = read_byte(vm, (process->pc + addr) % MEM_SIZE, 4);
        reg = vm->memory[(process->pc + 4) % MEM_SIZE];
        process->pc = (process->pc + 5) % MEM_SIZE;
    } else {
        process->pc = (process->pc + 1) % MEM_SIZE;
        return;
    }
    store_if_valid(process, reg, value);
}
