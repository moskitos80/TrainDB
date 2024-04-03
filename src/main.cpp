#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstddef>
#include <stdexcept>
#include <string_view>
#include <string>
#include <vector>
#include <array>

#include "App.hpp"
#include "Fsm.hpp"
#include "MainState.hpp"
#include "LoadingState.hpp"


int main()
{
    App app{};
    Fsm<AppState, App> stateMachine{ app };

    LoadingState loadingState{};
    MainState mainState{};

    stateMachine.AddState(AppState::Loading, loadingState);
    stateMachine.AddState(AppState::Main, mainState);

    stateMachine.run(AppState::Loading, AppState::Exit);
}
