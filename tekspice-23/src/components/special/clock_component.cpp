/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** clock_component
*/

#include "clock_component.hpp"

nts::ClockComponent::ClockComponent(std::string const &name)
{
    this->_name = name;
    this->_type = "clock";
    this->_value = nts::Tristate::Undefined;
    this->_last = nts::Tristate::Undefined;
    this->_newValue = false;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (_newValue) {
        _value = _last;
        _newValue = false;
        return;
    }
    if (_value == nts::Tristate::True)
        _value = nts::Tristate::False;
    else if (_value == nts::Tristate::False)
        _value = nts::Tristate::True;
}

void nts::ClockComponent::setValue(nts::Tristate value)
{
    _last = value;
    _newValue = true;
}

nts::Tristate nts::ClockComponent::getValue() const
{
    return _value;
}

void nts::ClockComponent::dump() const
{
    std::cout << "Clock Component: " << _name << std::endl;
}