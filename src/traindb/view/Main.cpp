
#include "input.hpp"
#include "traindb/Context.hpp"
#include "traindb/view/Key.hpp"
#include "traindb/view/Base.hpp"
#include "traindb/view/Main.hpp"

namespace traindb::view
{
    Key Main::execute(__attribute_maybe_unused__ Context& ctx)
    {
        std::cout << "\nГлавная\n\n"
            "1) Поиск и просмотр\n"
            "2) Управление\n"
            "3) Выход\n"
            "---\n";

        auto userChoice{
            getValidatedInput(
                std::cin,
                std::cout,
                "[123]",
                "Не верный ввод. Попробуйте еще раз\n"
            )
        };

        if (userChoice == "1") {
            return Key::Search;
        }

        if (userChoice == "2") {
            return Key::Admin;
        }

        return Key::Exit;
    }
}