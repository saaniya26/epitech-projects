/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** logger
*/

#ifndef LOGGER_HPP_
    #define LOGGER_HPP_

#include "AComponent.hpp"
#include <iostream>
#include <string>

namespace nts
{
    class Logger : public AComponent {
        public:
            explicit Logger(const std::string &name);
            ~Logger() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            nts::Tristate _last;
    };
}

#endif
