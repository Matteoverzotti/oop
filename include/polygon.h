//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <vector>
#include <complex>

#include "shape.h"

class Polygon : virtual public Shape {
protected:
    std::vector<std::complex<double>> points;
public:
    Polygon();
    Polygon(std::vector<std::complex<double>> points);

    ~Polygon() override = default;

    virtual size_t numberOfPoints() const;
    virtual size_t numberOfSides() const;

    double area() const override;

    double perimeter() const override;

    void print(std::ostream &os) const override;
};

std::ostream& operator<<(std::ostream &os, const Polygon &polygon);
