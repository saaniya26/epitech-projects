/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4001.hpp"
#include "not_component.hpp"
#include "or_component.hpp"

namespace nts {

    C4001::C4001(const std::string &name)
    {
        this->_name = name;
        this->_type = "4001";
    }

    void C4001::simulate(std::size_t tick)
    {
        (void)tick;
    }

    nts::Tristate C4001::compute(std::size_t pin)
    {
        if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
            if (_computing.find(pin) != _computing.end()) {
                auto it = _last.find(pin);
                if (it != _last.end())
                    return it->second;
                return nts::Tristate::Undefined;
            }
            _computing.insert(pin);
        }

        nts::Tristate result = nts::Tristate::Undefined;

        switch (pin) {
            case 3:
                result = NotComponent::_not(OrComponent::_or(getLink(1), getLink(2)));
                break;
            case 4:
                result = NotComponent::_not(OrComponent::_or(getLink(5), getLink(6)));
                break;
            case 10:
                result = NotComponent::_not(OrComponent::_or(getLink(8), getLink(9)));
                break;
            case 11:
                result = NotComponent::_not(OrComponent::_or(getLink(12), getLink(13)));
                break;
            case 7:
            case 14:
                result = nts::Tristate::Undefined;
                break;
            default:
                result = getLink(pin);
                break;
        }

        if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
            _last[pin] = result;
            _computing.erase(pin);
        }

        return result;
    }

    void nts::C4001::dump() const
    {
        std::cout << "Component: " << _name << " (4001 NOR)" << std::endl;
    }
}