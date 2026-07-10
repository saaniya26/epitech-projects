/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** false_component
*/

#ifndef FALSE_COMPONENT_HPP_
#define FALSE_COMPONENT_HPP_

#include "AComponent.hpp"
#include <iostream>

namespace nts {
    class FalseComponent : public AComponent {
        public:
            explicit FalseComponent(const std::string &name);
            FalseComponent() = default; 
            ~FalseComponent() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void dump() const override;
        private:
            std::string _type;
            nts::Tristate _value;

    };
}

#endif /* !FALSE_COMPONENT_HPP_ */
