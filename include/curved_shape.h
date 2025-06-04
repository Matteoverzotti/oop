//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include "shape.h"

class CurvedShape : virtual public Shape {
public:
    CurvedShape() = default;
    CurvedShape(const CurvedShape &other) = default;
    ~CurvedShape() override = default;
};