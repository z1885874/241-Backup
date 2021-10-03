/*

circle.cpp
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#include "circle.h"
/**
default constructor
@param color = the color of the shape
@param radius: the radius of the circle
**/
circle::circle(const std::string& color, int radius):shape(color)
{
this->radius = radius;
}
/**
default deconstructor
**/
circle::~circle()
{

}
/*
print description of shape
*/
void circle::print() const
{
shape::print();
std::cout << "circle, radius " << radius << ", area " << area() << std::endl;
}
/*
calculates area
@return: the area of the circle
*/
double circle::area() const
{
    return M_PI * radius * radius;
}