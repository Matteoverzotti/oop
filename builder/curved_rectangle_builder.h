//
// Created by matteoverz on 6/4/25.
//
#pragma once

#include <iostream>
#include <memory>

#include "../include/curved_rectangle.h"
#include "../include/exceptions.h"
#include "../include/shape.h"
#include "../src/tests/logger.h"

class CurvedRectangleBuilder {
    Logger &logger = Logger::instance();
    double width;
    double height;
    double radius;

public:
    CurvedRectangleBuilder() : width(0), height(0), radius(0) {}

    CurvedRectangleBuilder& setWidth(const double width) {
        this->width = width;
        return *this;
    }

    CurvedRectangleBuilder& setHeight(const double height) {
        this->height = height;
        return *this;
    }

    CurvedRectangleBuilder& setRadius(const double radius) {
        this->radius = radius;
        return *this;
    }

    void verify() const {
        if (width < 0 || height < 0 || radius < 0) {
            throw InvalidDimensionsException("Width, height, and radius must be non-negative.");
        }
    }

    std::unique_ptr<Shape> build() const {
        try {
            verify();
            return std::make_unique<CurvedRectangle>(width, height, radius);
        } catch (const InvalidDimensionsException& e) {
            logger.print_error(std::cerr, "Failed to build CurvedRectangle", e.what());
            return nullptr;
        }
    }
};
