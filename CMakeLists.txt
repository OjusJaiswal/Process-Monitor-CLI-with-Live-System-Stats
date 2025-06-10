cmake_minimum_required(VERSION 3.10)
project(process_monitor)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(process_monitor
    src/main.cpp
    src/process.cpp
    src/system_monitor.cpp
)

target_link_libraries(process_monitor ncurses pthread)
