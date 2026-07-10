/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4512
*/

#include "c4512.hpp"

namespace nts {

    C4512::C4512(const std::string &name) : AComponent(name)
    {
    }

    std::size_t C4512::getDataPin(std::size_t index) const
    {
        switch (index) {
            case 0:
                return 1;
            case 1:
                return 2;
            case 2:
                return 3;
            case 3:
                return 4;
            case 4:
                return 5;
            case 5:
                return 6;
            case 6:
                return 7;
            case 7:
                return 9;
            default:
                return 0;
        }
    }

    static std::size_t addressToIndex(nts::Tristate a, nts::Tristate b, nts::Tristate c)
    {
        std::size_t index = 0;

        if (a == nts::Tristate::True)
            index += 1;
        if (b == nts::Tristate::True)
            index += 2;
        if (c == nts::Tristate::True)
            index += 4;
        return index;
    }

    nts::Tristate C4512::compute(std::size_t pin)
    {
        if (pin == 8 || pin == 16)
            return nts::Tristate::Undefined;
        if (pin != 14)
            return getLink(pin);

        nts::Tristate inhibit = getLink(10);
        nts::Tristate enable = getLink(15);

        if (enable == nts::Tristate::Undefined || inhibit == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        if (enable != nts::Tristate::False)
            return nts::Tristate::Undefined;
        if (inhibit == nts::Tristate::True)
            return nts::Tristate::False;

        nts::Tristate a = getLink(11);
        nts::Tristate b = getLink(12);
        nts::Tristate c = getLink(13);
        if (a == nts::Tristate::Undefined ||
            b == nts::Tristate::Undefined ||
            c == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        std::size_t index = addressToIndex(a, b, c);
        std::size_t dataPin = getDataPin(index);
        return getLink(dataPin);
    }

    void C4512::dump() const
    {
        std::cout << "Component: " << _name << " (4512 Selector)" << std::endl;
    }

}
