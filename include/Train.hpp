#ifndef __TRAIN__H__
#define __TRAIN__H__

#include <iostream>
#include <memory>
#include <string>
#include <cassert>

struct Train
{
    std::string Dst{};
    std::string DepTime{};
    int Num{};

    ~Train() { std::cerr << "Destr " << Dst << "\n"; }
};

std::istream& operator>> (std::istream& in, Train* t)
{
    assert(t != nullptr);
    std::getline(in >> std::ws, t->Dst, '|');
    std::getline(in >> std::ws, t->DepTime, '|');
    return in >> t->Num;
}

std::ostream& operator<< (std::ostream& out, const Train& t)
{
    return out
        << t.Dst << '|'
        << t.DepTime << '|'
        << t.Num << '\n';
}

#endif  //!__TRAIN__H__