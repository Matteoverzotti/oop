//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <vector>
#include <complex>

#include "shape.h"

class Polygon : public Shape {
protected:
    std::vector<std::complex<double>> points;
public:
    ~Polygon() override = default;
    virtual int numberOfSides() const;

    double area() const override;

    double perimeter() const override;

    void print(std::ostream &os) const override;
};
