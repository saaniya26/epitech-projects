/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** output_component
*/

#include "output_component.hpp"

nts::OutputComponent::OutputComponent(std::string const &name)
{
    this->_name = name;
    this->_type = "output";
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        return getLink(1); 
    }
    return nts::Tristate::Undefined;
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    (void)tick;
}


nts::Tristate nts::OutputComponent::getValue() const
{
    return const_cast<OutputComponent*>(this)->compute(1);
}

void nts::OutputComponent::dump() const
{
    std::cout << "Output Component: " << _name << std::endl;
}