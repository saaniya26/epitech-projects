/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** graph_builder
*/

#include "graph_builder.hpp"
#include "IComponent.hpp"
#include <stdexcept>

void nts::buildGraph(ComponentMap &components, const std::vector<Link> &links)
{
    for (const Link &link : links) {
        if (link.fromPin == 0 || link.toPin == 0)
            throw std::runtime_error("Pins are 1-based, pin 0 is invalid.");
        auto fromIt = components.find(link.fromName);
        auto toIt = components.find(link.toName);

        if (fromIt == components.end())
            throw std::runtime_error("Unknown component name '" + link.fromName + "'.");
        if (toIt == components.end())
            throw std::runtime_error("Unknown component name '" + link.toName + "'.");
        if (!fromIt->second || !toIt->second)
            throw std::runtime_error("Cannot link null component pointer.");
        fromIt->second->setLink(link.fromPin, *toIt->second, link.toPin);
        toIt->second->setLink(link.toPin, *fromIt->second, link.fromPin);
    }
}

void nts::simulateTick(ComponentMap &components, std::size_t tick)
{
    for (const auto &[name, component] : components) {
        (void)name;
        if (!component)
            throw std::runtime_error("Cannot simulate null component pointer.");
        component->simulate(tick);
    }
}