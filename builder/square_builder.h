//
// Created by matteoverz on 6/4/25.
//
#pragma once

#include <algorithm>
#include <iostream>
#include <memory>

#include "../include/constants.h"
#include "../include/exceptions.h"
#include "../include/rectangle.h"
#include "../include/shape.h"
#include "../include/square.h"
#include "../src/tests/logger.h"

class SquareBuilder {
    Logger &logger = Logger::instance();
    double size;

public:
    SquareBuilder() : size(0) {}

    SquareBuilder& setSize(const double size) {
        this->size = size;
        return *this;
    }

    void verify() const {
        if (size < 0)
            throw InvalidDimensionsException("Size must be non-negative.");
    }

    std::unique_ptr<Shape> build() const {
        try {
            verify();
            return std::make_unique<Square>(size);
        } catch (const InvalidDimensionsException& e) {
            logger.print_error(std::cerr, "Failed to build Square", e.what());
            return nullptr;
        }
    }
};
