//
// Created by matteoverz on 6/2/25.
//
#include "../builder/circle_builder.h"
#include "../builder/polygon_builder.h"
#include "../builder/rectangle_builder.h"
#include "../factory/shape_factory.h"
#include "../include/circle.h"
#include "../include/curved_rectangle.h"
#include "../include/rectangle.h"
#include "../include/shape_collection.h"
#include "../include/vector.h"
#include "tests/test_shapes.cpp"

int main() {
    ShapeCollection collection;
    collection.addShape(std::make_shared<Circle>(5.0));
    collection.addShape(std::make_shared<Circle>(5.0));
    collection.addShape(std::make_shared<Rectangle>(4.0, 6.0));

    collection.addShape(ShapeFactory::create(CIRCLE));
    collection.addShape(ShapeFactory::create(RECTANGLE));
    collection.addShape(ShapeFactory::create(POLYGON));
    collection.printShapes();

    std::unique_ptr<Shape> poly = PolygonBuilder()
        .addPoint({0, 0})
        .addPoint({1, 0})
        .addPoint({1, 1})
        .addPoint({0, 1})
        .build();

    collection.addShape(std::move(poly));
    CurvedRectangle curvedRect(4.0, 3.0, 1.0);
    collection.addShape(std::make_shared<CurvedRectangle>(curvedRect));

    collection.addShape(ShapeFactory::create(CURVED_RECTANGLE));
    collection.printShapes();
    return 0;
}
