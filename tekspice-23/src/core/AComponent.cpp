/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"
#include <stdexcept>

namespace nts 
{
    AComponent::AComponent(const std::string &name) : _name(name)
    {
    }

    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        _links[pin].push_back({&other, otherPin});
    }

    nts::Tristate AComponent::getLink(std::size_t pin)
    {
        auto it = _links.find(pin);
        if (it != _links.end() && !it->second.empty()) {
            const auto &link = it->second[0];
            if (link.first) {
                return link.first->compute(link.second);
            }
        }
        return nts::Tristate::Undefined;
    }
}
