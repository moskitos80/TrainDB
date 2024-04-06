#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <ctime>
#include <vector>
#include <chrono>
#include <memory>

#include "input.hpp"
#include "traindb/App.hpp"
#include "traindb/persist/Repo.hpp"
#include "traindb/persist/Train.hpp"
#include "traindb/Context.hpp"
#include "traindb/view/Key.hpp"
#include "traindb/view/Main.hpp"
#include "traindb/view/Loading.hpp"

int main(/* int argc, char* argv[] */)
{
    auto locale = std::locale("");
    auto localeOld = std::locale::global(locale);
    std::cout.imbue(locale);

    std::ifstream infile{ "/home/artem/Projects/CPP/TrainDB/data/Train.dat" };
    std::vector<std::shared_ptr<traindb::Train>> storage{};
    readData<std::shared_ptr<traindb::Train>, decltype(storage)>(
        infile,
        storage,
        []() { return std::make_shared<traindb::Train>(); }
    );


// traindb::Train tr{
//     "7047",
//     "Москва (Курский вокзал)",
//     "Тула (Московский вокзал)",
// };

    auto tr{ std::make_shared<traindb::Train>() };
    tr->Id = "7047";
    tr->Dep = "Москва (Курский вокзал)";
    tr->Arr = "Тула (Московский вокзал)";

    std::tm date{};
    date.tm_year = 2024 - 1900;
    date.tm_mon = 4 - 1;
    date.tm_mday = 5;
    // std::cout << "Enter date: ";
    // std::cin >> std::get_time(&date, "%d.%m.%Y");
    tr->Date = std::mktime(&date);

    // std::cout << "Enter dep time: ";
    // std::cin >> std::get_time(&date, "%H:%M");

    std::tm timeDep{};
    timeDep.tm_year = 2024 - 1900;
    timeDep.tm_hour = 6;
    timeDep.tm_min = 57;
    tr->DepTime = std::mktime(&timeDep);

    // std::cout << "Enter arr time: ";
    // std::cin >> std::get_time(&date, "%H:%M");

    std::tm timeArr{};
    timeArr.tm_year = 2024 - 1900;
    timeArr.tm_hour = 9;
    timeArr.tm_min = 33;
    tr->ArrTime = std::mktime(&timeArr);


    // std::time_t tripTime = std::difftime(tr->ArrTime, tr->DepTime);
    // ------------------------------------

    // traindb::Train tr{};
    // std::istringstream str{ "321|Москва|Тверь|1717850700|1717867800|1717794000" };
    // tr.Unmarshall(str);

    // std::cout << tr.Marshall();
    // std::cout << "\nDate: " << std::put_time(std::localtime(&tr.Date), "%d %b") << '\n';
    // std::cout << "DepTime: " << std::put_time(std::localtime(&tr.DepTime), "%H:%M") << '\n';
    // std::cout << "ArrTime: " << std::put_time(std::localtime(&tr.ArrTime), "%H:%M") << '\n';
    // std::cout << "TripTime: " << std::put_time(std::gmtime(&tripTime), "%H:%M") << '\n';

       // using traindb::screen::Key;

       // traindb::Context ctx{};
       // ctx.DbSavePath = "/home/artem/Projects/CPP/TrainDB/data/Train.dat";

       // traindb::App app{ ctx };

       // traindb::screen::Main mainScreen{ };
       // traindb::screen::Loading loadScreen{ };

       // app.AddScreen(Key::Loading, loadScreen);
       // app.AddScreen(Key::Main, mainScreen);

       // app.run(Key::Loading, Key::Exit);

       // std::cout <<
       //     "--- Показать\n"
       //     "1-5) Поезд\n"
       //     "?  ) Помощь\n"

       //     "\n--- Сортировка\n"
       //     "t) Дата\n"
       //     "n) Номер\n"
       //     "d) Время Отпр\n"
       //     "a) Время Приб\n"

       //     "\n--- Перейти\n"
       //     "s) Поиск\n"
       //     "m) Главная\n"
       //     "c) Управление\n"
       //     "---\n";

       // auto userChoice = getValidatedInput(
       //     std::cin,
       //     std::cout,
       //     "^[1-5?tndasmc]$",
       //     "! Неверный ввод. Повторите попытку.\n"
       //     "---\n"
       // );

       // std::cout
       //     << "Your choice: "
       //     << userChoice << '\n';

    traindb::Repository<traindb::Train, std::string> repo{};
    repo.Add(std::move(tr));

    auto res{ repo.Get("7047") };
    if (res.has_value())
        std::cout << "Get: " << *res.value() << '\n';
    else {
        std::cout << "NOT Get 7047" << '\n';
    }

    // repo.Del("7047");

    res = repo.Get("7087");
    if (res.has_value())
        std::cout << "Get: " << *res.value() << '\n';
    else {
        std::cout << "NOT Get 7087" << '\n';
    }

    for (auto&& i : repo.Find([](const auto& i)->bool { return i->Id == "7047"; })) {
        std::cout << "Found: " << *i << '\n';
    }


    std::cout << "-----------" << '\n';

    for (auto&& i : storage) {
        std::cout << *i << '\n';
    }

    std::locale::global(localeOld);
    std::cout.imbue(localeOld);
}
