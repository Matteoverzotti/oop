//
// Created by matteoverz on 6/2/25.
//
#include "../builder/circle_builder.h"
#include "../builder/polygon_builder.h"
#include "../builder/rectangle_builder.h"
#include "../builder/square_builder.h"
#include "../factory/shape_factory.h"
#include "../include/circle.h"
#include "../include/curved_rectangle.h"
#include "../include/rectangle.h"
#include "../include/shape_collection.h"
#include "../include/vector.h"
#include "tests/test_shapes.cpp"

int main() {
    // TestShapes::test_all();
    ShapeCollection collection;

    collection.addShape(ShapeFactory::create(CIRCLE));
    collection.addShape(ShapeFactory::create(RECTANGLE));
    collection.addShape(ShapeFactory::create(SQUARE));
    collection.printShapes();

    collection.addShape(SquareBuilder().setSize(4).build());
    collection.getShape(3)->print(std::cout);

    collection.removeShape(2);
    collection.printShapes();
    return 0;
}
