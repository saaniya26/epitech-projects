/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_

#include "AComponent.hpp"
#include <string>

namespace nts
{
    class AndComponent : public AComponent {
        public:
            explicit AndComponent(const std::string &name);
            ~AndComponent() override = default;
            nts::Tristate compute(std::size_t pin) override;
            static nts::Tristate _and(nts::Tristate a, nts::Tristate b);
            void dump() const override;
    };
}

#endif