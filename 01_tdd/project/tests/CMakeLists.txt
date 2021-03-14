cmake_minimum_required(VERSION 3.16)

SET(HEADERS
        ../../include/TextWrap.h ../../include/RingBuffer.h)

SET(SOURCES
        ../../src/TextWrap.cpp ../../src/RingBuffer.cpp)

add_executable(tests src/RingBufferTest.cpp src/TextWrapTest.cpp ${HEADERS} ${SOURCES})

target_include_directories(tests PUBLIC ../include)

target_include_directories(tests PRIVATE ../../googletest/googletest/include)
target_link_directories(tests PRIVATE ../../googletest/build/lib)

target_link_libraries(tests PRIVATE gtest gtest_main pthread)
