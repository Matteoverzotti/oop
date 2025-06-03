cmake_minimum_required(VERSION 3.31)
project(Homework)

set(CMAKE_CXX_STANDARD 20)

add_executable(Homework src/main.cpp
        include/vector.h
        include/shape.h
        src/polygon.cpp
        include/polygon.h
        src/rectangle.cpp
        include/rectangle.h
        include/curved_shape.h
        src/circle.cpp
        include/circle.h
        include/constants.h
        include/exceptions.h
)
