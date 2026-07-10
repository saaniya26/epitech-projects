/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** not_component
*/

#ifndef NOT_COMPONENT_HPP_
#define NOT_COMPONENT_HPP_

#include "AComponent.hpp"
#include <string>

namespace nts {
    class NotComponent : public AComponent {
    public:
        explicit NotComponent(const std::string &name);
        ~NotComponent() override = default;
        nts::Tristate compute(std::size_t pin) override;
        static nts::Tristate _not(nts::Tristate a);
        void dump() const override;
    };
}

#endif /* !NOT_COMPONENT_HPP_ */
