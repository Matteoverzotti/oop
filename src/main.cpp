//
// Created by matteoverz on 6/2/25.
//
#include "../builder/circle_builder.h"
#include "../builder/polygon_builder.h"
#include "../builder/rectangle_builder.h"
#include "../factory/shape_factory.h"
#include "../include/circle.h"
#include "../include/curved_rectangle.h"
#include "../include/rectangle.h"
#include "../include/shape_collection.h"
#include "../include/vector.h"
#include "tests/test_shapes.cpp"

int main() {
    TestShapes::test_all();
    return 0;
}
