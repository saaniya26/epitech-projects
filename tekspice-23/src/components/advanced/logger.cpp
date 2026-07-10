/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** logger
*/

#include "logger.hpp"
#include <fstream>

namespace nts {

    Logger::Logger(const std::string &name) : AComponent(name)
    {
        _last = nts::Tristate::Undefined;
    }

    void Logger::simulate(std::size_t tick)
    {
        (void)tick;
        nts::Tristate clock = getLink(9);
        nts::Tristate inhibit = getLink(10);
    
        if (inhibit != nts::Tristate::False) {
            _last = clock;
            return;
        }
        if (_last != nts::Tristate::False || clock != nts::Tristate::True) {
            _last = clock;
            return;
        }
        _last = clock;
        char byte = 0;
        for (std::size_t i = 0; i < 8; i++) {
            nts::Tristate bit = getLink(i + 1);
            if (bit == nts::Tristate::Undefined) {
                return;
            }
            if (bit == nts::Tristate::True)
                byte |= static_cast<char>(1 << i);
        }
        std::ofstream file("./log.bin", std::ios::binary | std::ios::app);
        file.write(&byte, 1);
    }

    nts::Tristate Logger::compute(std::size_t pin)
    {
        return getLink(pin);
    }

    void Logger::dump() const
    {
        std::cout << "Component: " << _name << " (Logger)" << std::endl;
    }

}
