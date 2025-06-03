//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <memory>
#include <vector>

#include "shape.h"
#include "../src/tests/logger.h"

class ShapeCollection {
    std::vector<std::shared_ptr<Shape>> shapes;
    Logger &logger = Logger::instance();
public:
    ~ShapeCollection();

    void add_shape(const std::shared_ptr<Shape>& shape);
    void remove_shape(int id);
    void print_shapes() const;
};
