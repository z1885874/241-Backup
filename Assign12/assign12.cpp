/*

assign12.cpp
CSCI 241 Assign12

Created by Christopher Huguelet (z1885874)
Section 2

*/

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <vector>

int main()
{
std::vector<shape*> shapegg;
shapegg.push_back(new circle("red", 8));
shapegg.push_back(new circle("orange", 2));
shapegg.push_back(new rectangle("chartruesse", 4, 1));
shapegg.push_back(new rectangle("burghundy", 5, 12));
shapegg.push_back(new triangle("periwinkle", 7, 7));
shapegg.push_back(new triangle("coral blue #5", 3, 11));
std::cout << std::endl << "printing all shapes: " << std::endl << std::endl;
for(auto shape: shapegg)
{
    shape->print();
}
std::cout << std::endl << "printing only circles: " << std::endl << std::endl;
for(auto shape: shapegg)
{
    if (dynamic_cast<circle*>(shape))
    shape->print();
}

size_t size = shapegg.size();
for (size_t i = 0; i < size; i++)
{
    shape* s = shapegg.back();
    shapegg.pop_back();
    delete s;
}
return 0;
}