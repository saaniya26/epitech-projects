/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** Shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <map>
#include <string>
#include <csignal>
#include "Circuit.hpp"

namespace nts {
    class Shell {
        public:
            Shell(Circuit &circuit);
            void run();

        protected:
        private:
            Circuit &_circuit;
            std::size_t _tick;
            bool executeCommand(const std::string& line);
            bool assignment(const std::string& line);
            void cmdDisplay() const;
            void cmdSimulate();
            void cmdAssign(const std::string& name, const std::string& value);
            void cmdLoop();
    };
}

#endif /* !SHELL_HPP_ */
