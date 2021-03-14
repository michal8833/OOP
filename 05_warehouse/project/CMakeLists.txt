cmake_minimum_required(VERSION 3.10)
project(Warehouse)

set(CMAKE_CXX_STANDARD 14)

add_library(utils
        utils/include/LiquidContainer.h utils/include/Warehouse.h
        utils/src/LiquidContainer.cpp utils/src/Warehouse.cpp)

target_include_directories(utils PUBLIC utils/include)

add_executable(warehouse src/main.cpp)

target_link_libraries(warehouse LINK_PRIVATE utils)
