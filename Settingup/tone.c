/*
** EPITECH PROJECT, 2025
** settingup
** File description:
** tone
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

void rotone(char *str)
{
    int i;
    i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z')
            my_putchar('a' + ((str[i] - 'a' + 1) % 26));
        else if (str[i] >= 'A' && str[i] <= 'Z')
            my_putchar('A' + ((str[i] - 'A' + 1) % 26));
        else
            my_putchar(str[i]);
        i++;
   }
}

int main(int argc, char **argv)
{
    if (argc > 1)
        rotone(argv[1]);
    my_putchar('\n');
    return (0);
}
