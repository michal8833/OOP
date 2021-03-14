cmake_minimum_required(VERSION 3.16)
project(benchmarks)

set(HEADERS
        ../include/Small.h ../include/Medium.h ../include/Large.h)

set(BENCHMARKS
        src/SmallBench.cpp src/MediumBench.cpp src/LargeBench.cpp
        src/ListBench_Small.cpp src/MultiMapBench_Small.cpp src/UnorderedMapBench_Small.cpp
        src/ListBench_Medium.cpp src/MultiMapBench_Medium.cpp src/UnorderedMapBench_Medium.cpp
        src/ListBench_Large.cpp src/MultiMapBench_Large.cpp src/UnorderedMapBench_Large.cpp)

add_executable(benchmarks ${BENCHMARKS} ${HEADERS})
target_include_directories(benchmarks PUBLIC ../include)

target_link_libraries(benchmarks PRIVATE benchmark benchmark_main pthread)
