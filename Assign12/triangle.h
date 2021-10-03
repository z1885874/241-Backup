/*

triangle.h
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class triangle:public shape
{
private:
int height = 0, width = 0;


public:
triangle(const std::string& = "egg",int = 0, int = 0);
virtual ~triangle();
virtual void print() const;
virtual double area() const;
};


#endif