/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4008.hpp"
#include "xor_component.hpp"
#include "and_component.hpp"
#include "or_component.hpp"

namespace nts {

    C4008::C4008(const std::string &name) : AComponent(name)
    {
    }

    Tristate C4008::_adder(nts::Tristate x, nts::Tristate y, nts::Tristate carry_in, nts::Tristate &carry_out) const
    {
        nts::Tristate xor_result = XorComponent::_xor(x, y);
        nts::Tristate sum = XorComponent::_xor(xor_result, carry_in);
        nts::Tristate and_result = AndComponent::_and(x, y);
        nts::Tristate carry_in_result = AndComponent::_and(carry_in, xor_result);
        carry_out = OrComponent::_or(and_result, carry_in_result);
        return sum;
    }

    Tristate C4008::compute(std::size_t pin)
    {
        nts::Tristate z1, z2, z3, z4;
        nts::Tristate sum1 = _adder(getLink(7), getLink(6), getLink(9), z1);
        nts::Tristate sum2 = _adder(getLink(5), getLink(4), z1, z2);
        nts::Tristate sum3 = _adder(getLink(3), getLink(2), z2, z3);
        nts::Tristate sum4 = _adder(getLink(1), getLink(15), z3, z4);

        switch (pin) {
            case 10:
                return sum1;
            case 11:
                return sum2;
            case 12:
                return sum3;
            case 13:
                return sum4;
            case 14:
                return z4;
            case 8:
            case 16:
                return nts::Tristate::Undefined;
            default:
                return getLink(pin);
        }
    }

    void nts::C4008::dump() const
    {
        std::cout << "Component: " << _name << " (4008 Adder)" << std::endl;
    }

}