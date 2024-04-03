#ifndef __MAINSTATE__H__
#define __MAINSTATE__H__

#include <iostream>
#include <fstream>
#include <memory>

#include "App.hpp"
#include "Fsm.hpp"

class MainState : public FsmState<AppState, App>
{
public:
    AppState execute(App& ctx) override
    {
        for (const auto& train : ctx.Db) {
            std::cout
                << "Поезд: " << train->Num << '\n'
                << "Назначение: " << train->Dst << '\n'
                << "Отправление: " << train->DepTime << "\n---\n";
        }
        std::cout << "Enter any ";
        char c;
        std::cin >> c;
        return AppState::Exit;
    }
};

#endif  //!__MAINSTATE__H__