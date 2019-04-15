cmake_minimum_required(VERSION 3.0)

set(SOURCES
	app.cpp
    main.cpp
)

set(HEADERS
	app.hpp
	input.hpp
)

add_executable(LR7 ${HEADERS} ${SOURCES})


