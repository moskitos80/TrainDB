#ifndef __TRAIN__H__
#define __TRAIN__H__

#include <iostream>
#include <string>
#include <memory>
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
        std::time_t Date{};

        std::string Marshall() const;
        bool Unmarshall(std::istream& in);

        friend bool operator==(std::shared_ptr<traindb::Train> t, std::string_view n)
        {
            return t->Id == n;
        }

        Train() { std::cerr << "Made: " << Dep << "-" << Arr << '\n'; }
        ~Train() { std::cerr << "Destr: " << Dep << "-" << Arr << '\n'; }
    };



    std::istream& operator>> (std::istream&, std::shared_ptr<Train>);
    std::ostream& operator<< (std::ostream&, const Train&);
} // namespace traindb

#endif  //!__TRAIN__H__