/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4512
*/

#ifndef C4514_HPP_
    #define C4514_HPP_

#include "AComponent.hpp"
#include <iostream>
#include <string>

namespace nts
{
    class C4514 : public AComponent {
        public:
            explicit C4514(const std::string &name);
            ~C4514() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void dump() const override;
        private:
    };
}

#endif