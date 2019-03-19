cmake_minimum_required(VERSION 3.0)

set(SOURCES
    angle.cpp
    main.cpp
    righttriangle.cpp
)

set(HEADERS
    angle.hpp
    righttriangle.hpp
)

add_executable(LR4 ${HEADERS} ${SOURCES})


