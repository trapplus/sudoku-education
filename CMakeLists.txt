cmake_minimum_required(VERSION 3.20)

project(Sudoku LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include/sudoku-education)

add_executable(Sudoku
    src/main.cpp
    src/Board.cpp
    src/Engine.cpp
    src/Game.cpp
    src/Validator.cpp
    src/Statistics.cpp
)

include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)

target_link_libraries(sudoku PRIVATE nlohmann_json::nlohmann_json)

