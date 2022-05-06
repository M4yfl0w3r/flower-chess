cmake_minimum_required(VERSION 3.13)

project(flower_chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")
add_compile_options(${CMAKE_CXX_FLAGS})

include(FetchContent)

option(SFML_LINK_STATIC FALSE)
option(SFML_BUILD_AUDIO FALSE)
option(SFML_BUILD_NETWORK FALSE)

FetchContent_Declare(SFML
  URL "https://github.com/SFML/SFML/archive/2.5.1.zip")
FetchContent_GetProperties(SFML)

if (NOT SFML_POPULATED)
  if (LINK_DEPS_STATIC)
    find_package(SFML)
  else()
    FetchContent_Populate(SFML)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
  endif()
endif()


set(SOURCE 
  src/main.cpp
  src/Chess_Piece.cpp
  src/Flower_Board.cpp
  src/Game_Window.cpp
  src/flower_vector.cpp
)

add_executable(game ${SOURCE})

target_link_libraries(game PRIVATE sfml-graphics sfml-system sfml-window)
