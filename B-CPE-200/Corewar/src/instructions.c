/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions
*/

#include "../include/my.h"
#include "../include/op.h"

int read_byte(vm_t *vm, int address, int size)
{
    int value = 0;

    for (int i = 0; i < size; i++) {
        value = (value << 8) | vm->memory[(address + i) % MEM_SIZE];
    }
    return value;
}

static void print_live_message(int id, champion_t *champion)
{
    char num[12];

    my_putstr("The player ");
    my_sprintf(id, num);
    my_putstr(num);
    my_putstr("(");
    my_putstr(champion->name);
    my_putstr(") is alive.\n");
}

void op_live(vm_t *vm, process_t *process)
{
    int id = 0;
    champion_t *champion = vm->champions;

    id = read_byte(vm, process->pc + 1, 4);
    while (champion) {
        if (champion->id == id) {
            champion->alive = true;
            champion->last_live_cycle = vm->cycles;
            champion->lives_in_period += 1;
            vm->last_live_id = id;
            print_live_message(id, champion);
            break;
        }
        champion = champion->next;
    }
    process->is_alive = true;
    vm->num_lives++;
    process->pc = (process->pc + 5) % MEM_SIZE;
}

void op_ld(vm_t *vm, process_t *process)
{
    int coding_byte = vm->memory[(process->pc + 1) % MEM_SIZE];
    int value = 0;
    int reg = 0;
    int adres = 0;

    if (coding_byte == 0x90) {
        value = read_byte(vm, process->pc + 2, 4);
        reg = vm->memory[(process->pc + 6) % MEM_SIZE];
        process->pc = (process->pc + 7) % MEM_SIZE;
    } else if (coding_byte == 0xD0) {
        adres = read_byte(vm, process->pc + 2, 2);
        value = read_byte(vm, (process->pc + (adres % IDX_MOD)) % MEM_SIZE, 4);
        reg = vm->memory[(process->pc + 4) % MEM_SIZE];
        process->pc = (process->pc + 5) % MEM_SIZE;
    } else {
        process->pc = (process->pc + 1) % MEM_SIZE;
        return;
    }
    if (reg >= 1 && reg <= REG_NUMBER)
        process->registers[reg - 1] = value;
}

void write_bytes(vm_t *vm, int addr, int value)
{
    int i = 0;

    for (i = 0; i < 4; i++) {
        vm->memory[(addr + 3 - i) % MEM_SIZE] = (value >> (i * 8)) & 0xFF;
    }
}

static void store_register(process_t *process, int reg_src, int reg_dest)
{
    if (reg_dest >= 1 && reg_dest <= REG_NUMBER)
        process->registers[reg_dest - 1] = process->registers[reg_src - 1];
}

static void st_condition(vm_t *vm, process_t *process, int byte, int reg)
{
    int value = 0;
    int addr = 0;
    int reg2;

    if (byte == 0x50) {
        reg2 = vm->memory[(process->pc + 3) % MEM_SIZE];
        store_register(process, reg, reg2);
        process->pc = (process->pc + 4) % MEM_SIZE;
    } else if (byte == 0x70) {
        addr = read_byte(vm, process->pc + 3, 2);
        addr = (process->pc + (addr % IDX_MOD)) % MEM_SIZE;
        value = process->registers[reg - 1];
        write_bytes(vm, addr, value);
        process->pc = (process->pc + 5) % MEM_SIZE;
    } else {
        process->pc = (process->pc + 1) % MEM_SIZE;
    }
}

void op_st(vm_t *vm, process_t *process)
{
    int coding_byte = vm->memory[(process->pc + 1) % MEM_SIZE];
    int reg = vm->memory[(process->pc + 2) % MEM_SIZE];

    if (reg < 1 || reg > REG_NUMBER) {
        process->pc = (process->pc + 1) % MEM_SIZE;
        return;
    }
    st_condition(vm, process, coding_byte, reg);
}
