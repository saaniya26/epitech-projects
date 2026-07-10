/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4801
*/

#include "c4801.hpp"

namespace nts {

    static const std::size_t ADDR_PINS[] = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22};
    static const std::size_t DATA_PINS[] = {9, 10, 11, 13, 14, 15, 16, 17};

    C4801::C4801(const std::string &name) : AComponent(name)
    {
        _memory.resize(1024, 0);
    }

    std::size_t C4801::getDataBitIndex(std::size_t pin) const
    {
        for (std::size_t i = 0; i < 8; i++) {
            if (DATA_PINS[i] == pin)
                return i;
        }
        return 42;
    }

    std::size_t C4801::getAddress() const
    {
        std::size_t addr = 0;

        for (std::size_t i = 0; i < 10; i++) {
            nts::Tristate bit = const_cast<C4801 *>(this)->getLink(ADDR_PINS[i]);
            if (bit == nts::Tristate::True)
                addr |= (1U << i);
        }
        return addr;
    }

    void C4801::simulate(std::size_t tick)
    {
        (void)tick;
        nts::Tristate enable = getLink(18);
        nts::Tristate write = getLink(21);

        if (enable != nts::Tristate::False)
            return;
        if (write != nts::Tristate::False)
            return;

        for (std::size_t i = 0; i < 10; i++) {
            nts::Tristate bit = getLink(ADDR_PINS[i]);
            if (bit == nts::Tristate::Undefined)
                return;
        }

        std::size_t addr = getAddress();
        std::uint8_t byte = 0;

        for (std::size_t i = 0; i < 8; i++) {
            nts::Tristate val = getLink(DATA_PINS[i]);
            if (val == nts::Tristate::True)
                byte |= static_cast<std::uint8_t>(1U << i);
        }
        _memory[addr] = byte;
    }

    nts::Tristate C4801::compute(std::size_t pin)
    {
        std::size_t bit = getDataBitIndex(pin);

        if (bit == 42)
            return getLink(pin);

        nts::Tristate enable = getLink(18);
        nts::Tristate read = getLink(20);

        if (enable != nts::Tristate::False)
            return nts::Tristate::Undefined;
        if (read != nts::Tristate::False)
            return nts::Tristate::Undefined;

        for (std::size_t i = 0; i < 10; i++) {
            nts::Tristate addrBit = getLink(ADDR_PINS[i]);
            if (addrBit == nts::Tristate::Undefined)
                return nts::Tristate::Undefined;
        }

        std::size_t addr = getAddress();

        if ((_memory[addr] >> bit) & 1U)
            return nts::Tristate::True;
        return nts::Tristate::False;
    }

    void C4801::dump() const
    {
        std::cout << "Component: " << _name << " (4801 RAM)" << std::endl;
    }

}
