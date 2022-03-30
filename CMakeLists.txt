cmake_minimum_required(VERSION 3.22.3)

project(flower-chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

include_directories(include/, /usr/include/SFML)
add_executable(flower-chess main.cpp)
target_link_libraries(flower-chess sfml-graphics sfml-window sfml-system)

