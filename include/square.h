//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include "polygon.h"
#include "rectangle.h"

class Square : public Polygon {
protected:
    double size;

public:
    Square();
    Square(double l);
    Square(const std::vector<std::complex<double>> &points);
    Square(const Square &other);
    Square(const Rectangle &other);
    ~Square() override = default;

    double area() const override;
    double perimeter() const override;

    size_t numberOfSides() const override;
    void print(std::ostream &os) const override;
};
