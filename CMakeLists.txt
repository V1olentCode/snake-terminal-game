cmake_minimum_required(VERSION 3.16)

project(TerminalSnake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(snake
    src/main.cpp
    src/Snake.cpp
    src/Board.cpp
    src/Renderer.cpp
    src/Food.cpp
    src/Game.cpp
    src/Input.cpp
)

target_include_directories(snake PRIVATE include)