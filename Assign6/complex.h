/*CSCI 241       Assignment 6   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 3/4/2021
Purpose: this program is created in order to simulate a simple computer called simplesim
*/

#ifndef COMPLEX_H
#define COMPLEX_H
#include <tuple>
#include <iostream>

class complex
{
private:
    double real;
    double imaginary;

public:
    complex(double = 0, double = 0);
    void set_complex(double, double);
    std::tuple<double,double> get_complex() const;
    void set_real(double);
    double get_real() const; 
    void set_imaginary(double);
    double get_imaginary() const; 
    complex operator+(const complex&) const;
    complex operator*(const complex&) const;
    bool operator==(const complex&) const;
    friend std::ostream& operator<<(std::ostream&, const complex&);
    friend std::istream& operator>>(std::istream&, complex&);
};

#endif
