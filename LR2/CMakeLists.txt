cmake_minimum_required(VERSION 3.0)

set(SOURCES
    cyl.cpp
        main.cpp
)

set(HEADERS
cyl.h
)

add_executable(program ${HEADERS} ${SOURCES})
