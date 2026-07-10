#include <string>
#include <vector>
#include <set>
#include "Circuit.hpp"
#include "Factory.hpp"

namespace nts
{
    class Parser {
    public:
        Parser(Circuit &circuit);
        ~Parser() = default;
        void parse_file(const std::string &filename);
    private:
        Circuit &_circuit;
        Factory _factory;
        void parse_line(std::string line);
        void parse_chipset(const std::string &line);
        void parse_link(const std::string &line);
        static std::string trim(const std::string& str);
        enum class Section {
            NONE,
            CHIPSETS,
            LINKS
        };
        Section _currentsection;
        bool _chipsets;
        bool _links;
        std::set<std::string> _componentNames;
    };
}