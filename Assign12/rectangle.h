/*

rectangle.h
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle:public shape
{
private:
int height = 0, width = 0;


public:
rectangle(const std::string& = "egg",int = 0, int = 0);
virtual ~rectangle();
virtual void print() const;
virtual double area() const;
};


#endif