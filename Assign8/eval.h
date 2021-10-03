/*

eval.h
CSCI 241 Assign 8

Created by Christopher Huguelet (z1885874)
Section 2

*/

#ifndef EVAL_H
#define EVAL_H
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include "mystack.h"
#include "inpost.h"

int evaluate(const std::string&);
bool isbin(const std::string&);
int stringtoint(const std::string&);
int calculate(int, int, std::string&);


#endif
