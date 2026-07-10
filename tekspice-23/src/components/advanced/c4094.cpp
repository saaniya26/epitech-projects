
/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** C4094 - 8-bit shift register
*/

#include "c4094.hpp"

namespace nts {

    C4094::C4094(const std::string &name) : AComponent(name), _reg(), _last(nts::Tristate::False)
    {
        for (auto &b : _reg) {
            b = nts::Tristate::Undefined;
        }
    }

    void C4094::simulate(std::size_t tick)
    {
        (void)tick;

        nts::Tristate data   = getLink(2);
        nts::Tristate clock  = getLink(3);
        bool rising = (_last == nts::Tristate::False && clock == nts::Tristate::True);
        if (rising) {
            for (int i = 7; i > 0; --i) {
                _reg[i] = _reg[i - 1];
            }
            _reg[0] = data;
        }
        _last = clock;
    }

    nts::Tristate C4094::compute(std::size_t pin)
    {
        switch (pin) {
            case 4:  
                return _reg[0];
            case 5:  
                return _reg[1];
            case 6:  
                return _reg[2];
            case 7:  
                return _reg[3];
            case 14: 
                return _reg[4];
            case 13: 
                return _reg[5];
            case 12: 
                return _reg[6];
            case 11: 
                return _reg[7];
            case 9:
                return _reg[7];
            default:
                return nts::Tristate::Undefined;
        }
    }

    void C4094::dump() const
    {
        std::cout << "Component: " << _name << " (4094 shift)\n  reg: ";
        for (int i = 7; i >= 0; --i) {
            char c = 'U';
            if (_reg[i] == nts::Tristate::True) {
                c = '1';
            } else if (_reg[i] == nts::Tristate::False) {
                c = '0';
            }
            std::cout << c;
        }
        std::cout << std::endl;
    }
}