cmake_minimum_required(VERSION 3.0)

project(LR8)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS})

file(GLOB_RECURSE EXE_SRCS src/*.cpp)
file(GLOB_RECURSE EXE_HDRS src/*.hpp)
file(GLOB_RECURSE EXE_FORMS forms/*.ui)

add_executable(lr8 ${EXE_HDRS} ${EXE_SRCS} ${EXE_FORMS})
target_link_libraries(lr8 PUBLIC ${Qt5Core_QTMAIN_LIBRARIES} ${Qt5Widgets_LIBRARIES})
target_compile_features(lr8 PUBLIC cxx_std_17)
