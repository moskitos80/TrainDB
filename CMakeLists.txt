cmake_minimum_required(VERSION 3.22)
project(TrainDB VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(gcc_like_msvc "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_executable(TrainDB src/main.cpp)
target_include_directories(TrainDB PRIVATE include)
target_compile_options(TrainDB PRIVATE
    $<${gcc_like_cxx}:-O0;-gdwarf;-Wall;-Wextra;-Werror;-Wshadow;-Wpedantic;-Weffc++>
    $<${gcc_like_msvc}:-W3>
)