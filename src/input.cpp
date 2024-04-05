#include <iostream>     // istream ostream ws getline
#include <string>       // string
#include <regex>        // regex regex_match

#include "input.hpp"

std::string getValidatedInput(
    std::istream& in,
    std::ostream& out,
    const std::string& validateRegex,
    const std::string& failMessage
)
{
    std::string inp{};
    std::regex rgx{ validateRegex };

    while (true) {
        out << "> ";
        std::getline(in >> std::ws, inp, '\n');
        if (in && std::regex_match(inp, rgx)) {
            break;
        }
        if (in.eof()) {
            throw InputError{ "Interrupted" };
        }
        out << failMessage;
        in.clear();
    }

    return inp;
}
