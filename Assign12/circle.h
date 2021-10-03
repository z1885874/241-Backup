/*

circle.h
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <math.h>

class circle:public shape
{
private:
int radius = 0;


public:
circle(const std::string& = "egg",int =0);
virtual ~circle();
virtual void print() const;
virtual double area() const;
};


#endif