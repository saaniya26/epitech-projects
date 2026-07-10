/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4071.hpp"
#include "or_component.hpp"

namespace nts {

    C4071::C4071(const std::string &name)
    {
        this->_name = name;
        this->_type = "4071";
    }

    void C4071::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate C4071::compute(std::size_t pin)
    {
        switch (pin) {
            case 3:
                return OrComponent::_or(getLink(1), getLink(2));
            case 4:
                return OrComponent::_or(getLink(5), getLink(6));
            case 10:
                return OrComponent::_or(getLink(8), getLink(9));
            case 11:
                return OrComponent::_or(getLink(12), getLink(13));
            case 7:
            case 14:
                return nts::Tristate::Undefined;
            default:
                return getLink(pin);
        }
    }

    void nts::C4071::dump() const
    {
        std::cout << "Component: " << _name << " (4071 OR)" << std::endl;
    }
}