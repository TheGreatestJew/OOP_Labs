cmake_minimum_required(VERSION 3.0)

set(SOURCES
    main.cpp
)

set(HEADERS
    b1.hpp
    b2.hpp
    b3.hpp
    d1.hpp
    d2.hpp
    d3.hpp
)

add_executable(LR5 ${HEADERS} ${SOURCES})


