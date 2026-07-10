/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4801
*/

#ifndef C4801_HPP_
    #define C4801_HPP_

#include "AComponent.hpp"
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace nts
{
    class C4801 : public AComponent {
        public:
            explicit C4801(const std::string &name);
            ~C4801() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            std::size_t getAddress() const;
            std::size_t getDataBitIndex(std::size_t pin) const;
            std::vector<std::uint8_t> _memory;
    };
}

#endif
