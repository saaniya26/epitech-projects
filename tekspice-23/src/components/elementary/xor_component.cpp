/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** XorComponent
*/

#include "xor_component.hpp"

namespace nts
{
    XorComponent::XorComponent(const std::string &name) : AComponent(name)
    {
    }

    nts::Tristate XorComponent::compute(std::size_t pin)
    {
        if (pin == 3) {
            return _xor(getLink(1), getLink(2));
        }
        return nts::Tristate::Undefined;
    }

    nts::Tristate XorComponent::_xor(nts::Tristate a, nts::Tristate b)
    {
        if (a == nts::Tristate::Undefined|| b == nts::Tristate::Undefined) {
            return nts::Tristate::Undefined;
        }
        if (a == b) {
            return nts::Tristate::False;
        }
        return nts::Tristate::True;
    }

    void XorComponent::dump() const
    {
        ;
    }
}
