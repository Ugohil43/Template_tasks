cmake_minimum_required(VERSION 3.5.0)

set(SOURCES
    ./src/Task_0.h
    ./src/Task_0.cpp
    )

include_directories(
    ./src/
    )
add_executable(Task_0 ./main.cpp ${SOURCES})