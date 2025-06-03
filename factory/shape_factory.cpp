//
// Created by matteoverz on 6/3/25.
//

#include "shape_factory.h"

Shape * ShapeFactory::create(const ShapeType type) {
    switch (type) {
        case CIRCLE:
            return new Circle();
        case RECTANGLE:
            return new Rectangle();
        case POLYGON:
            return new Polygon();
        default:
            throw std::invalid_argument("Unknown shape type");
    }
}
