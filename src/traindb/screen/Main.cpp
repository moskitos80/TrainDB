
#include "traindb/Context.hpp"
#include "traindb/screen/Key.hpp"
#include "traindb/screen/Base.hpp"
#include "traindb/screen/Main.hpp"

namespace traindb::screen
{
    Key Main::execute(__attribute_maybe_unused__ Context& ctx)
    {
        // for (const auto& train : ctx.Db) {
        //     std::cout
        //         << "Поезд: " << train->Num << '\n'
        //         << "Назначение: " << train->Dst << '\n'
        //         << "Отправление: " << train->DepTime << "\n---\n";
        // }

        std::cout << "Main screen: Enter any sym and press enter: ";
        char c;
        std::cin >> c;

        return Key::Exit;
    }
}