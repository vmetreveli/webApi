cmake_minimum_required(VERSION 3.26)
project(webApi)

set(CMAKE_CXX_STANDARD 23)

add_executable(webApi main.cpp)

find_package(Crow CONFIG REQUIRED)
target_link_libraries(webApi PRIVATE Crow::Crow)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(webApi PRIVATE nlohmann_json::nlohmann_json)
