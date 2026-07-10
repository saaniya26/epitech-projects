/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_

#include "IComponent.hpp"
#include <memory>
#include <string>
#include <map>

namespace nts
{
    class Circuit {
        public:
            Circuit() = default;
            ~Circuit() = default;
            void addComponent(const std::string &name, std::unique_ptr<IComponent> component);
            IComponent *getComponent(const std::string &name);
            const std::map<std::string, std::unique_ptr<IComponent>> &getComponents() const;
            std::map<std::string, std::unique_ptr<IComponent>> &getComponents();
            void simulate(std::size_t tick);
            void display() const;
        private:
            std::map<std::string, std::unique_ptr<IComponent>> _components;
    };
}

#endif