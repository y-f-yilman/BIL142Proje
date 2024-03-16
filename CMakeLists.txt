cmake_minimum_required(VERSION 3.27)
project(Space_Voyagers_Divan_Edition_GOTY)

set(CMAKE_CXX_STANDARD 17)

add_executable(Space_Voyagers_Divan_Edition_GOTY main.cpp
        SpaceVoyage.h
        Ship.h
        ShipProperty.h
        SpaceVoyage.cpp
        GamePlayr.h
        GamePlayr.cpp
        ShipProperty.cpp)
