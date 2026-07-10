/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4081.hpp"
#include "and_component.hpp"

namespace nts {

    C4081::C4081(const std::string &name)
    {
        this->_name = name;
        this->_type = "4081";
    }

    void C4081::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate C4081::compute(std::size_t pin)
    {
        switch (pin) {
            case 3:
                return AndComponent::_and(getLink(1), getLink(2));
            case 4:
                return AndComponent::_and(getLink(5), getLink(6));
            case 10:
                return AndComponent::_and(getLink(8), getLink(9));
            case 11:
                return AndComponent::_and(getLink(12), getLink(13));
            case 7:
            case 14:
                return nts::Tristate::Undefined;
            default:
                return getLink(pin);
        }
    }

    void nts::C4081::dump() const
    {
        std::cout << "Component: " << _name << " (4081 AND)" << std::endl;
    }

}