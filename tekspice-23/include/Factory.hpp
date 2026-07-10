/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

#include "IComponent.hpp"
#include <memory>
#include <string>

namespace nts
{
    class Factory {
        public:
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &name);
    };
}

#endif