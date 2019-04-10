cmake_minimum_required(VERSION 3.0)

set(SOURCES
    array.cpp
    main.cpp
)

set(HEADERS
    input.hpp
    array.hpp
    arrayemptyexception.hpp
    invalidposexception.hpp
    noposelementsexception.hpp
    noelementsbetweenpos.hpp
    nozerosexception.hpp
)

add_executable(LR6 ${HEADERS} ${SOURCES})


