/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** true_component
*/

#ifndef TRUE_COMPONENT_HPP_
#define TRUE_COMPONENT_HPP_

#include "AComponent.hpp"
#include <iostream>

namespace nts {
    class TrueComponent: public AComponent {
        public:
            TrueComponent();
            ~TrueComponent() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void dump() const override;
            explicit TrueComponent(const std::string &name);
        private:
            std::string _type;
            nts::Tristate _value;
    };
}

#endif /* !TRUE_COMPONENT_HPP_ */
