/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** testfile.c
*/

#include "../include/my.h"

void display_usage(void)
{
    char *usage =
        "USAGE\n"
        "./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] "
        "prog_name] ...\n"
        "DESCRIPTION\n"
        "-dump nbr_cycle dumps the memory after the nbr_cycle execution (if "
        "the round isn't already over) with the following format: 32 bytes/"
        "line in hexadecimal (A0BCDEFE1DD3...)\n"
        "-n prog_number sets the next program's number. By default, the "
        "first free number in the parameter order\n"
        "-a load_address sets the next program's loading address. When no "
        "address is specified, optimize the addresses so that the processes "
        "are as far away from each other as possible. The addresses are "
        "MEM_SIZE modulo.\n";

    fwrite(usage, 1, my_strlen(usage), stdout);
}

int main(int ac, char **av)
{
    vm_t vm;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_usage();
        return EXIT_SUCCESS;
    } else if (ac < 2) {
        display_usage();
        return EXIT_FAILURE;
    }
    if (init_vm(&vm, ac, av) == EXIT_FAILURE)
        return EXIT_FAILURE;
    run_vm(&vm);
    return EXIT_SUCCESS;
}
