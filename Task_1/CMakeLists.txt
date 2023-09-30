cmake_minimum_required(VERSION 3.5.0)

set(SOURCES
    ./src/MyVector.h
    )

include_directories(
    ./src/
    )
add_executable(Task_1 ./main.cpp ${SOURCES})