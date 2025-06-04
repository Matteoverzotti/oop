//
// Created by matteoverz on 6/3/25.
//

#include "shape_factory.h"

#include "../builder/circle_builder.h"
#include "../builder/curved_rectangle_builder.h"
#include "../builder/polygon_builder.h"
#include "../builder/rectangle_builder.h"
#include "../builder/square_builder.h"

std::unique_ptr<Shape> ShapeFactory::create(const ShapeType type) {
    switch (type) {
        case CIRCLE:
            return CircleBuilder().build();
        case RECTANGLE:
            return RectangleBuilder().build();
        case POLYGON:
            return PolygonBuilder().setPoints({{0, 0}, {0, 1}, {1, 0}}).build();
        case CURVED_RECTANGLE:
            return CurvedRectangleBuilder().build();
        case SQUARE:
            return SquareBuilder().setSize(1.0).build();
        default:
            throw std::invalid_argument("Unknown shape type");
    }
}
