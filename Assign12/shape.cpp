/*

shape.cpp
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#include "shape.h"
/**
default constructor
@param color = the color of the shape
**/
shape::shape(const std::string& color)
{
this->color = color;
}
/**
default deconstructor
**/
shape::~shape()
{

}
/*
print description of shape
*/
void shape::print() const
{
std::cout << color << " " ;
}
