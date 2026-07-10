/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "c4017.hpp"

namespace nts
{
    C4017::C4017(const std::string &name) : AComponent(name)
    {
        _counter = 0;
        _last = nts::Tristate::False;
    }

    void C4017::simulate(std::size_t tick)
    {
        (void)tick;

        nts::Tristate clock = getLink(14);
        nts::Tristate reset = getLink(15);
        nts::Tristate inhibit = getLink(13);
        bool inhibit_on = (inhibit == nts::Tristate::True);
        bool rising_edge = (_last == nts::Tristate::False && clock == nts::Tristate::True);
        if (reset == nts::Tristate::True) {
            _counter = 0;
        } else if (!inhibit_on && rising_edge) {
            _counter++;
            if (_counter > 9) {
                _counter = 0;
            }
        }
        _last = clock;
    }

    nts::Tristate C4017::compute(std::size_t pin)
    {
        switch (pin) {
            case 3:  
                return (_counter == 0 ? nts::Tristate::True : nts::Tristate::False);
            case 2:  
                return (_counter == 1 ? nts::Tristate::True : nts::Tristate::False);
            case 4:  
                return (_counter == 2 ? nts::Tristate::True : nts::Tristate::False);
            case 7:  
                return (_counter == 3 ? nts::Tristate::True : nts::Tristate::False);
            case 10: 
                return (_counter == 4 ? nts::Tristate::True : nts::Tristate::False);
            case 1:  
                return (_counter == 5 ? nts::Tristate::True : nts::Tristate::False);
            case 5: 
                return (_counter == 6 ? nts::Tristate::True : nts::Tristate::False);
            case 6:  
                return (_counter == 7 ? nts::Tristate::True : nts::Tristate::False);
            case 9:  
                return (_counter == 8 ? nts::Tristate::True : nts::Tristate::False);
            case 11: 
                return (_counter == 9 ? nts::Tristate::True : nts::Tristate::False);
            case 12:
                return (_counter <= 4 ? nts::Tristate::True : nts::Tristate::False);
            default:
                return nts::Tristate::Undefined;
        }
    }

    void C4017::dump() const
    {
        std::cout << "Component: " << _name << " (4017 Johnson counter, state=" << _counter << ")" << std::endl;
    }
}