/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** not_component
*/

#include "not_component.hpp"

namespace nts
{
    NotComponent::NotComponent(const std::string &name) : AComponent(name)
    {
    }

    Tristate NotComponent::compute(std::size_t pin)
    {
        if (pin == 2 || pin == 3) {
            return _not(getLink(1));
        }
        return nts::Tristate::Undefined;
    }

    Tristate NotComponent::_not(nts::Tristate a)
    {
        if (a == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        if (a == nts::Tristate::True)
            return nts::Tristate::False;
        return nts::Tristate::True;
    }

    void NotComponent::dump() const
    {
        ;
    }
}
