cmake_minimum_required(VERSION 3.5.0)

set(SOURCES
    ./src/Task_2.h
    )

include_directories(
    ./src/
    )
add_executable(Task_2 ./main.cpp ${SOURCES})