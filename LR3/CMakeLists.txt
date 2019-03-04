cmake_minimum_required(VERSION 3.0)

set(SOURCES
    main.cpp
    time.cpp
)

set(HEADERS
    time.hpp
)

add_executable(LR3 ${HEADERS} ${SOURCES})
