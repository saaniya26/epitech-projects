/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "and_component.hpp"

namespace nts
{

    AndComponent::AndComponent(const std::string &name) : AComponent(name)
    {
    }

    Tristate AndComponent::compute(std::size_t pin)
    {
        if (pin == 3) {
            return _and(getLink(1), getLink(2));
        }
        return nts::Tristate::Undefined;
    }

    Tristate AndComponent::_and(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::Tristate::False || b == nts::Tristate::False) {
            return nts::Tristate::False;
        }
        if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
            return nts::Tristate::Undefined;
        }
        return nts::Tristate::True;
    }

    void AndComponent::dump() const
    {
        ;
    }
}