/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "Circuit.hpp"
#include "input_component.hpp"
#include "clock_component.hpp"
#include <map>
#include <iostream>
#include <stdexcept>

namespace nts 
{
    void Circuit::addComponent(const std::string &name, std::unique_ptr<IComponent> component)
    {
        if (name.empty()) {
            throw std::runtime_error("empty name");
        }
        if (component == nullptr) {
            throw std::runtime_error("null component");
        }
        if (_components.find(name) != _components.end()) {
            throw std::runtime_error("Component name already exists");
        }
        _components[name] = std::move(component);
    }

    IComponent *Circuit::getComponent(const std::string &name)
    {
        auto i = _components.find(name);
        if (i == _components.end()) {
            throw std::runtime_error("Unknown component name: " + name);
        }
        return i->second.get();
    }

    const std::map<std::string, std::unique_ptr<IComponent>> &Circuit::getComponents() const
    {
        return _components;
    }

    std::map<std::string, std::unique_ptr<IComponent>> &Circuit::getComponents()
    {
        return _components;
    }

    void Circuit::simulate(std::size_t tick)
    {
        for (auto &it : _components) {
            IComponent *component = it.second.get();

            if (dynamic_cast<InputComponent *>(component) != nullptr ||
                dynamic_cast<ClockComponent *>(component) != nullptr) {
                component->simulate(tick);
            }
        }
        for (auto &it : _components) {
            IComponent *component = it.second.get();

            if (dynamic_cast<InputComponent *>(component) == nullptr &&
                dynamic_cast<ClockComponent *>(component) == nullptr) {
                component->simulate(tick);
            }
        }
    }

    void Circuit::display() const
    {
        std::map<std::string, std::unique_ptr<IComponent>>::const_iterator i;

        i = _components.begin();
        while (i != _components.end()) {
            i->second->dump();
            i++;
        }
    }
}