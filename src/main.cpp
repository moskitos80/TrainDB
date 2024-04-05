#include <iomanip>
#include <locale>
#include <ctime>
#include <vector>

#include "input.hpp"
#include "traindb/App.hpp"
#include "traindb/Context.hpp"
#include "traindb/screen/Key.hpp"
#include "traindb/screen/Main.hpp"
#include "traindb/screen/Loading.hpp"

int main()
{
    // using traindb::screen::Key;

    // traindb::Context ctx{};
    // traindb::App app{ ctx };

    // traindb::screen::Main mainScreen{ };
    // traindb::screen::Loading loadScreen{ };

    // app.AddScreen(Key::Loading, loadScreen);
    // app.AddScreen(Key::Main, mainScreen);

    // app.run(Key::Loading, Key::Exit);


    auto locale = std::locale("en_US.UTF-8");
    auto localeOld = std::locale::global(locale);
    std::cout.imbue(locale);

    std::cout <<
        "--- Показать\n"
        "1-5) Поезд\n"
        "?  ) Помощь\n"

        "\n--- Сортировка\n"
        "t) Дата\n"
        "n) Номер\n"
        "d) Время Отпр\n"
        "a) Время Приб\n"

        "\n--- Перейти\n"
        "s) Поиск\n"
        "m) Главная\n"
        "c) Управление\n";

    auto userChoice = getValidatedInput(
        std::cin,
        std::cout,
        "^[1-5?tndasmc]$",
        "Неверный ввод. Повторите попытку.\n"
    );

    std::cout << "Your choice: " << userChoice << '\n';

    std::locale::global(localeOld);
    std::cout.imbue(localeOld);
}
