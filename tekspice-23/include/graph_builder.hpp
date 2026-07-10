/*
** EPITECH PROJECT, 2026
** \
** File description:
** graph_builder
*/

#ifndef GRAPH_BUILDER_HPP_
#define GRAPH_BUILDER_HPP_

#include <cstddef>
#include <map>
#include <string>
#include <vector>

namespace nts
{
    class IComponent;

    struct Link {
        std::string fromName;
        std::size_t fromPin;
        std::string toName;
        std::size_t toPin;
    };
    using ComponentMap = std::map<std::string, IComponent *>;
    void buildGraph(ComponentMap &components, const std::vector<Link> &links);
    void simulateTick(ComponentMap &components, std::size_t tick);
}

#endif /* !GRAPH_BUILDER_HPP_ */
