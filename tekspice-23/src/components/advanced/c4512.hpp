/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4512
*/

#ifndef C4512_HPP_
    #define C4512_HPP_

#include "AComponent.hpp"
#include <iostream>
#include <string>

namespace nts
{
    class C4512 : public AComponent {
        public:
            explicit C4512(const std::string &name);
            ~C4512() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            std::size_t getDataPin(std::size_t index) const;
    };
}

#endif
