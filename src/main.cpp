//
// Created by matteoverz on 6/2/25.
//
#include "../include/circle.h"
#include "../include/rectangle.h"
#include "../include/shape_collection.h"
#include "../include/vector.h"
#include "tests/test_shapes.cpp"

int main() {
    ShapeCollection collection;
    collection.add_shape(std::make_shared<Circle>(5.0));
    collection.add_shape(std::make_shared<Circle>(5.0));
    collection.add_shape(std::make_shared<Rectangle>(4.0, 6.0));

    Circle circle1(std::complex<double>(0, 0), 5.0);
    Circle circle2(std::complex<double>(0, 0), 5.0);
    collection.add_shape(std::make_shared<Circle>(circle1));
    collection.add_shape(std::make_shared<Circle>(circle2));

    collection.remove_shape(0);

    collection.print_shapes();
    return 0;
}
