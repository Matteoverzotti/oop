//
// Created by matteoverz on 6/2/25.
//

#include "../include/curved_shape.h"
#include "../include/circle.h"
#include "../include/rectangle.h"
#include "../include/vector.h"
#include "tests/test_vector.cpp"
#include "tests/test_shapes.cpp"

int main() {
    // TestVector::test_all();
    TestShapes::test_all();
    // const Rectangle rect(20, 10);
    // std::cout << "Rectangle area: " << rect.area() << std::endl;
    // std::cout << "Rectangle perimeter: " << rect.perimeter() << std::endl;
    // std::cout << "Rectangle number of sides: " << rect.numberOfSides() << std::endl;
    // std::cout << "Rectangle details:\n" << rect << std::endl;
    //
    // const Circle circle(5);
    // std::cout << "Circle area: " << circle.area() << std::endl;
    // std::cout << "Circle perimeter: " << circle.perimeter() << std::endl;
    // std::cout << "Circle details: " << circle << std::endl;
    return 0;
}
