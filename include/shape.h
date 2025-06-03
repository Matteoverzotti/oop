//
// Created by matteoverz on 6/3/25.
//

#pragma once
#include <ostream>

class Shape {
protected:
    int id;
    static int next_id;
public:
    Shape();
    virtual ~Shape() = default;
    int get_id() const;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print(std::ostream& os) const;
};