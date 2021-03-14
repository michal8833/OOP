cmake_minimum_required(VERSION 3.16)

project(project)

SET(ABSTRACT_FACTORY_HEADERS
        include/abstract_factory/animals/AnimalFactory.h include/abstract_factory/animals/FishFactory.h include/abstract_factory/animals/Cod.h
        include/abstract_factory/animals/Salmon.h include/abstract_factory/animals/Tuna.h include/abstract_factory/animals/BirdFactory.h
        include/abstract_factory/animals/Sparrow.h include/abstract_factory/animals/Eagle.h include/abstract_factory/animals/Raven.h)

SET(ABSTRACT_FACTORY_SOURCES
        src/abstract_factory/animals/FishFactory.cpp src/abstract_factory/animals/Salmon.cpp src/abstract_factory/animals/Tuna.cpp
        src/abstract_factory/animals/Cod.cpp src/abstract_factory/animals/BirdFactory.cpp src/abstract_factory/animals/Sparrow.cpp
        src/abstract_factory/animals/Eagle.cpp src/abstract_factory/animals/Raven.cpp)

SET(OBSERVER_HEADERS
        include/observer/Observable.h include/observer/Observer.h
        include/observer/Displacement.h include/observer/Acceleration.h include/observer/Speed.h)

SET(OBSERVER_SOURCES
        src/observer/Observable.cpp src/observer/Displacement.cpp src/observer/Acceleration.cpp src/observer/Speed.cpp)

add_executable(example
        src/main.cpp
        ${ABSTRACT_FACTORY_HEADERS} ${ABSTRACT_FACTORY_SOURCES}
        ${OBSERVER_HEADERS} ${OBSERVER_SOURCES})

target_include_directories(example PUBLIC include)

add_subdirectory(tests)
