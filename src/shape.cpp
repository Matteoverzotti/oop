//
// Created by matteoverz on 6/3/25.
//

#include "../include/shape.h"

int Shape::next_id = 0;
Shape::Shape(): id(next_id) {
    next_id++;
}

void Shape::print(std::ostream &os) const {
    os << "Shape ID: " << id << "\n";
    os << "Area: " << area() << "\n";
    os << "Perimeter: " << perimeter() << "\n";
}

std::ostream& operator<<(std::ostream& os, const Shape& s) {
    s.print(os);
    return os;
}
