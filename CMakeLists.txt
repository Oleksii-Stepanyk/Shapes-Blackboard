cmake_minimum_required(VERSION 3.29)
project(Shapes_Blackboard)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shapes_Blackboard main.cpp
        BlackBoard.cpp
        BlackBoard.h
        UIKernel.cpp
        UIKernel.h
        Shape.cpp
        Shape.h
        FileHandler.cpp
        FileHandler.h
        TextFormat.cpp)
