/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** c4013
*/

#include "c4013.hpp"

namespace nts {

    C4013::C4013(const std::string &name) : AComponent(name)
    {
        _q1 = nts::Tristate::Undefined;
        _qb1 = nts::Tristate::Undefined;
        _q2 = nts::Tristate::Undefined;
        _qb2 = nts::Tristate::Undefined;
        _clock1 = nts::Tristate::Undefined;
        _clock2 = nts::Tristate::Undefined;
    }

    void C4013::simulate(std::size_t tick)
    {
        (void)tick;
        nts::Tristate clock1 = getLink(3);
        nts::Tristate data1 = getLink(5);
        nts::Tristate set1 = getLink(6);
        nts::Tristate reset1 = getLink(4);

        if (set1 == nts::Tristate::True && reset1 == nts::Tristate::False) {
            _q1 = nts::Tristate::True;
            _qb1 = nts::Tristate::False;
        } else if (set1 == nts::Tristate::False && reset1 == nts::Tristate::True) {
            _q1 = nts::Tristate::False;
            _qb1 = nts::Tristate::True;
        } else if (set1 == nts::Tristate::True && reset1 == nts::Tristate::True) {
            _q1 = nts::Tristate::True;
            _qb1 = nts::Tristate::True;
        } else if (set1 == nts::Tristate::Undefined || reset1 == nts::Tristate::Undefined) {
            _q1 = nts::Tristate::Undefined;
            _qb1 = nts::Tristate::Undefined;
        } else if (_clock1 == nts::Tristate::False && clock1 == nts::Tristate::True) {
            _q1 = data1;
            if (data1 == nts::Tristate::True)
                _qb1 = nts::Tristate::False;
            else if (data1 == nts::Tristate::False)
                _qb1 = nts::Tristate::True;
            else
                _qb1 = nts::Tristate::Undefined;
        }
        _clock1 = clock1;

        nts::Tristate clock2 = getLink(11);
        nts::Tristate data2 = getLink(9);
        nts::Tristate set2 = getLink(8);
        nts::Tristate reset2 = getLink(10);

        if (set2 == nts::Tristate::True && reset2 == nts::Tristate::False) {
            _q2 = nts::Tristate::True;
            _qb2 = nts::Tristate::False;
        } else if (set2 == nts::Tristate::False && reset2 == nts::Tristate::True) {
            _q2 = nts::Tristate::False;
            _qb2 = nts::Tristate::True;
        } else if (set2 == nts::Tristate::True && reset2 == nts::Tristate::True) {
            _q2 = nts::Tristate::True;
            _qb2 = nts::Tristate::True;
        } else if (set2 == nts::Tristate::Undefined || reset2 == nts::Tristate::Undefined) {
            _q2 = nts::Tristate::Undefined;
            _qb2 = nts::Tristate::Undefined;
        } else if (_clock2 == nts::Tristate::False && clock2 == nts::Tristate::True) {
            _q2 = data2;
            if (data2 == nts::Tristate::True)
                _qb2 = nts::Tristate::False;
            else if (data2 == nts::Tristate::False)
                _qb2 = nts::Tristate::True;
            else
                _qb2 = nts::Tristate::Undefined;
        }
        _clock2 = clock2;
    }

    nts::Tristate C4013::compute(std::size_t pin)
    {
        nts::Tristate set1 = getLink(6);
        nts::Tristate reset1 = getLink(4);
        nts::Tristate set2 = getLink(8);
        nts::Tristate reset2 = getLink(10);

        switch (pin) {
            case 1:
                if (set1 == nts::Tristate::True && reset1 == nts::Tristate::False)
                    return nts::Tristate::True;
                if (set1 == nts::Tristate::False && reset1 == nts::Tristate::True)
                    return nts::Tristate::False;
                if (set1 == nts::Tristate::True && reset1 == nts::Tristate::True)
                    return nts::Tristate::True;
                if (set1 == nts::Tristate::Undefined || reset1 == nts::Tristate::Undefined)
                    return nts::Tristate::Undefined;
                return _q1;
            case 2:
                if (set1 == nts::Tristate::True && reset1 == nts::Tristate::False)
                    return nts::Tristate::False;
                if (set1 == nts::Tristate::False && reset1 == nts::Tristate::True)
                    return nts::Tristate::True;
                if (set1 == nts::Tristate::True && reset1 == nts::Tristate::True)
                    return nts::Tristate::True;
                if (set1 == nts::Tristate::Undefined || reset1 == nts::Tristate::Undefined)
                    return nts::Tristate::Undefined;
                return _qb1;
            case 12:
                if (set2 == nts::Tristate::True && reset2 == nts::Tristate::False)
                    return nts::Tristate::False;
                if (set2 == nts::Tristate::False && reset2 == nts::Tristate::True)
                    return nts::Tristate::True;
                if (set2 == nts::Tristate::True && reset2 == nts::Tristate::True)
                    return nts::Tristate::True;
                if (set2 == nts::Tristate::Undefined || reset2 == nts::Tristate::Undefined)
                    return nts::Tristate::Undefined;
                return _qb2;
            case 13:
                if (set2 == nts::Tristate::True && reset2 == nts::Tristate::False)
                    return nts::Tristate::True;
                if (set2 == nts::Tristate::False && reset2 == nts::Tristate::True)
                    return nts::Tristate::False;
                if (set2 == nts::Tristate::True && reset2 == nts::Tristate::True)
                    return nts::Tristate::True;
                if (set2 == nts::Tristate::Undefined || reset2 == nts::Tristate::Undefined)
                    return nts::Tristate::Undefined;
                return _q2;
            case 7:
            case 14:
                return nts::Tristate::Undefined;
            default:
                return getLink(pin);
        }
    }

    void C4013::dump() const
    {
        std::cout << "Component: " << _name << " (4013 Flip-Flop)" << std::endl;
    }

}
