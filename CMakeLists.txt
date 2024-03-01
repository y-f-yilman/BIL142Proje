cmake_minimum_required(VERSION 3.1)
project(SpaceAdventureGame)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCE_FILES
    main.cpp
    Ship.cpp
    GameEngine.cpp
    General.cpp
)

set(HEADER_FILES
    Ship.h
    GameEngine.h
    General.h
)

add_executable(SpaceAdventureGame ${SOURCE_FILES} ${HEADER_FILES})

