#include <iostream>
#include <stdexcept>
#include <fstream>
#include <memory>
#include <string>

#include "traindb/persist/Train.hpp"
#include "input.hpp"

#include "traindb/Context.hpp"
#include "traindb/view/Key.hpp"
#include "traindb/view/Base.hpp"
#include "traindb/view/Loading.hpp"

namespace traindb::view
{
    Key Loading::execute(Context& ctx)
    {
        if (ctx.DbSavePath == "") {
            std::cerr << "Не предоставлен путь к файлу данных.\n";
            return Key::Exit;
        }

        std::cout << "Loading screen: Enter any sym and press enter: ";
        std::string line;
        std::getline(std::cin, line, '\n');
        return Key::Main;
/*

        try {
            std::string path{};
            std::cout << "Введите путь к файлу данных: ";
            if (std::getline(std::cin >> std::ws, path, '\n').eof()) {
                throw LoadDataError{ "Прервано" };
                return Key::Error;
            }

            std::ifstream trainStream{ path };
            if (!trainStream) {
                throw LoadDataError{ "Не смог открыть файл данных" };
                return Key::Error;
            }

            int lineNo{ 1 };
            while (trainStream) {
                auto trainPrt{ std::make_unique<Train>() };
                trainStream >> trainPrt.get();
                ctx.Db.push_back(std::move(trainPrt));
                ++lineNo;
            }

            if (!trainStream.eof()) {
                throw LoadDataError{
                    "Не смог прочитать файл данных. Ошибка в строке: " +
                    std::to_string(lineNo) };
            }

        } catch (const LoadDataError& e) {
            ctx.Error.emplace_back(e.what());
            return Key::Error;
        }

        return Key::Main; */
    }
}

