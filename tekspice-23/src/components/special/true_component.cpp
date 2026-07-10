/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** true_component
*/

#include "true_component.hpp"

nts::TrueComponent::TrueComponent(std::string const &name)
{
    this->_name = name;
    this->_type = "true";
    this->_value = nts::Tristate::True;
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::True;
}

void nts::TrueComponent::simulate(std::size_t tick) 
{
    (void)tick;
}

void nts::TrueComponent::dump() const
{
    std::cout << "True Component: " << _name << std::endl;
}