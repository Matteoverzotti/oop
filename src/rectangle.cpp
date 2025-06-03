//
// Created by matteoverz on 6/3/25.
//

#include "../include/rectangle.h"

Rectangle::Rectangle(const double w, const double h) : width(w), height(h) {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

int Rectangle::numberOfSides() const {
    return 4;
}

void Rectangle::print(std::ostream &os) const {
    os << "width: " << width << " heigth: " << height << '\n';
}
