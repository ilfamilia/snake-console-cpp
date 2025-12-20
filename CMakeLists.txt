cmake_minimum_required(VERSION 3.16)
project(snake_console_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(snake
    src/main.cpp
    src/Board.cpp
    src/Renderer.cpp
    src/Snake.cpp
    src/Food.cpp
)

target_include_directories(snake PRIVATE include)
