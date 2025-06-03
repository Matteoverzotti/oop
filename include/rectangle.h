//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include "polygon.h"

class Rectangle : public Polygon {
    double width, height;

public:
    Rectangle(double w, double h);
    ~Rectangle() override = default;

    double area() const override;
    double perimeter() const override;
    int numberOfSides() const override;
    void print(std::ostream &os) const override;

};
