/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** parsing.c
*/

#include "../include/my.h"

int parse_args(vm_t *vm, int ac, char **av)
{
    champ_opt_t opt = {0, 0, false, false};

    for (int i = 1; i < ac; i++) {
        if (handle_arg(vm, &opt, &i, av) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (vm->nb_champions == 0)
        return my_puterror("Erreur: aucun champion fourni.\n");
    return EXIT_SUCCESS;
}

static int handle_dump(vm_t *vm, int *i, char **av)
{
    if (av[*i + 1] == NULL || !is_number(av[*i + 1]))
        return my_puterror("Erreur: -dump sans cycle valide.\n");
    vm->dump_cycle = my_getnbr(av[*i + 1]);
    *i += 1;
    return EXIT_SUCCESS;
}

static int handle_n(champ_opt_t *opt, int *i, char **av)
{
    if (av[*i + 1] == NULL || !is_number(av[*i + 1]))
        return my_puterror("Erreur: -n sans numéro.\n");
    opt->id = my_getnbr(av[*i + 1]);
    opt->has_id = true;
    *i += 1;
    return EXIT_SUCCESS;
}

static int handle_a(champ_opt_t *opt, int *i, char **av)
{
    if (av[*i + 1] == NULL || !is_number(av[*i + 1]))
        return my_puterror("Erreur: -a sans adresse.\n");
    opt->address = my_getnbr(av[*i + 1]);
    opt->has_address = true;
    *i += 1;
    return EXIT_SUCCESS;
}

static int handle_cor_file(vm_t *vm, champ_opt_t *opt, const char *filepath)
{
    if (handle_champion(vm, filepath, opt) == EXIT_FAILURE)
        return EXIT_FAILURE;
    opt->has_id = false;
    opt->has_address = false;
    return EXIT_SUCCESS;
}

int handle_arg(vm_t *vm, champ_opt_t *opt, int *i, char **av)
{
    if (my_strcmp(av[*i], "-dump") == 0)
        return handle_dump(vm, i, av);
    if (my_strcmp(av[*i], "-n") == 0)
        return handle_n(opt, i, av);
    if (my_strcmp(av[*i], "-a") == 0)
        return handle_a(opt, i, av);
    if (ends_with_cor(av[*i]))
        return handle_cor_file(vm, opt, av[*i]);
    return my_puterror("Erreur: argument inconnu.\n");
}
