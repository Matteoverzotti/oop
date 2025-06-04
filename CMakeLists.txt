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
        src/tests/test_shapes.cpp
        src/tests/logger.cpp
        src/tests/logger.h
        src/tests/base_test.h
        factory/shape_factory.cpp
        factory/shape_factory.h
        src/shape_collection.cpp
        include/shape_collection.h
        src/shape.cpp
        builder/circle_builder.h
        src/curved_rectangle.cpp
        include/curved_rectangle.h
        builder/curved_rectangle_builder.h
        src/square.cpp
        include/square.h
)
