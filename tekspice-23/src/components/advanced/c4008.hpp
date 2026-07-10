/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef C4008_HPP_
    #define C4008_HPP_

#include "AComponent.hpp"
#include <string>
#include <iostream>

namespace nts
{
    class C4008 : public AComponent {
        public:
            explicit C4008(const std::string &name);
            ~C4008() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            nts::Tristate _adder(nts::Tristate x, nts::Tristate y, nts::Tristate carry_in, nts::Tristate &carry_out) const;
    };
}

#endif