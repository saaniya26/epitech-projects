/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4069.hpp"
#include "not_component.hpp"

namespace nts {

    C4069::C4069(const std::string &name)
    {
        this->_name = name;
        this->_type = "4069";
    }

    void C4069::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate C4069::compute(std::size_t pin)
    {
        switch (pin) {
            case 2:
                return NotComponent::_not(getLink(1));
            case 4:
                return NotComponent::_not(getLink(3));
            case 6:
                return NotComponent::_not(getLink(5));
            case 8:
                return NotComponent::_not(getLink(9));
            case 10:
                return NotComponent::_not(getLink(11));
            case 12:
                return NotComponent::_not(getLink(13));
            case 7:
            case 14:
                return nts::Tristate::Undefined;
            default:
                return getLink(pin);
        }
    }

    void nts::C4069::dump() const
    {
        std::cout << "Component: " << _name << " (4069 NOT)" << std::endl;
    }

}