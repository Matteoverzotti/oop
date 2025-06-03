//
// Created by matteoverz on 6/3/25.
//

#include "../include/rectangle.h"

#include "../include/exceptions.h"

Rectangle::Rectangle(const double w, const double h) {
    if (w < 0 || h < 0) {
        throw InvalidDimensionsException("Width and height must be non-negative.");
    }
    this->width = w;
    this->height = h;
}

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
