/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef C4069_HPP_
    #define C4069_HPP_

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class C4069 : public AComponent {
        public:
            explicit C4069(const std::string &name);
            ~C4069() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            std::string _type;
    };
}

#endif