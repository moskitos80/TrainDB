#ifndef __INPUT__H__
#define __INPUT__H__

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstddef>
#include <limits>
#include <memory>
#include <array>

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

template<std::size_t Size>
std::size_t getSelection(
    std::string_view prompt,
    const std::array<std::string_view, Size>& items
) noexcept(false)
{
    while (true) {
        std::cout << prompt;
        std::size_t index{ 1 };

        for (auto&& item : items) {
            std::cout << index << ") " << item << '\n';
            index++;
        } std::cout << "---\n> ";

        if (int choice{ 0 }; std::cin >> choice && choice > 0 && choice < std::size(items)) {
            return static_cast<std::size_t>(choice + 1);
        }

        if (std::cin.eof()) {
            throw InputError{ "Прервано" };
        }

        std::cerr << "Не верный ввод. Попробуем еще раз.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

#endif  //!__INPUT__H__