cmake_minimum_required(VERSION 3.24)
project(cmpe230_p3)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt6Widgets REQUIRED)

add_executable(cmpe230_p3
        src/main.cpp)

target_link_libraries(cmpe230_p3 Qt6::Widgets)