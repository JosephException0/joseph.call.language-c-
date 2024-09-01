#include <iostream>
#include <iomanip>
#include "imports.hpp"
 
void testConstructor(double radius) {
    std::cout << "Testing Constructor" << std::endl;
    Circle circle(radius);
    std::cout << "Circle created with radius " << radius 
<< " (Expected: " << radius << ", Your code's radius: " 
<< circle.radius << ")\n" << std::endl;
}
 
void testArea(Circle& circle) {
    std::cout << "Testing Area" << std::endl;
    std::cout << "Area of circle with radius " << circle.radius 
<< " (Expected: " << std::fixed << std::setprecision(2) 
<< M_PI * std::pow(circle.radius, 2) << ", Your code's output: " 
<< circle.getArea() << ")\n" << std::endl;
}
 
void testCircumference(Circle& circle) {
    std::cout << "Testing Circumference" << std::endl;
    std::cout << "Circumference of circle with radius " << circle.radius 
<< " (Expected: " << std::fixed << std::setprecision(2) 
<< 2 * M_PI * circle.radius << ", Your code's output: " 
<< circle.getCircumference() << ")\n" << std::endl;
}
 
int main() {
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    Circle circle(radius);
 
    int testCase;
    std::cout << "Enter the test case number (1 for Constructor, 2 for Area, 3 for Circumference): ";
    std::cin >> testCase;
 
    switch (testCase) {
        case 1:
            testConstructor(radius);
            break;
        case 2:
            testArea(circle);
            break;
        case 3:
            testCircumference(circle);
            break;
        default:
            std::cout << "Invalid test case number" << std::endl;
            break;
    }
 
    return 0;
}