/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include <map>
#include <utility>
#include <string>
#include <vector>

namespace nts
{
    class AComponent : public IComponent {
    public:
        explicit AComponent(const std::string &name); 
        AComponent() = default;
        ~AComponent() override = default;
        nts::Tristate compute(std::size_t pin) override = 0;
        void simulate(std::size_t tick) override { (void)tick; }
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin);
    protected:
        std::map<std::size_t, std::vector<std::pair<nts::IComponent *, std::size_t>>> _links;
        std::string _name;
    };
}

#endif /* !ACOMPONENT_HPP_ */