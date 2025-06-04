//
// Created by matteoverz on 6/3/25.
//

#include "../include/square.h"

#include <algorithm>

#include "../include/constants.h"
#include "../include/exceptions.h"

Square::Square() : size(0) {}

Square::Square(const double l) {
    if (l < 0) {
        throw InvalidDimensionsException("Square dimensions must be non-negative.");
    }
    this->size = l;
    this->points = {
        {0, 0}, // Bottom-left
        {l, 0}, // Bottom-right
        {l, l}, // Top-right
        {0, l}  // Top-left
    };
}

Square::Square(const std::vector<std::complex<double>> &points) {
    if (points.size() != 4) {
        throw InvalidPolygonException("A square must have exactly 4 points.");
    }
    if (std::ranges::any_of(points, [](const std::complex<double>& p) {
        return std::isnan(p.real()) || std::isnan(p.imag());
    })) {
        throw InvalidPolygonException("Square points must be valid complex numbers.");
    }

    // Assuming points are given in order: bottom-left, bottom-right, top-right, top-left
    size = std::fabs(points[1].real() - points[0].real());
    if (size < 0) {
        throw InvalidDimensionsException("Square dimensions must be non-negative.");
    }

    if (std::abs(points[0].real() - points[1].real()) != size ||
        std::abs(points[0].imag() - points[3].imag()) != size ||
        std::abs(points[1].imag() - points[2].imag()) != size ||
        std::abs(points[2].real() - points[3].real()) != size) {
        throw InvalidPolygonException("Points do not form a valid rectangle.");
    }

    // Dot product to check for right angles
    const std::complex<double> v1 = points[1] - points[0]; // Bottom edge
    const std::complex<double> v2 = points[3] - points[0]; // Left edge
    if (std::abs(v1.real() * v2.real() + v1.imag() * v2.imag()) > Constants::EPSILON) {
        throw InvalidPolygonException("Points do not form a valid rectangle with right angles.");
    }

    this->points = points;
    this->size = std::fabs(points[1].real() - points[0].real());
}

double Square::area() const {
    return size * size;
}

double Square::perimeter() const {
    return 4 * size;
}

size_t Square::numberOfSides() const {
    return 4;
}

void Square::print(std::ostream &os) const {
    Polygon::print(os);
    os << "side: " << size << '\n';
}
