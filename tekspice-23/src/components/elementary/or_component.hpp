#ifndef OR_COMPONENT_HPP_
#define OR_COMPONENT_HPP_

#include "AComponent.hpp"
#include <string>

namespace nts {
    class OrComponent : public AComponent {
    public:
        explicit OrComponent(const std::string &name);
        ~OrComponent() override = default;
        nts::Tristate compute(std::size_t pin) override;
        static nts::Tristate _or(nts::Tristate a, nts::Tristate b);
        void dump() const override;
    };
}

#endif /* !OR_COMPONENT_HPP_ */
