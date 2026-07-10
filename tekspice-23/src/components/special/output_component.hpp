/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** output_component
*/

#ifndef OUTPUT_COMPONENT_HPP_
#define OUTPUT_COMPONENT_HPP_

#include "AComponent.hpp"
#include <iostream>

namespace nts {
    class OutputComponent : public AComponent {
        public:
            OutputComponent();
            ~OutputComponent() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getValue() const;
            void dump() const override;
            explicit OutputComponent(const std::string &name);
        private:
            std::string _type;
            nts::Tristate _value;

    };
}

#endif /* !OUTPUT_COMPONENT_HPP_ */
