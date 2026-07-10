/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4040
*/

#include "c4040.hpp"

namespace nts {
    static bool resetState(nts::Tristate reset, nts::Tristate clock,
        std::uint16_t &value, bool &defined, nts::Tristate &lastClock)
    {
        if (reset == nts::Tristate::True) {
            value = 0;
            defined = true;
            lastClock = clock;
            return true;
        }
        if (reset == nts::Tristate::Undefined) {
            defined = false;
            lastClock = clock;
            return true;
        }
        return false;
    }

    static nts::Tristate readCounter(std::uint16_t value, std::size_t bit)
    {
        std::uint16_t mask = static_cast<std::uint16_t>(1U << bit);

        if ((value & mask) != 0)
            return nts::Tristate::True;
        return nts::Tristate::False;
    }

    C4040::C4040(const std::string &name) : AComponent(name)
    {
        _value = 0;
        _defined = false;
        _clock = nts::Tristate::Undefined;
    }

    std::size_t C4040::getBitIndex(std::size_t pin) const
    {
        switch (pin) {
            case 9:
                return 0;
            case 7:
                return 1;
            case 6:
                return 2;
            case 5:
                return 3;
            case 3:
                return 4;
            case 2:
                return 5;
            case 4:
                return 6;
            case 13:
                return 7;
            case 12:
                return 8;
            case 14:
                return 9;
            case 15:
                return 10;
            case 1:
                return 11;
            default:
                return 42;
        }
    }

    void C4040::simulate(std::size_t tick)
    {
        (void)tick;
        nts::Tristate reset = getLink(11);
        nts::Tristate clock = getLink(10);

        if (resetState(reset, clock, _value, _defined, _clock))
            return;
        if (_clock == nts::Tristate::True && clock == nts::Tristate::False) {
            if (!_defined) {
                _value = 0;
                _defined = true;
            } else {
                _value = static_cast<std::uint16_t>((_value + 1) & 0x0FFF);
            }
        }
        _clock = clock;
    }

    nts::Tristate C4040::compute(std::size_t pin)
    {
        std::size_t bit = getBitIndex(pin);

        if (pin == 8 || pin == 16)
            return nts::Tristate::Undefined;
        if (bit != 42) {
            if (!_defined)
                return nts::Tristate::Undefined;
            return readCounter(_value, bit);
        }
        return getLink(pin);
    }

    void C4040::dump() const
    {
        std::cout << "Component: " << _name << " (4040 Counter)" << std::endl;
    }

}
