#ifndef __APP__H__
#define __APP__H__

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "Train.hpp"

enum class AppState {
    Loading,
    Main,
    Sort,
    Add,
    Save,
    Exit,
};

class InputError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

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

        std::cerr << "Не верный выбор. Попробуем еще раз.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

struct App
{
    std::vector<std::string> Info{};
    std::vector<std::string> Error{};
    std::vector<std::unique_ptr<Train>> Db{};
    AppState PrevState{ AppState::Main };
};

#endif  //!__APP__H__