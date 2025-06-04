//
// Created by matteoverz on 6/4/25.
//

#pragma once
#include "curved_shape.h"
#include "polygon.h"
#include "rectangle.h"


class CurvedRectangle : public CurvedShape, public Rectangle {
    double cornerRadius;

public:
    CurvedRectangle(double w, double h, double r);
    CurvedRectangle();
    ~CurvedRectangle() override;

    size_t numberOfPoints() const override;

    size_t numberOfSides() const override;

    double area() const override;

    double perimeter() const override;

    void print(std::ostream &os) const override;
};
