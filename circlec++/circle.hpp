#ifndef CIRCLE_H
#define CIRCLE_H
 
#include <cmath>
 
class Circle {
public:
    double radius;
 
    Circle(double radius) : radius(radius) {}
 
    double getArea() {
        return M_PI * std::pow(radius, 2);
    }
 
    double getCircumference() {
        return 2 * M_PI * radius;
    }
};
 
#endif