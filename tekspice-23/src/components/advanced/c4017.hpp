/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef C4017_HPP_
    #define C4017_HPP_

#include "AComponent.hpp"
#include <string>
#include <iostream>

namespace nts
{
    class C4017 : public AComponent {
        public:
            explicit C4017(const std::string &name);
            ~C4017() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void dump() const override;
        private:
            size_t _counter;
            nts::Tristate _last;
    };
}

#endif