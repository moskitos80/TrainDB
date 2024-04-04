#include <iostream>
#include <cassert>
#include <string>
#include <ctime>

#include "traindb/Train.hpp"

namespace traindb
{
    std::istream& operator>> (std::istream& in, Train* t)
    {
        assert(t != nullptr);
        char sep{};
        int date{};
        int arrTime{};
        int depTime{};
        return in
            >> t->Id >> sep
            >> t->Arr >> sep
            >> t->Dep >> sep
            >> depTime >> sep
            >> arrTime >> sep
            >> date;
    }

    std::ostream& operator<< (std::ostream& out, const Train& t)
    {
        return out << t.Id;
    }
}

