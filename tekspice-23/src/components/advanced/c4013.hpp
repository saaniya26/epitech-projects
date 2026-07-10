/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4013
*/

#ifndef C4013_HPP_
    #define C4013_HPP_

#include "AComponent.hpp"
#include <iostream>
#include <string>

namespace nts
{
    class C4013 : public AComponent {
        public:
            explicit C4013(const std::string &name);
            ~C4013() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            nts::Tristate _q1;
            nts::Tristate _qb1;
            nts::Tristate _q2;
            nts::Tristate _qb2;
            nts::Tristate _clock1;
            nts::Tristate _clock2;
    };
}

#endif
