cmake_minimum_required(VERSION 3.16)
project(tests)

set(HEADERS
        ../include/Small.h ../include/Medium.h ../include/Large.h)

set(TESTS_SOURCES
        src/SmallTest.cpp
        src/MediumTest.cpp src/LargeTest.cpp)

add_executable(tests ${TESTS_SOURCES} ${HEADERS})
target_include_directories(tests PUBLIC ../include)

target_link_libraries(tests PRIVATE gtest gtest_main pthread)
