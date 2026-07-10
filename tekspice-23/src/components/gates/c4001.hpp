/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef C4001_HPP_
    #define C4001_HPP_

#include "AComponent.hpp"
#include <iostream>
#include <map>
#include <set>

namespace nts
{
    class C4001 : public AComponent {
        public:
            explicit C4001(const std::string &name);
            ~C4001() override = default;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void dump() const override;
        private:
            std::string _type;
            std::map<std::size_t, nts::Tristate> _last;
            std::set<std::size_t> _computing;
    };
}

#endif