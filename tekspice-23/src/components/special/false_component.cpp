/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** false_component
*/

#include "false_component.hpp"

nts::FalseComponent::FalseComponent(std::string const &name)
{
    this->_name = name;
    this->_type = "false";
    this->_value = nts::Tristate::False;
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::False;
}

void nts::FalseComponent::simulate(std::size_t tick) 
{
    (void)tick;
}

void nts::FalseComponent::dump() const
{
    std::cout << "False Component: " << _name << std::endl;
}