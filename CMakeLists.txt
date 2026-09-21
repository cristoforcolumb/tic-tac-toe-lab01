cmake_minimum_required(VERSION 3.10)
project(TicTacToeLab01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(game_core src/GameEngine.cpp src/Renderer.cpp src/Listener.cpp)
target_include_directories(game_core PUBLIC include)
if(MSVC)
    target_compile_options(game_core PRIVATE /W4)
else()
    target_compile_options(game_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(tic_tac_toe src/main.cpp)
target_link_libraries(tic_tac_toe PRIVATE game_core)

include(CTest)
if(BUILD_TESTING)
    add_executable(game_tests tests/tests.cpp)
    target_link_libraries(game_tests PRIVATE game_core)
    add_test(NAME game_tests COMMAND game_tests)
endif()
