/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** input_component
*/

#ifndef INPUT_COMPONENT_HPP_
#define INPUT_COMPONENT_HPP_

#include "AComponent.hpp"
#include <iostream>

namespace nts {
    class InputComponent : public AComponent {
        public:
            InputComponent();
            ~InputComponent() override = default;
            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override;
            void setValue(nts::Tristate value);
            nts::Tristate getValue() const;
            void dump() const override;
            explicit InputComponent(const std::string &name);
        private:
            std::string _type;
            nts::Tristate _value;
            nts::Tristate _last;
            bool _newValue;

    };
}

#endif /* !INPUT_COMPONENT_HPP_ */
