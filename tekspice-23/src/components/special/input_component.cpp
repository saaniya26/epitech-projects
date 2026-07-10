/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** input_component
*/

#include "input_component.hpp"

nts::InputComponent::InputComponent(std::string const &name)
{
    this->_name = name;
    this->_type = "input";
    this->_value = nts::Tristate::Undefined;
    this->_last = nts::Tristate::Undefined;
    this->_newValue = false;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (_newValue) {
        _value = _last;
        _newValue = false;
    }
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    _last = value;
    _newValue = true;
}

nts::Tristate nts::InputComponent::getValue() const
{
    return _value;
}

void nts::InputComponent::dump() const
{
    std::cout << "Input Component: " << _name << std::endl;
}