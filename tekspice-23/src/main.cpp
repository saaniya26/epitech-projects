/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** main
*/

#include <iostream>
#include "Shell.hpp"
#include "Circuit.hpp"
#include "Parser.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Not enough arguments" << std::endl;
        return 84;
    }
    try {
        nts::Circuit circuit;
        nts::Parser parser(circuit);
        parser.parse_file(argv[1]);
        nts::Shell shell(circuit);
        shell.run();
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 84;
    }
    return 0;
}
