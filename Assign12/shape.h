/*

shape.h
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

class shape
{
private:
std::string color = "";

public:
shape(const std::string& = "egg");
virtual ~shape();
virtual void print() const;
virtual double area() const = 0;
};


#endif