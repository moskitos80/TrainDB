#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>
#include <sstream>
#include <ctime>

#include "traindb/persist/Train.hpp"

namespace traindb
{
    std::istream& operator>> (std::istream& in, std::shared_ptr<Train> t)
    {
        char sep{};

        std::getline(in >> std::ws, t->Id, '|');
        std::getline(in >> std::ws, t->Arr, '|');
        std::getline(in >> std::ws, t->Dep, '|');

        in >> t->DepTime >> sep
            >> t->ArrTime >> sep
            >> t->Date;

        return in;
    }

    std::ostream& operator<< (std::ostream& out, std::shared_ptr<Train> t)
    {
        std::ostringstream os;
        out << t->Id << "|"
            << t->Dep << "|"
            << t->Arr << "|"
            << t->DepTime << "|"
            << t->ArrTime << "|"
            << t->Date;

        return out;
    }

    std::ostream& operator<< (std::ostream& out, const Train& t)
    {
        auto presentDepTime{ std::put_time(
            std::localtime(&t.DepTime), "%d/%m/%y %H:%M") };
        auto presentArrTime{ std::put_time(
            std::localtime(&t.ArrTime), "%d/%m/%y %H:%M") };

        out << "Поезд:    " << t.Id << '\n'
            << "Откуда:   " << t.Dep << '\n'
            << "Куда:     " << t.Arr << '\n'
            << "Отправл:  " << presentDepTime << '\n'
            << "Прибытие: " << presentArrTime << '\n';

        return out;
    }
}

