/*
** EPITECH PROJECT, 2026
** tekspice-23
** File description:
** AComponent
*/

#include "Parser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

namespace nts
{
    Parser::Parser(Circuit &circuit) : _circuit(circuit), _currentsection(Section::NONE),
        _chipsets(false), _links(false)
    {
    }

    std::string Parser::trim(const std::string& str)
    {
        size_t first = 0;
        size_t last = 0;
        size_t value = 0;

        first = str.find_first_not_of(" \t");
        if (std::string::npos == first) {
            return "";
        }
        last = str.find_last_not_of(" \t");
        value = (last - first + 1);
        return str.substr(first, value);
    }

    void Parser::parse_file(const std::string &filename)
    {
        std::ifstream file(filename);
        std::string line;
        size_t comment = 0;

        if (!file.is_open()) {
            throw std::runtime_error("could not open file: " + filename);
        }
        while (std::getline(file, line)) {
            comment = line.find('#');
            if (comment != std::string::npos) {
                line = line.substr(0, comment);
            }
            line = trim(line);
            if (line.empty()) {
                continue;
            }
            if (line == ".chipsets" || line == ".chipsets:") {
                if (_chipsets)
                    throw std::runtime_error("Duplicate .chipsets section");
                _chipsets = true;
                _currentsection = Section::CHIPSETS;
                continue;
            }
            if (line == ".links" || line == ".links:") {
                if (_links)
                    throw std::runtime_error("Duplicate .links section");
                _links = true;
                _currentsection = Section::LINKS;
                continue;
            }
            if (_currentsection == Section::NONE)
                throw std::runtime_error("Content outside of section");
            if (_currentsection == Section::CHIPSETS) {
                parse_chipset(line);
            } else if (_currentsection == Section::LINKS) {
                parse_link(line);
            }
        }
        if (!_chipsets)
            throw std::runtime_error("Missing .chipsets section");
        if (!_links)
            throw std::runtime_error("Missing .links section");
    }

    void Parser::parse_chipset(const std::string &line)
    {
        std::stringstream ss(line);
        std::string type;
        std::string name;
        std::string extra;

        ss >> type >> name;
        if (type.empty() || name.empty()) {
            throw std::runtime_error("Invalid chipset line: " + line);
        }
        if (ss >> extra) {
            throw std::runtime_error("Too many arguments in chipset line: " + line);
        }
        if (_componentNames.count(name)) {
            throw std::runtime_error("Duplicate component name: " + name);
        }
        _componentNames.insert(name);
        auto component = _factory.createComponent(type, name);
        _circuit.addComponent(name, std::move(component));
    }

    void Parser::parse_link(const std::string &line)
    {
        std::stringstream ss(line);
        std::string first;
        std::string second;
        std::string extra;

        ss >> first >> second;
        if (first.empty() || second.empty()) {
            throw std::runtime_error("Invalid link line: " + line);
        }
        if (ss >> extra) {
            throw std::runtime_error("Too many arguments in link line: " + line);
        }
        size_t pos1 = first.find(':');
        if (pos1 == std::string::npos) {
            throw std::runtime_error("Invalid link format: " + first);
        }
        std::string name1 = first.substr(0, pos1);
        std::string pinStr1 = first.substr(pos1 + 1);
        if (pinStr1.empty()) {
            throw std::runtime_error("Missing pin number: " + first);
        }
        size_t pin1 = std::stoul(pinStr1);
        size_t pos2 = second.find(':');
        if (pos2 == std::string::npos) {
            throw std::runtime_error("Invalid link format: " + second);
        }
        std::string name2 = second.substr(0, pos2);
        std::string pinStr2 = second.substr(pos2 + 1);
        if (pinStr2.empty()) {
            throw std::runtime_error("Missing pin number: " + second);
        }
        size_t pin2 = std::stoul(pinStr2);
        nts::IComponent *circuit1 = _circuit.getComponent(name1);
        nts::IComponent *circuit2 = _circuit.getComponent(name2);
        circuit1->setLink(pin1, *circuit2, pin2);
        circuit2->setLink(pin2, *circuit1, pin1);
    }
}
