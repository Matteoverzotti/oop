//
// Created by matteoverz on 6/3/25.
//

#include "../include/rectangle.h"

#include <algorithm>

#include "../include/constants.h"
#include "../include/exceptions.h"

Rectangle::Rectangle() : width(0), height(0) {}

Rectangle::Rectangle(const double w, const double h) {
    if (w < 0 || h < 0) {
        throw InvalidDimensionsException("Width and height must be non-negative.");
    }
    this->width = w;
    this->height = h;
}

Rectangle::Rectangle(const std::vector<std::complex<double>> &points) {
    if (points.size() != 4) {
        throw InvalidPolygonException("A rectangle must have exactly 4 points.");
    }
    if (std::ranges::any_of(points, [](const std::complex<double>& p) {
        return std::isnan(p.real()) || std::isnan(p.imag());
    })) {
        throw InvalidPolygonException("Rectangle points must be valid complex numbers.");
    }

    // Assuming points are given in order: bottom-left, bottom-right, top-right, top-left
    width = std::fabs(points[1].real() - points[0].real());
    height = std::fabs(points[2].imag() - points[0].imag());
    if (width < 0 || height < 0) {
        throw InvalidDimensionsException("Width and height must be non-negative.");
    }

    if (std::abs(points[0].real() - points[1].real()) != width ||
        std::abs(points[0].imag() - points[3].imag()) != height ||
        std::abs(points[1].imag() - points[2].imag()) != height ||
        std::abs(points[2].real() - points[3].real()) != width) {
        throw InvalidPolygonException("Points do not form a valid rectangle.");
    }

    // Dot product to check for right angles
    const std::complex<double> v1 = points[1] - points[0]; // Bottom edge
    const std::complex<double> v2 = points[3] - points[0]; // Left edge
    if (std::abs(v1.real() * v2.real() + v1.imag() * v2.imag()) > Constants::EPSILON) {
        throw InvalidPolygonException("Points do not form a valid rectangle with right angles.");
    }

    this->points = points;
    this->width = std::fabs(points[1].real() - points[0].real());
    this->height = std::fabs(points[2].imag() - points[0].imag());
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

size_t Rectangle::numberOfSides() const {
    return 4;
}

void Rectangle::print(std::ostream &os) const {
    os << "width: " << width << " heigth: " << height << '\n';
}
