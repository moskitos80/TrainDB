#ifndef __INPUT__H__
#define __INPUT__H__

#include <stdexcept>    // runtime_error
#include <iostream>     // istream ostream
#include <memory>       // make_unique


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
void readData(std::istream& input, DataStorageType& s)
{
    auto dataUnit{ std::make_unique<DataUnitType>() };

    int lineNo{ 1 };
    while (input >> dataUnit.get()) {
        s.push_back(std::move(dataUnit));
        ++lineNo;
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