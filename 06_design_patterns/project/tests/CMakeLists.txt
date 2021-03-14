cmake_minimum_required(VERSION 3.16)

SET(OBSERVER_HEADERS
        ../include/observer/Observable.h ../include/observer/Observer.h
        ../include/observer/Displacement.h ../include/observer/Acceleration.h ../include/observer/Speed.h)

SET(OBSERVER_SOURCES
        ../src/observer/Observable.cpp ../src/observer/Displacement.cpp ../src/observer/Acceleration.cpp ../src/observer/Speed.cpp)

add_executable(tests
        src/Tests.cpp
        ${OBSERVER_HEADERS} ${OBSERVER_SOURCES})

target_include_directories(tests PUBLIC ../include)

target_include_directories(tests PRIVATE ../../googletest/googletest/include)
target_link_directories(tests PRIVATE ../../googletest/build/lib)

target_link_libraries(tests PRIVATE gtest gtest_main pthread)
