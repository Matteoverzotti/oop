//
// Created by matteoverz on 6/3/25.
//
#pragma once

#include <stdexcept>
#include <string>

class ShapeException : public std::runtime_error {
public:
    explicit ShapeException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class InvalidRadiusException : public ShapeException {
public:
    explicit InvalidRadiusException(const std::string& msg)
        : ShapeException(msg) {}
};

class InvalidDimensionsException : public ShapeException {
public:
    explicit InvalidDimensionsException(const std::string& msg)
        : ShapeException(msg) {}
};

class InvalidPointsException : public ShapeException {
public:
    explicit InvalidPointsException(const std::string& msg)
        : ShapeException(msg) {}
};