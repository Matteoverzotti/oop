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

class PolygonBuilder {
    Logger &logger = Logger::instance();
    std::vector<std::complex<double>> points;

public:
    PolygonBuilder() = default;

    PolygonBuilder& addPoint(const std::complex<double> &point) {
        points.push_back(point);
        return *this;
    }

    PolygonBuilder& addPoints(const std::vector<std::complex<double>> &new_points) {
        points.insert(points.end(), new_points.begin(), new_points.end());
        return *this;
    }

    PolygonBuilder& setPoints(const std::vector<std::complex<double>> &new_points) {
        points = new_points;
        return *this;
    }

    void verify() const {
        if (points.size() < 3) {
            throw InvalidPolygonException("A polygon must have at least 3 points.");
        }
        for (const auto& point : points) {
            if (std::isnan(point.real()) || std::isnan(point.imag())) {
                throw InvalidPolygonException("Polygon points must be valid complex numbers.");
            }
        }
    }

    std::unique_ptr<Shape> build() const {
        try {
            verify();
            return std::make_unique<Polygon>(points);
        } catch (const ShapeException& e) {
            logger.print_error(std::cerr, "Failed to build Polygon", e.what());
            return nullptr;
        }
    }
};
