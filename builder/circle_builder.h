//
// Created by matteoverz on 6/4/25.
//
#pragma once

#include <complex>
#include <iostream>
#include <memory>

#include "../include/circle.h"
#include "../include/shape.h"
#include "../include/exceptions.h"
#include "../src/tests/logger.h"

class CircleBuilder {
    Logger &logger = Logger::instance();
    double radius;
    std::complex<double> center;

public:
    CircleBuilder() : radius(0), center(0, 0) {}

    CircleBuilder& setRadius(double r) {
        radius = r;
        return *this;
    }

    CircleBuilder& setCenter(const std::complex<double>& c) {
        center = c;
        return *this;
    }

    void verify() const {
        if (radius < 0) {
            throw InvalidRadiusException("Radius must be non-negative");
        }
    }

    std::unique_ptr<Shape> build() const {
        try {
            verify();
            return std::make_unique<Circle>(center, radius);
        } catch (const InvalidRadiusException& e) {
            logger.print_error(std::cerr, "Failed to build Circle", e.what());
            return nullptr;
        }
    }
};
