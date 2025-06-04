//
// Created by matteoverz on 6/4/25.
//
#pragma once

#include <iostream>
#include <memory>

#include "../include/exceptions.h"
#include "../include/rectangle.h"
#include "../include/shape.h"
#include "../src/tests/logger.h"

class RectangleBuilder {
    Logger &logger = Logger::instance();
    double width;
    double height;

public:
    RectangleBuilder() : width(0), height(0) {}

    RectangleBuilder& setWidth(const double width) {
        this->width = width;
        return *this;
    }

    RectangleBuilder& setHeight(const double height) {
        this->height = height;
        return *this;
    }

    void verify() const {
        if (width < 0 || height < 0) {
            throw InvalidDimensionsException("Width and height must be non-negative.");
        }
    }

    std::unique_ptr<Shape> build() const {
        try {
            verify();
            return std::make_unique<Rectangle>(width, height);
        } catch (const InvalidDimensionsException& e) {
            logger.print_error(std::cerr, "Failed to build Rectangle", e.what());
            return nullptr;
        }
    }
};
