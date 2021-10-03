/*

triangle.cpp
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#include "triangle.h"
/**
default constructor
@param color = the color of the shape
@param height = the height of the triangle
@param width = the width of the triangle
**/
triangle::triangle(const std::string& color, int height, int width):shape(color)
{
this->height = height;
this->width = width;
}
/**
default deconstructor
**/
triangle::~triangle()
{

}
/*
print description of shape
*/
void triangle::print() const
{
shape::print();
std::cout << "triangle, height " << height << ", width " << width << ", area " << area() << std::endl;
}

/*
calculates area
@return: the area of the triangle
*/
double triangle::area() const
{
    return static_cast<double>(width * height) * 0.5;
}