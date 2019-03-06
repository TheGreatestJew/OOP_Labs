cmake_minimum_required(VERSION 3.0)

set(SOURCES
    time.cpp
)

set(HEADERS
    time.hpp
)

add_library(LR3_lib STATIC ${HEADERS} ${SOURCES})
add_executable(LR3  main.cpp)
target_link_libraries(LR3 PRIVATE LR3_lib)

find_package(GTest MODULE)

if(GTest_FOUND)
    enable_testing()
    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(LR3-test test.cpp)
    target_link_libraries(LR3-test PRIVATE LR3_lib GTest::GTest GTest::Main)
    add_test(AllTestsIn LR3-test)
endif()


