//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <cmath>

namespace Constants {
    const double PI = std::acos(-1);
    constexpr double EPSILON = 1e-9;
}

namespace LoggerColors {
    const std::string RED = "\033[1;31m";
    const std::string GREEN = "\033[1;32m";
    const std::string YELLOW = "\033[1;33m";
    const std::string BLUE = "\033[1;34m";
    const std::string RESET = "\033[0m";
}