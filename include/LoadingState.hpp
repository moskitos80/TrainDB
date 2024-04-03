#ifndef __LOADINGSTATE__H__
#define __LOADINGSTATE__H__

#include <iostream>
#include <fstream>
#include <memory>

#include "App.hpp"
#include "Fsm.hpp"

class LoadingState : public FsmState<AppState, App>
{
public:
    AppState execute(App& ctx) override
    {
        std::string path{};
        std::cout << "Введите путь к файлу данных: ";
        if (std::getline(std::cin >> std::ws, path, '\n').eof()) {
            ctx.Error.emplace_back("Прервано");
            return AppState::Exit;
        }

        std::ifstream dataStream{ path };
        if (!dataStream) {
            ctx.Error.emplace_back("Не смог открыть файл данных");
            return AppState::Exit;
        }

        while (true) {
            auto trainRec{ std::make_unique<Train>() };
            if (dataStream >> trainRec.get()) {
                ctx.Db.push_back(std::move(trainRec));
            } else if (dataStream.eof()) {
                break;
            } else {
                ctx.Error.emplace_back("Не смог прочитать");
            }
        }

        return AppState::Main;
    }
};

#endif  //!__LOADINGSTATE__H__