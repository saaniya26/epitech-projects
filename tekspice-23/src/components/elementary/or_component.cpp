/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** OrComponent
*/

#include "or_component.hpp"

namespace nts
{
    OrComponent::OrComponent(const std::string &name) : AComponent(name)
    {
    }

    nts::Tristate OrComponent::compute(std::size_t pin)
    {
        if (pin == 3) {
            return _or(getLink(1), getLink(2));
        }
        return nts::Tristate::Undefined;
    }

    nts::Tristate OrComponent::_or(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::Tristate::True || b == nts::Tristate::True) {
            return nts::Tristate::True;
        }
        if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
            return nts::Tristate::Undefined;
        }
        return nts::Tristate::False;
    }

    void OrComponent::dump() const
    {
        ;
    }
}
