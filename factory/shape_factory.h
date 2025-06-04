//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <memory>

#include "../include/shape.h"

enum ShapeType {
    SHAPE, // Base class, not instantiable
    CIRCLE,
    RECTANGLE,
    CURVED_RECTANGLE,
    POLYGON
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> create(ShapeType type);
};
