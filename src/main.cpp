//
// Created by matteoverz on 6/2/25.
//

#include "../include/rectangle.h"
#include "../include/vector.h"
#include "tests/test_vector.cpp"

int main() {
    const Rectangle rect(20, 10);
    std::cout << "Rectangle area: " << rect.area() << std::endl;
    std::cout << "Rectangle perimeter: " << rect.perimeter() << std::endl;
    std::cout << "Rectangle number of sides: " << rect.numberOfSides() << std::endl;
    std::cout << "Rectangle details:\n" << rect << std::endl;
    return 0;
}
