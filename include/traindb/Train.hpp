#ifndef __TRAIN__H__
#define __TRAIN__H__

#include <iostream>
#include <string>
#include <ctime>

namespace traindb
{
    struct Train
    {
        std::string Id{};
        std::string Arr{};
        std::string Dep{};
        std::time_t DepTime{};
        std::time_t ArrTime{};
        std::tm Date{};
    };

    std::istream& operator>> (std::istream&, Train*);
    std::ostream& operator<< (std::ostream&, const Train&);
} // namespace traindb

#endif  //!__TRAIN__H__