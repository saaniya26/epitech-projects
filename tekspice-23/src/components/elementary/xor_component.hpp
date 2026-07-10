#ifndef XOR_COMPONENT_HPP_
#define XOR_COMPONENT_HPP_

#include "AComponent.hpp"
#include <string>

namespace nts {
    class XorComponent : public AComponent {
    public:
        explicit XorComponent(const std::string &name);
        ~XorComponent() override = default;
        nts::Tristate compute(std::size_t pin) override;
        static nts::Tristate _xor(nts::Tristate a, nts::Tristate b);
        void dump() const override;
    };
}

#endif /* !XOR_COMPONENT_HPP_ */
