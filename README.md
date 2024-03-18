# BIL142Proje
Project Design For BIL142 Course in C++

![Local image](diagrams/system_headers.svg "System Headers")
    <figcaption>System Headers</figcaption>

\
&nbsp;
\
&nbsp;

![Local image](diagrams/class_diagram.svg "Class Diagram")
    <figcaption>Class Diagrams</figcaption>

# Space Adventure Game

## Description
Space Adventure Game is a console-based game where you navigate a spaceship through a series of events in space.


## Requirements
- `CMake 3.10` or higher
- `C++17` compliant compiler

## Compilation Using Cmake
To compile the game, follow these steps:

1. Navigate to the root directory of the project.
2. Create a build directory:
    
    ```
    mkdir build && cd build
    ```
3. Generate the make file using CMake:

    ```
    cmake ..
    ```
4. Compile the project:

    ```
    make
    ```

## Compilation Using GCC

Run the following command:

```
    g++ -o SpaceAdventure main.cpp game.cpp ship.cpp
        GeneralFunc.h
        GeneralFunc.cpp
        event.cpp
        GameStarter.h
        GameStarter.cpp
```

## Usage
After compiling, you can run the game by executing the binary:

```
    ./SpaceAdventure
```
