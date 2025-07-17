/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** last_alive
*/

#include "../include/my.h"
#include "../include/op.h"

void dump_memory(vm_t *vm)
{
    char hex[3];

    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0 && i != 0)
            write(1, "\n", 1);
        my_byte_to_hex(vm->memory[i], hex);
        write(1, hex, 2);
    }
    write(1, "\n", 1);
}

int get_last_alive_champion(vm_t *vm)
{
    champion_t *champ = vm->champions;
    int last_id = -1;
    int last_cycle = -1;

    while (champ) {
        if (champ->alive && champ->last_live_cycle >= last_cycle) {
            last_cycle = champ->last_live_cycle;
            last_id = champ->id;
        }
        champ = champ->next;
    }
    return last_id;
}

void print_winner(vm_t *vm)
{
    int winner_id = vm->last_live_id;
    champion_t *champ = vm->champions;
    char num[12];

    while (champ) {
        if (champ->id == winner_id) {
            my_putstr("The player ");
            my_sprintf(champ->id, num);
            my_putstr(num);
            my_putstr("(");
            my_putstr(champ->name);
            my_putstr(") has won.\n");
            return;
        }
        champ = champ->next;
    }
    my_putstr("No winner.\n");
}

void kill_dead_processes(vm_t *vm)
{
    process_t **pp = &vm->processes;
    process_t *tmp;

    while (*pp) {
        if (!(*pp)->is_alive) {
            tmp = *pp;
            *pp = (*pp)->next;
            free(tmp);
        } else {
            (*pp)->is_alive = false;
            pp = &(*pp)->next;
        }
    }
}

static void execute_cycle(vm_t *vm)
{
    process_t *process = vm->processes;
    int opcode;

    while (process) {
        opcode = fetch_opcode(vm, process);
        instructions(vm, process, opcode);
        process = process->next;
    }
}

static bool handle_cycle_events(vm_t *vm, int cycle, int *cycles_since_check,
    int cycles_to_die)
{
    if (vm->dump_cycle != -1 && cycle == vm->dump_cycle) {
        dump_memory(vm);
        return true;
    }
    if (*cycles_since_check >= cycles_to_die) {
        kill_dead_processes(vm);
        *cycles_since_check = 0;
        if (!vm->processes)
            return true;
    }
    return false;
}

void run_vm(vm_t *vm)
{
    int cycle = 0;
    int cycles_since_check = 0;
    int cycles_to_die = vm->cycles_to_die;

    while (vm->processes) {
        execute_cycle(vm);
        cycle++;
        vm->cycles = cycle;
        cycles_since_check++;
        if (handle_cycle_events(vm, cycle, &cycles_since_check, cycles_to_die))
            break;
    }
    print_winner(vm);
}
