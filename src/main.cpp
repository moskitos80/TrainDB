
#include "traindb/App.hpp"
#include "traindb/Context.hpp"
#include "traindb/screen/Key.hpp"
#include "traindb/screen/Main.hpp"
#include "traindb/screen/Loading.hpp"

int main()
{
    using traindb::screen::Key;

    traindb::Context ctx{};
    traindb::App app{ ctx };

    traindb::screen::Main mainScreen{ };
    traindb::screen::Loading loadScreen{ };

    app.AddScreen(Key::Loading, loadScreen);
    app.AddScreen(Key::Main, mainScreen);

    app.run(Key::Loading, Key::Exit);
}
