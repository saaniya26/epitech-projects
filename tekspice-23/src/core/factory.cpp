/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** Factory implementation
*/

#include "Factory.hpp"
#include "c4081.hpp"
#include "c4071.hpp"
#include "c4069.hpp"
#include "c4001.hpp"
#include "c4011.hpp"
#include "c4013.hpp"
#include "c4040.hpp"
#include "c4512.hpp"
#include "c4801.hpp"
#include "c4030.hpp"
#include "c4008.hpp"
#include "c4013.hpp"
#include "c4017.hpp"
#include "c4094.hpp"
#include "c4514.hpp"
#include "logger.hpp"
#include "input_component.hpp"
#include "output_component.hpp"
#include "clock_component.hpp"
#include "true_component.hpp"
#include "false_component.hpp"
#include "and_component.hpp"
#include "or_component.hpp"
#include "xor_component.hpp"
#include "not_component.hpp"
#include <iostream>
#include <functional>
#include <map>
#include <stdexcept>

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string &name)
{
    using constructor_t = std::function<std::unique_ptr<nts::IComponent>(const std::string &name)>;

    static const std::map<std::string, constructor_t> constructors = {
        {"4081", [](const std::string &name) { return std::make_unique<C4081>(name);}},
        {"4071", [](const std::string &name) { return std::make_unique<C4071>(name);}},
        {"4069", [](const std::string &name) { return std::make_unique<C4069>(name);}},
        {"4001", [](const std::string &name) { return std::make_unique<C4001>(name);}},
        {"4011", [](const std::string &name) { return std::make_unique<C4011>(name);}},
        {"4013", [](const std::string &name) { return std::make_unique<C4013>(name);}},
        {"4040", [](const std::string &name) { return std::make_unique<C4040>(name);}},
        {"4512", [](const std::string &name) { return std::make_unique<C4512>(name);}},
        {"4801", [](const std::string &name) { return std::make_unique<C4801>(name);}},
        {"ram", [](const std::string &name) { return std::make_unique<C4801>(name);}},
        {"4030", [](const std::string &name) { return std::make_unique<C4030>(name);}},
        {"4008", [](const std::string &name) { return std::make_unique<C4008>(name);}},
        {"4017", [](const std::string &name) { return std::make_unique<nts::C4017>(name);}},
        {"4094", [](const std::string &name) { return std::make_unique<nts::C4094>(name);}},
        {"4514", [](const std::string &name) { return std::make_unique<nts::C4514>(name);}},
        {"logger", [](const std::string &name) { return std::make_unique<nts::Logger>(name);}},
        {"and", [](const std::string &name) { return std::make_unique<AndComponent>(name);}},
        {"or", [](const std::string &name) { return std::make_unique<OrComponent>(name);}},
        {"xor", [](const std::string &name) { return std::make_unique<XorComponent>(name);}},
        {"not", [](const std::string &name) { return std::make_unique<NotComponent>(name);}},
        {"input", [](const std::string &name) { return std::make_unique<InputComponent>(name);}},
        {"output", [](const std::string &name) { return std::make_unique<OutputComponent>(name);}},
        {"clock", [](const std::string &name) { return std::make_unique<ClockComponent>(name);}},
        {"true", [](const std::string &name) { return std::make_unique<TrueComponent>(name);}},
        {"false", [](const std::string &name) { return std::make_unique<FalseComponent>(name);}},
        {"and", [](const std::string &name) { return std::make_unique<AndComponent>(name);}},
        {"or", [](const std::string &name) { return std::make_unique<OrComponent>(name);}},
        {"xor", [](const std::string &name) { return std::make_unique<XorComponent>(name);}},
        {"not", [](const std::string &name) { return std::make_unique<NotComponent>(name);}},
    };
    auto i = constructors.find(type);
    if (i == constructors.end()) {
        throw std::runtime_error("Unknown component type: " + type);
    }
    return i->second(name);
}