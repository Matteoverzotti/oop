//
// Created by matteoverz on 6/3/25.
//

#include "../include/polygon.h"

#include <complex>

int Polygon::numberOfSides() const {
    return 0;
}

double Polygon::area() const {
    double totalArea = 0.0;
    for (size_t i = 0; i < points.size(); ++i) {
        const auto& p1 = points[i];
        const auto& p2 = points[(i + 1) % points.size()];
        totalArea += (p1.real() * p2.imag()) - (p2.real() * p1.imag());
    }
    return std::abs(totalArea) / 2.0;
}

double Polygon::perimeter() const {
    double totalPerimeter = 0.0;
    for (size_t i = 0; i < points.size(); ++i) {
        const auto& p1 = points[i];
        const auto& p2 = points[(i + 1) % points.size()];
        totalPerimeter += std::abs(p2 - p1);
    }
    return totalPerimeter;
}

void Polygon::print(std::ostream &os) const {
    os << "Polygon with " << points.size() << " sides:\n";
    for (const auto& point : points) {
        os << "(" << point.real() << ", " << point.imag() << ")\n";
    }
}

std::ostream& operator<<(std::ostream &os, const Polygon &polygon) {
    polygon.print(os);
    return os;
}

