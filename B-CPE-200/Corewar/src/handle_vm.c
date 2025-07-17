/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** init_vm.c
*/

#include "../include/my.h"
#include "../include/op.h"

void clear_vm(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++)
        vm->memory[i] = 0;
    vm->champions = NULL;
    vm->nb_champions = 0;
    vm->cycles = 0;
    vm->cycles_to_die = CYCLE_TO_DIE;
    vm->checks = 0;
    vm->num_lives = 0;
    vm->dump_cycle = -1;
    vm->processes = NULL;
    vm->last_live_id = -1;
}

void create_initial_processes(vm_t *vm)
{
    champion_t *champ = vm->champions;
    process_t *proc = NULL;

    while (champ) {
        proc = malloc(sizeof(process_t));
        if (proc == NULL)
            exit (84);
        for (int i = 0; i < REG_NUMBER; i++)
            proc->registers[i] = 0;
        proc->registers[0] = champ->id;
        proc->pc = champ->load_address;
        proc->carry = false;
        proc->is_alive = true;
        proc->wait_cycles = 0;
        proc->current_opcode = 0;
        proc->next = vm->processes;
        vm->processes = proc;
        champ = champ->next;
    }
}

int init_vm(vm_t *vm, int ac, char **av)
{
    if (vm == NULL)
        return my_puterror("Erreur : VM non initialisée.\n");
    clear_vm(vm);
    if (parse_args(vm, ac, av) == EXIT_FAILURE)
        return my_puterror("Erreur : parsing des arguments échoué.\n");
    if (vm->nb_champions == 0)
        return my_puterror("Erreur : aucun champion détecté.\n");
    create_initial_processes(vm);
    return EXIT_SUCCESS;
}

int fetch_opcode(vm_t *vm, process_t *process)
{
    return vm->memory[process->pc % MEM_SIZE];
}

static void update_pc(process_t *process, int offset)
{
    process->pc = (process->pc + offset + MEM_SIZE) % MEM_SIZE;
}

static void instruction(vm_t *vm, process_t *process, int opcode)
{
    switch (opcode) {
        case 1:
            op_live(vm, process);
            break;
        case 2:
            op_ld(vm, process);
            break;
        case 3:
            op_st(vm, process);
            break;
        case 4:
            op_add(vm, process);
            break;
        case 5:
            op_sub(vm, process);
            break;
        default:
            update_pc(process, 1);
            break;
    }
}

static void instruction2(vm_t *vm, process_t *process, int opcode)
{
    switch (opcode) {
        case 6:
            op_and(vm, process);
            break;
        case 7:
            op_or(vm, process);
            break;
        case 8:
            op_xor(vm, process);
            break;
        case 9:
            op_zjmp(vm, process);
            break;
        case 10:
            op_ldi(vm, process);
            break;
        default:
            update_pc(process, 1);
            break;
    }
}

static void instruction3(vm_t *vm, process_t *process, int opcode)
{
    switch (opcode) {
        case 11:
            op_sti(vm, process);
            break;
        case 12:
            op_fork(vm, process);
            break;
        case 13:
            op_lld(vm, process);
            break;
        case 14:
            op_lldi(vm, process);
            break;
        case 15:
            op_lfork(vm, process);
            break;
        default:
            update_pc(process, 1);
            break;
    }
}

static void instruction4(vm_t *vm, process_t *process, int opcode)
{
    switch (opcode) {
        case 16:
            op_aff(vm, process);
            break;
        default:
            break;
    }
}

void instructions(vm_t *vm, process_t *process, int opcode)
{
    if (opcode >= 1 && opcode <= 5) {
        instruction(vm, process, opcode);
        return;
    }
    if (opcode >= 6 && opcode <= 10) {
        instruction2(vm, process, opcode);
        return;
    }
    if (opcode >= 11 && opcode <= 15) {
        instruction3(vm, process, opcode);
        return;
    }
    if (opcode == 16) {
        instruction4(vm, process, opcode);
        return;
    }
    update_pc(process, 1);
}
