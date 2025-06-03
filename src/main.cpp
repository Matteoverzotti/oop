//
// Created by matteoverz on 6/2/25.
//
#include "../include/circle.h"
#include "../include/rectangle.h"
#include "../include/vector.h"
#include "tests/test_shapes.cpp"

int main() {
    // ShapeCollection collection;
    // collection.add_shape(std::make_shared<Circle>(5.0));
    // collection.add_shape(std::make_shared<Circle>(5.0));
    // collection.add_shape(std::make_shared<Rectangle>(4.0, 6.0));

    // Circle circle1(std::complex<double>(0, 0), 5.0);
    const Polygon p;
    std::cout << p << '\n';
    const Polygon p2({
        {0, 0}, {4, 0}, {4, 3}, {0, 3}
    });
    std::cout << p2 << '\n';

    const Circle c1(std::complex<double>(0, 0), 5.0);
    const Circle c2(std::complex<double>(0, 0), 5.0);
    std::cout << c1 << '\n';
    std::cout << c2 << '\n';
    return 0;
}
