
#include "traindb/App.hpp"
#include "traindb/Context.hpp"
#include "traindb/screen/Key.hpp"
#include "traindb/screen/Main.hpp"
#include "traindb/screen/Loading.hpp"

#include <iomanip>
#include <locale>
#include <ctime>

std::istream& operator>>(std::istream& in, std::time_t& time)
{
    std::tm tm;
    char c;
    in.get(c);
    if (in && c == '"') {
        in >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        in.get(c);
    }
    if (in && c == '"') {
        time = std::mktime(&tm);
        return in;
    }
    in.putback(c);
    return in;
}

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

    std::cout << "locale is " << locale.name().c_str() << '\n';

    std::tm t = {};
    if (std::cin >> std::get_time(&t, "%d/%m %H:%M")) {
        std::cout << std::put_time(&t, "%c") << '\n';
    } else {
        std::cerr << "Wrong\n";
    }

    std::locale::global(localeOld);
    std::cout.imbue(localeOld);

    // std::tm date{};
    // date.tm_year = 2024 - 1900;
    // date.tm_mon = 4 - 1;
    // date.tm_mday = 4;
    // date.tm_hour = 16;
    // date.tm_min = 30;
    // auto start = std::mktime(&date);

    // std::tm date2{};
    // date2.tm_year = 2024 - 1900;
    // date2.tm_mon = 4 - 1;
    // date2.tm_mday = 4;
    // date2.tm_hour = 18;
    // date2.tm_min = 40;
    // auto end = std::mktime(&date2);

    // auto diffSec = std::difftime(end, start);
    // std::tm res{};
    // res.tm_sec = diffSec;
    // std::mktime(&res);

    // // auto diff = static_cast<std::time_t>(std::difftime(end, start));

    // std::cout
    //     << std::put_time(&date, "%c") << " - "
    //     << std::put_time(&date2, "%c") << " -> "
    //     << diffSec << " -> "
    //     << std::put_time(&res, "%H:%M") << '\n';

}
