/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4040
*/

#ifndef C4040_HPP_
    #define C4040_HPP_

#include "AComponent.hpp"
#include <cstdint>
#include <iostream>
#include <string>

namespace nts
{
    class C4040 : public AComponent {
        public:
            explicit C4040(const std::string &name);
            ~C4040() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            std::size_t getBitIndex(std::size_t pin) const;
            std::uint16_t _value;
            bool _defined;
            nts::Tristate _clock;
    };
}

#endif
