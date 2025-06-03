//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <ostream>

class Shape {
protected:
    std::string color;
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Shape& s) {
    s.print(os);
    return os;
}