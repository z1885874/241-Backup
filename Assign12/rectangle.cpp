/*

rectangle.cpp
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#include "rectangle.h"
/**
default constructor
@param color = the color of the shape
@param height = the height of the rectangle
@param width = the width of the rectangle
**/
rectangle::rectangle(const std::string& color, int height, int width):shape(color)
{
this->height = height;
this->width = width;
}
/**
default deconstructor
**/
rectangle::~rectangle()
{

}
/*
print description of shape
*/
void rectangle::print() const
{
shape::print();
std::cout << "rectangle, height " << height << ", width " << width << ", area " << area() << std::endl;
}
/*
calculates area
@return: the area of the rectangle
*/
double rectangle::area() const
{
    return width*height;
}