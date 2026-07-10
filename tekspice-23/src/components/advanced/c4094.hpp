/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4512
*/

#ifndef C4094_HPP_
    #define C4094_HPP_

#include "AComponent.hpp"
#include <iostream>
#include <string>
#include <array>
#include <cstddef>

namespace nts
{
    class C4094 : public AComponent {
        public:
            explicit C4094(const std::string &name);
            ~C4094() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void dump() const override;
        private:
            std::array<nts::Tristate, 8> _reg;
            nts::Tristate _last;
    };
}

#endif