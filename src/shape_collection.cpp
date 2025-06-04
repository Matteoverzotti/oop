//
// Created by matteoverz on 6/3/25.
//

#include "../include/shape_collection.h"

#include <iostream>
#include <algorithm>

#include "../include/circle.h"
#include "../include/constants.h"
#include "../include/curved_rectangle.h"
#include "../include/rectangle.h"

ShapeCollection::~ShapeCollection() {
    logger.log(std::cout, "ShapeCollection destructor called, deleting shapes", LoggerColors::YELLOW);
    for (auto& shape : shapes) {
        logger.log(std::cout, "Deleting shape: " + std::string(typeid(*shape).name()), LoggerColors::YELLOW);
        shape.reset();  // Explicitly reset shared_ptr to release resources
    }
}

void ShapeCollection::addShape(const std::shared_ptr<Shape>& shape) {
    shapes.push_back(shape);
    logger.log(std::cout, "Added shape: " + std::string(typeid(*shape).name()) + " with id: " + std::to_string(shape->get_id()), LoggerColors::GREEN);
}

void ShapeCollection::removeShape(const int id) {
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        if ((*it)->get_id() == id) {
            logger.log(std::cout, "Removing shape with ID: " + std::to_string(id), LoggerColors::YELLOW);
            shapes.erase(it);
            return;
        }
    }
}

void ShapeCollection::printShapes() const {
    for (const auto& shape : shapes) {
        if (dynamic_cast<Rectangle*>(shape.get())) {
            logger.log(std::cout, "Rectangle: " + std::to_string(shape->get_id()), LoggerColors::BLUE);
        } else if (dynamic_cast<Circle*>(shape.get())) {
            logger.log(std::cout, "Circle: " + std::to_string(shape->get_id()), LoggerColors::BLUE);
        } else if (dynamic_cast<CurvedRectangle*>(shape.get())) {
            logger.log(std::cout, "Curved Rectangle: " + std::to_string(shape->get_id()), LoggerColors::BLUE);
        } else if (dynamic_cast<Polygon*>(shape.get())) {
            logger.log(std::cout, "Polygon: " + std::to_string(shape->get_id()), LoggerColors::BLUE);
        } else {
            logger.log(std::cout, "Unknown shape type with ID: " + std::to_string(shape->get_id()), LoggerColors::RED);
        }
    }
}
