/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4514
*/

#include "c4514.hpp"

namespace nts {

    C4514::C4514(const std::string &name): AComponent(name)
    {
    }

    void C4514::simulate(std::size_t tick)
    {
        (void)tick;
    }
    
    nts::Tristate C4514::compute(std::size_t pin)
    {
        int sel = 0;

        if (pin < 7 || pin > 22) {
            return nts::Tristate::Undefined;
        }
        nts::Tristate a0 = getLink(1);
        nts::Tristate a1 = getLink(2);
        nts::Tristate a2 = getLink(3);
        nts::Tristate a3 = getLink(4);
        nts::Tristate strobe  = getLink(5);
        nts::Tristate inhibit = getLink(6);
        if (inhibit == nts::Tristate::True) {
            return nts::Tristate::False;
        }
        if (strobe == nts::Tristate::True) {
            return nts::Tristate::False;
        }
        if (a0 == nts::Tristate::Undefined || a1 == nts::Tristate::Undefined 
        || a2 == nts::Tristate::Undefined || a3 == nts::Tristate::Undefined) {
            return nts::Tristate::Undefined;
        }
        if (a0 == nts::Tristate::True) {
            sel += 1;
        }
        if (a1 == nts::Tristate::True) {
            sel += 2;
        }
        if (a2 == nts::Tristate::True) {
            sel += 4;
        }
        if (a3 == nts::Tristate::True) {
            sel += 8;
        }
        int outIndex = static_cast<int>(pin) - 7;
        return (outIndex == sel ? nts::Tristate::True : nts::Tristate::False);
    }

    void C4514::dump() const
    {
        std::cout << "Component: " << _name << " (4514 decoder)" << std::endl;
    }
}