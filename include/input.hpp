#ifndef __INPUT__H__
#define __INPUT__H__

#include <stdexcept>    // runtime_error
#include <iostream>     // istream ostream
#include <type_traits>  // make_unique
#include <memory>       // make_unique
#include <functional> 


class InputError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class LoadDataError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};


template<typename DataUnitType, typename DataStorageType>
std::enable_if_t<
    std::is_same_v<decltype(std::declval<DataStorageType>().push_back(std::declval<DataUnitType>())), void>&&
    std::is_same_v<decltype(std::declval<std::istream&>() >> std::declval<DataUnitType&>()), std::istream&>
>
readData(std::istream& input, DataStorageType& s, std::function<DataUnitType()> allocator)
{
    int lineNo{ 1 };
    while (input) {
        auto dataUnit{ allocator() };
        if (input >> dataUnit) {
            s.push_back(std::move(dataUnit));
            ++lineNo;
        }
    }

    if (!input.eof()) {
        throw LoadDataError{
            "Не смог прочитать файл данных. Ошибка в строке: " +
            std::to_string(lineNo) };
    }
}

std::string getValidatedInput(
    std::istream& in,
    std::ostream& out,
    const std::string& validateRegex,
    const std::string& failMessage
);

#endif  //!__INPUT__H__