/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef C4030_HPP_
    #define C4030_HPP_

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class C4030 : public AComponent {
        public:
            explicit C4030(const std::string &name);
            ~C4030() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            std::string _type;
    };
}

#endif