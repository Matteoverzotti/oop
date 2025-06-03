//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <complex>

#include "curved_shape.h"

class Circle : public CurvedShape {
    std::complex<double> center;
    double radius;
public:
    Circle();
    Circle(std::complex<double> center, double radius);
    Circle(const std::pair<double, double> &center, double radius);
    Circle(double radius);
    Circle(const Circle& other);
    ~Circle() override = default;

    double area() const override;

    double perimeter() const override;

    void print(std::ostream &os) const override;
};

std::ostream& operator<<(std::ostream &os, const Circle &circle);
