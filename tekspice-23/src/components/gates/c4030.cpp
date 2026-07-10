/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4030.hpp"
#include "xor_component.hpp"

namespace nts {

    C4030::C4030(const std::string &name)
    {
        this->_name = name;
        this->_type = "4030";
    }

    void C4030::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate C4030::compute(std::size_t pin)
    {
        switch (pin) {
            case 3:
                return XorComponent::_xor(getLink(1), getLink(2));
            case 4:
                return XorComponent::_xor(getLink(5), getLink(6));
            case 10:
                return XorComponent::_xor(getLink(8), getLink(9));
            case 11:
                return XorComponent::_xor(getLink(12), getLink(13));
            case 7:
            case 14:
                return nts::Tristate::Undefined;
            default:
                return getLink(pin);
        }
    }

    void nts::C4030::dump() const
    {
        std::cout << "Component: " << _name << " (4030 XOR)" << std::endl;
    }

}