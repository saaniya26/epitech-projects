/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4011.hpp"
#include "not_component.hpp"
#include "and_component.hpp"

namespace nts {

    C4011::C4011(const std::string &name)
    {
        this->_name = name;
        this->_type = "4011";
    }

    void C4011::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate C4011::compute(std::size_t pin)
    {
        switch (pin) {
            case 3:
                return NotComponent::_not(AndComponent::_and(getLink(1), getLink(2)));
            case 4:
                return NotComponent::_not(AndComponent::_and(getLink(5), getLink(6)));
            case 10:
                return NotComponent::_not(AndComponent::_and(getLink(8), getLink(9)));
            case 11:
                return NotComponent::_not(AndComponent::_and(getLink(12), getLink(13)));
            case 7:
            case 14:
                return nts::Tristate::Undefined;
            default:
                return getLink(pin);
        }
    }

    void nts::C4011::dump() const
    {
        std::cout << "Component: " << _name << " (4011 NAND)" << std::endl;
    }

}