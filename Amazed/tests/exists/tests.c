/*
** EPITECH PROJECT, 2025
** tests (Exists)
** File description:
** Amazed
*/

#include <stdio.h>
#include <unistd.h>
#include "amazed.h"
#include "my.h"
#include "utils.h"
#include "charsmod.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static int prog_failure_unkn(void)
{
    my_putstr_fd("[TESTS]: Test aborted due to unknown error!\n", STDERR);
    return FUNC_SUCCESS;
}

static int prog_failure(void)
{
    my_putstr_fd("[TESTS]: Function exitted with FUNC_FAILED status!\n"
        "Program EXIT 84!\n", STDERR);
    return FUNC_SUCCESS;
}

static int write_to_stdin(FILE *stdin_redir, const char *string)
{
    if (stdin_redir == NULL || string == NULL)
        return FUNC_FAILED;
    fwrite(string, sizeof(char *), my_strlen(string), stdin_redir);
    fclose(stdin_redir);
    return FUNC_SUCCESS;
}

Test(test_exists, program_exists, .init=cr_redirect_stdin)
{
    bool do_not_exec = false;
    const char *input = "Hello world!\n";

    if (write_to_stdin(cr_get_redirected_stdin(), input) == FUNC_FAILED) {
        do_not_exec = true;
        cr_fail(prog_failure_unkn);
    }
    if (am_main() != FUNC_FAILED && !do_not_exec)
        cr_fail(prog_failure);
    my_putchar(C_LF);
}
