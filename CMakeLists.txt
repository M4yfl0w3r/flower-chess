cmake_minimum_required(VERSION 3.22.3)

project(flower-chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(include/, /usr/include/SFML)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
target_link_libraries(flower-chess sfml-graphics sfml-window sfml-system)

