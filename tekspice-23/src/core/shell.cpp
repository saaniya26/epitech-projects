/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** shell
*/

#include "Shell.hpp"
#include "input_component.hpp"
#include "output_component.hpp"
#include "clock_component.hpp"
#include <iostream>
#include <cctype>
#include <stdexcept>

namespace nts {

Shell::Shell(Circuit &circuit)
    : _circuit(circuit), _tick(0)
{
}

static std::string trim(const std::string &value)
{
    std::size_t start = 0;
    std::size_t end = value.size();

    while (start < end && std::isspace(static_cast<unsigned char>(value[start])))
        start++;
    while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1])))
        end--;
    return value.substr(start, end - start);
}

static char tristateToChar(nts::Tristate value)
{
    if (value == nts::Tristate::True)
        return '1';
    if (value == nts::Tristate::False)
        return '0';
    return 'U';
}

void Shell::run()
{
    std::string line;

    while (true) {
            std::cout << "> ";
        if (!std::getline(std::cin, line))
            break;
        line = trim(line);
        if (line.empty())
            continue;
        if (!executeCommand(line))
            break;
    }
}

bool Shell::executeCommand(const std::string& line)
{
    if (line == "exit")
        return false;
    if (line == "display") {
        cmdDisplay();
        return true;
    }
    if (line == "simulate") {
        cmdSimulate();
        return true;
    }
    if (line == "loop") {
        cmdLoop();
        return true;
    }
    if (assignment(line))
        return true;
    std::cerr << "Unknown command: " << line << std::endl;
    return true;
}

bool Shell::assignment(const std::string& line)
{
    std::size_t pos = line.find('=');

    if (pos == std::string::npos)
        return false;
    std::string name = trim(line.substr(0, pos));
    std::string value = trim(line.substr(pos + 1));
    if (name.empty() || value.empty()) {
        std::cerr << "Invalid assignment syntax" << std::endl;
        return true;
    }
    cmdAssign(name, value);
    return true;
}

void Shell::cmdDisplay() const
{
    std::cout << "tick: " << _tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (const auto& [name, comp] : _circuit.getComponents()) {
        if (dynamic_cast<const nts::InputComponent *>(comp.get()) ||
            dynamic_cast<const nts::ClockComponent *>(comp.get()))
            std::cout << "  " << name << ": " << tristateToChar(comp->compute(1)) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (const auto& [name, comp] : _circuit.getComponents()) {
        if (dynamic_cast<const nts::OutputComponent *>(comp.get()))
            std::cout << "  " << name << ": " << tristateToChar(comp->compute(1)) << std::endl;
    }
}

void Shell::cmdSimulate()
{
    _circuit.simulate(++_tick);
}

void Shell::cmdAssign(const std::string& name, const std::string& value)
{
    nts::IComponent *component = nullptr;

    try {
        component = _circuit.getComponent(name);
    } catch (const std::runtime_error &) {
        std::cerr << "Unknown input: " << name << std::endl;
        return;
    }

    auto input = dynamic_cast<nts::InputComponent*>(component);
    auto clock = dynamic_cast<nts::ClockComponent*>(component);

    if (!input && !clock) {
        std::cerr << "Component " << name << " is not an input/clock." << std::endl;
        return;
    }

    nts::Tristate state = nts::Tristate::Undefined;

    if (value == "1")
        state = nts::Tristate::True;
    else if (value == "0")
        state = nts::Tristate::False;
    else if (value != "U" && value != "u") {
        std::cerr << "Invalid value: " << value << " (expected 0, 1 or U)" << std::endl;
        return;
    }

    if (input)
        input->setValue(state);
    if (clock)
        clock->setValue(state);
}

static volatile sig_atomic_t g_stopLoop = 0;

static void signalHandler(int)
{
    g_stopLoop = 1;
}

void nts::Shell::cmdLoop() {
    g_stopLoop = 0;
    std::signal(SIGINT, signalHandler);
    while (!g_stopLoop) {
        cmdSimulate();
        cmdDisplay();
    }
    std::signal(SIGINT, SIG_DFL);
}

}
