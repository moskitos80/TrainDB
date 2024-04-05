#include <iostream>
#include <stdexcept>
#include <fstream>
#include <memory>

#include "traindb/Train.hpp"
#include "input.hpp"

#include "traindb/Context.hpp"
#include "traindb/screen/Key.hpp"
#include "traindb/screen/Base.hpp"
#include "traindb/screen/Loading.hpp"

namespace traindb::screen
{
    Key Loading::execute(__attribute_maybe_unused__ Context& ctx)
    {
        std::cout << "Loading screen: Enter any sym and press enter: ";
        char c;
        std::cin >> c;
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

