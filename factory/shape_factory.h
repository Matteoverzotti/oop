//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include "../include/shape.h"

enum ShapeType {
    SHAPE, // Base class, not instantiable
    CIRCLE,
    RECTANGLE,
    POLYGON
};

class ShapeFactory {
public:
    static Shape* create(ShapeType type);
};
