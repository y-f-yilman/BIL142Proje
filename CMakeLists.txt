cmake_minimum_required(VERSION 3.10)
project(SpaceAdventure)

set(CMAKE_CXX_STANDARD 11)

# Add executable
add_executable(SpaceAdventure main.cpp game.cpp ship.cpp
        GeneralFunc.h
        GeneralFunc.cpp
        event.cpp
        GameStarter.h
        GameStarter.cpp
)

# Add include directories
target_include_directories(SpaceAdventure PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set executable output directory
set_target_properties(SpaceAdventure PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

