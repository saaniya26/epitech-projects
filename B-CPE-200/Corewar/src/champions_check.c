/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** champions_check.c
*/

#include "../include/my.h"

static int open_and_read_header(int fd, header_t *header)
{
    unsigned char padding[4];

    if (read(fd, &header->magic, 4) != 4)
        return my_puterror("Erreur: lecture magic échouée.\n");
    if (read(fd, &header->prog_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
        return my_puterror("Erreur: lecture nom échouée.\n");
    if (read(fd, padding, 4) != 4)
        return my_puterror("Erreur: lecture padding après nom échouée.\n");
    if (read(fd, &header->prog_size, 4) != 4)
        return my_puterror("Erreur: lecture taille échouée.\n");
    if (read(fd, &header->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
        return my_puterror("Erreur: lecture commentaire échouée.\n");
    if (read(fd, padding, 4) != 4)
        return my_puterror(
            "Erreur: lecture padding après commentaire échouée.\n");
    return EXIT_SUCCESS;
}

static int validate_header(header_t *header)
{
    if (swap_oct(header->magic) != COREWAR_EXEC_MAGIC)
        return my_puterror("Erreur: magic number invalide.\n");
    if (swap_oct(header->prog_size) > CHAMP_MAX_SIZE)
        return my_puterror("Erreur: taille du programme trop grande.\n");
    return EXIT_SUCCESS;
}

static champion_t *init_champion_struct(header_t *header,
    champ_opt_t *opt, vm_t *vm)
{
    champion_t *champ = malloc(sizeof(champion_t));

    if (!champ)
        return NULL;
    champ->name = my_strdup(header->prog_name);
    champ->comment = my_strdup(header->comment);
    champ->code_size = swap_oct(header->prog_size);
    champ->id = opt->has_id ? opt->id : vm->nb_champions + 1;
    champ->load_address = opt->has_address
        ? opt->address % MEM_SIZE
        : (MEM_SIZE / (vm->nb_champions + 1)) * vm->nb_champions;
    champ->alive = true;
    champ->last_live_cycle = 0;
    champ->lives_in_period = 0;
    champ->processes = NULL;
    champ->next = NULL;
    return champ;
}

static int read_champion_code(int fd, champion_t *champ)
{
    champ->code = malloc(champ->code_size);
    if (!champ->code)
        return my_puterror("Erreur: malloc du code échoué.\n");
    if (read(fd, champ->code, champ->code_size) != champ->code_size)
        return my_puterror("Erreur: lecture du code échouée.\n");
    return EXIT_SUCCESS;
}

void insert_champion_to_vm(vm_t *vm, champion_t *champ)
{
    champ->next = vm->champions;
    vm->champions = champ;
    vm->nb_champions += 1;
    for (int i = 0; i < champ->code_size; i++) {
        vm->memory[(champ->load_address + i) % MEM_SIZE] = champ->code[i];
    }
}

int handle_champion(vm_t *vm, const char *path, champ_opt_t *opt)
{
    int fd = open(path, O_RDONLY);
    header_t header;
    champion_t *champ = NULL;

    if (fd < 0)
        return my_puterror("Erreur: ouverture du fichier échouée.\n");
    if (open_and_read_header(fd, &header) == EXIT_FAILURE ||
        validate_header(&header) == EXIT_FAILURE)
        return close(fd), EXIT_FAILURE;
    champ = init_champion_struct(&header, opt, vm);
    if (!champ)
        return close(fd), my_puterror("Erreur: malloc champion.\n");
    if (read_champion_code(fd, champ) == EXIT_FAILURE)
        return close(fd), EXIT_FAILURE;
    insert_champion_to_vm(vm, champ);
    close(fd);
    return EXIT_SUCCESS;
}
