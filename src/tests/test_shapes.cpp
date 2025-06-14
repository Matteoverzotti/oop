//
// Created by matteoverz on 6/3/25.
//

#include "base_test.h"
#include "../../include/constants.h"
#include "../../include/exceptions.h"
#include "../../include/polygon.h"
#include "../../include/shape.h"
#include "../../include/rectangle.h"
#include "../../include/circle.h"
#include "../../include/square.h"

class TestShapes : public BaseTest {
    static void polygon_constructor() {
        base("Default polygon constructor", []() {
            const Polygon x;
            if (x.numberOfPoints() != 0) {
                throw std::runtime_error("Polygon should have 0 points by default");
            }
            if (x.numberOfSides() != 0) {
                throw std::runtime_error("Polygon should have 0 sides by default");
            }
            if (x.area() != 0) {
                throw std::runtime_error("Polygon area should be 0 by default");
            }
            if (x.perimeter() != 0) {
                throw std::runtime_error("Polygon perimeter should be 0 by default");
            }
        });

        base("Rectangular polygon constructor", []() {
            const Polygon rect({
            {0, 0}, {4, 0}, {4, 3}, {0, 3}
            });
            if (rect.numberOfPoints() != 4) {
                throw std::runtime_error("Rectangle should have 4 points");
            }
            if (rect.numberOfSides() != 4) {
                throw std::runtime_error("Rectangle should have 4 sides");
            }
            if (fabs(rect.area() - 12.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle area should be 12");
            }
            if (fabs(rect.perimeter() - 14.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle perimeter should be 14");
            }
        });

        base("Irregular polygon constructor", []() {
            const Polygon irregular({
            {1, 5}, {4, 2}, {6, 6}, {3, 8}, {1, 7}
            });
            if (irregular.numberOfPoints() != 5) {
                throw std::runtime_error("Irregular polygon should have 5 points");
            }
            if (irregular.numberOfSides() != 5) {
                throw std::runtime_error("Irregular polygon should have 5 sides");
            }
            if (fabs(irregular.area() - 17.5) > Constants::EPSILON) {
                throw std::runtime_error("Irregular polygon area should be 17.5");
            }
            if (fabs(irregular.perimeter() - 16.5563958951) > Constants::EPSILON) {
                throw std::runtime_error("Irregular polygon perimeter should be 16.5563958951");
            }
        });
    }

    static void rectangle_constructor() {
        base("Default rectangle constructor", []() {
            const Rectangle rect;
            if (fabs(rect.area() - 0.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle area should be 0 by default");
            }
            if (fabs(rect.perimeter() - 0.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle perimeter should be 0 by default");
            }
        });

        base("Incorrect rectangle constructor with negative dimensions", []() {
            try {
                const Rectangle rect(-5, 10);
            } catch (const InvalidDimensionsException& e) {
                // Expected exception
            }
        });

        base("Rectangle constructor with valid dimensions", []() {
            const Rectangle rect(5, 10);
            if (fabs(rect.area() - 50.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle area should be 50");
            }
            if (fabs(rect.perimeter() - 30.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle perimeter should be 30");
            }
        });

        base("Rectangle constructor with points", []() {
            const Rectangle rect({
                {0, 0}, {4, 0}, {4, 3}, {0, 3}
            });
            if (fabs(rect.area() - 12.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle area should be 12");
            }
            if (fabs(rect.perimeter() - 14.0) > Constants::EPSILON) {
                throw std::runtime_error("Rectangle perimeter should be 14");
            }
        });

        base("Rectangle constructor with invalid points", []() {
            try {
                const Rectangle rect({
                    {0, 0}, {4, 0}, {4, 3}
                });
            } catch (const InvalidPolygonException& e) {
                // Expected exception
            }

            try {
                const Rectangle rect({
                    {0, 0}, {4, 0}, {4, 3}, {0, 3}, {1, 1}
                });
            } catch (const InvalidPolygonException& e) {
                // Expected exception
            }
        });

        base("Rectangle constructor without 90 degrees", []() {
            try {
                const Rectangle rect({
                    {0, 0}, {4, 0}, {4, 3}, {1, 3}
                });
            } catch (const InvalidPolygonException& e) {
                // Expected exception
            }
        });
    }

    static void square_constructor() {
        base("Default square constructor", []() {
            const Square sq;
            if (fabs(sq.area() - 0.0) > Constants::EPSILON) {
                throw std::runtime_error("Square area should be 0 by default");
            }
            if (fabs(sq.perimeter() - 0.0) > Constants::EPSILON) {
                throw std::runtime_error("Square perimeter should be 0 by default");
            }
        });

        base("Incorrect square constructor with negative dimensions", []() {
            try {
                const Square sq(-5);
            } catch (const InvalidDimensionsException& e) {
                // Expected exception
            }
        });

        base("Square constructor with valid dimensions", []() {
            const Square sq(6);
            if (fabs(sq.area() - 36.0) > Constants::EPSILON) {
                throw std::runtime_error("Square area should be 36");
            }
            if (fabs(sq.perimeter() - 24.0) > Constants::EPSILON) {
                throw std::runtime_error("Square perimeter should be 24");
            }
        });

        base("Square constructor with valid points", []() {
            const Square sq({
                {0, 0}, {4, 0}, {4, 4}, {0, 4}
            });
            if (fabs(sq.area() - 16.0) > Constants::EPSILON) {
                throw std::runtime_error("Square area should be 16");
            }
            if (fabs(sq.perimeter() - 16.0) > Constants::EPSILON) {
                throw std::runtime_error("Square perimeter should be 16");
            }
        });

        base("Square constructor with invalid points", []() {
            try {
                const Square sq({
                    {0, 0}, {4, 0}, {4, 3}
                });
                throw std::runtime_error("Square should not allow less than 4 points");
            } catch (const InvalidPolygonException& e) {
                // Expected exception
            }

            try {
                const Square sq({
                    {0, 0}, {4, 0}, {4, 3}, {0, 3}, {1, 1}
                });
                throw std::runtime_error("Square should not allow more than 4 points");
            } catch (const InvalidPolygonException& e) {
                // Expected exception
            }

            try {
                const Square sq({
                    {0, 0}, {4, 0}, {4, 3}, {0, 3}
                });
                throw std::runtime_error("Square should not allow points that do not form a square");
            } catch (const InvalidPolygonException& e) {
                // Expected exception
            }
        });

        base("Square constructor without 90 degrees", []() {
            try {
                const Square sq({
                    {0, 0}, {3, 1}, {0, 4}, {-3, 1}
                });
            } catch (const InvalidPolygonException& e) {
                // Expected exception
            }
        });
    }


    static void circle_constructor() {
        base("Default circle constructor", []() {
            const Circle circle;
            if (fabs(circle.area() - 0.0) > Constants::EPSILON) {
                throw std::runtime_error("Circle area should be 0 by default");
            }
            if (fabs(circle.perimeter() - 0.0) > Constants::EPSILON) {
                throw std::runtime_error("Circle perimeter should be 0 by default");
            }
        });

        base("Circle constructor with negative radius", []() {
            try {
                const Circle circle(-5);
                throw std::runtime_error("Circle should not allow negative radius");
            } catch (const InvalidRadiusException& e) {
                // Expected exception
            }
        });

        base("Circle constructor", []() {
            const Circle circle(5);
            if (fabs(circle.area() - 78.53981633974483) > Constants::EPSILON) {
                throw std::runtime_error("Circle area should be approximately 78.54");
            }
            if (fabs(circle.perimeter() - 31.41592653589793) > Constants::EPSILON) {
                throw std::runtime_error("Circle perimeter should be approximately 31.42");
            }

            const Circle circle2(std::complex<double>(3, 4), 5);
            if (fabs(circle2.area() - 78.53981633974483) > Constants::EPSILON) {
                throw std::runtime_error("Circle area should be approximately 78.54");
            }
            if (fabs(circle2.perimeter() - 31.41592653589793) > Constants::EPSILON) {
                throw std::runtime_error("Circle perimeter should be approximately 31.42");
            }
        });

        base("Circle copy constructor", []() {
            const Circle original(5);
            const Circle copy(original);
            if (fabs(copy.area() - original.area()) > Constants::EPSILON) {
                throw std::runtime_error("Circle copy constructor failed to copy area");
            }
            if (fabs(copy.perimeter() - original.perimeter()) > Constants::EPSILON) {
                throw std::runtime_error("Circle copy constructor failed to copy perimeter");
            }
        });
    }

public:
    static void test_all() {
        polygon_constructor();
        rectangle_constructor();
        square_constructor();
        circle_constructor();
    }
};
