/*
** EPITECH PROJECT, 2025
** main
** File description:
** Cuddle (Tester)
*/

#include <stdlib.h>
#include "my.h"
#include "dataframe.h"
#include "utils.h"

static bool sort_func(void *value1, void *value2)
{
    return *(int *) value1 > *(int *) value2;
}

static int write_delim(dataframe_t *dt, FILE *file)
{
    if (dt == NULL || file == NULL)
        return FUNC_FAILED;
    fprintf("%s", dt->separator);
}

int main(void)
{
    dataframe_t *df = df_read_csv("./tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    if (df == NULL)
        return EXIT_FAILURE_84;
    df2 = df_sort(df, "age", sort_func);
    if (df2 == NULL) {
        df_free(df);
        return EXIT_FAILURE_84;
    }
    df_write_csv(df, "./a-out.csv");
    df_write_csv(df2, "./a2-out.csv");
    df_free(df);
    df_free(df2);
    return EXIT_SUCCESS;
}
