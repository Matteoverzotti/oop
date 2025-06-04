//
// Created by matteoverz on 6/4/25.
//

#include "../include/curved_rectangle.h"

#include "../include/exceptions.h"

CurvedRectangle::CurvedRectangle(const double w, const double h, const double r) {
    if (w < 0 || h < 0 || r < 0) {
        throw InvalidDimensionsException("Width, height, and radius must be non-negative.");
    }
    width = w;
    height = h;
    cornerRadius = r;
}

CurvedRectangle::CurvedRectangle() {
    cornerRadius = 0;
}

CurvedRectangle::~CurvedRectangle() = default;

size_t CurvedRectangle::numberOfPoints() const {
    return Polygon::numberOfPoints();
}

size_t CurvedRectangle::numberOfSides() const {
    return Polygon::numberOfSides();
}

double CurvedRectangle::area() const {
    return Polygon::area();
}

double CurvedRectangle::perimeter() const {
    return Polygon::perimeter();
}

void CurvedRectangle::print(std::ostream &os) const {
    Polygon::print(os);
}
