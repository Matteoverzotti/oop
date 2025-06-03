//
// Created by matteoverz on 6/3/25.
//

#include "../include/circle.h"

#include "../include/constants.h"

Circle::Circle() : center(0, 0), radius(0) {
}

Circle::Circle(const std::complex<double> center, const double radius) : center(center), radius(radius) {}

Circle::Circle(const std::pair<double, double> &center, const double radius) {
    this->center = std::complex(center.first, center.second);
    this->radius = radius;
}

Circle::Circle(const double radius) : center(0, 0), radius(radius) {}

Circle::Circle(const Circle &other) : CurvedShape(other) {
    this->center = other.center;
    this->radius = other.radius;
}

double Circle::area() const {
    return Constants::PI * radius * radius;
}

double Circle::perimeter() const {
    return 2.0 * Constants::PI * radius;
}

void Circle::print(std::ostream &os) const {
    os << "center: " << center << " radius: " << radius;
}

