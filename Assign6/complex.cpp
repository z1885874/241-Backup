#include "complex.h"

using namespace std;

/**
 * default constructor
 * @param real: real part of complex number, defaults to 0.
 * @param imaginary: imaginary part of complex number, defaults to zero.
 **/

complex::complex (double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

/**
 * sets real and imaginary
 * @param real: real part of complex number
 * @param imaginary: imaginary part of complex number.
 **/


void complex::set_complex(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

/**
 * gets real and imaginary parts
 * @return a tuple<double, double> with the real and imaginary parts
 **/	


tuple<double, double> complex::get_complex() const
{
	tuple<double, double> result = make_tuple(real, imaginary);
    return result;	
} 

/**
 * sets real 
 * @param real: new real value
 **/

void complex::set_real(double real)
{
	this->real = real;
}

/**
 * gets real
 * @return the real value
 **/
 
double complex::get_real() const
{
	return this->real;
}

/**
 * sets imaginary
 * @param imaginary: the new imaginary value
 **/
 
void complex::set_imaginary (double imaginary)
{
	this->imaginary = imaginary;
}

/**
 * gets imaginary
 * @return imaginary: the new imaginary value
 **/
 
double complex::get_imaginary() const
{
	return this->imaginary;
}

/**
 * adds 2 complex numbers together
 * @param rhs : right hand side of the operator
 * @return the sum of the two added numbers
 **/
 
complex complex::operator+(const complex& rhs) const
{
	complex add;
	add.set_real(this->get_real() + rhs.get_real());
	add.set_imaginary(this->get_imaginary() + rhs.get_imaginary());
	return add;
}

/**
 * multiplies 2 complex numbers together
 * @param rhs: right hand side of the operator
 * @return the product of the two multiplied numbers
 **/

complex complex::operator*(const complex& rhs) const
{
	complex prod;
	prod.set_real((this->get_real() * rhs.get_real()) - (this->get_imaginary() * rhs.get_imaginary()));
	prod.set_imaginary((this->get_real() * rhs.get_imaginary()) + (this->get_imaginary() * rhs.get_real()));
	return prod;
}

/**
 * checks if equal
 * @param rhs : right hand side of the operator
 * @return true if the real and imaginary parts are the same else false.
 **/

bool complex::operator==(const complex& rhs) const
{
	return(rhs.get_real() == this->get_real() && rhs.get_imaginary() == this->get_imaginary());
}

/**
 * inserts formatted string into outpur stream
 * @param os: the output stream
 * @param c: the complex number
 * @return os: output stream object
 **/
 
std::ostream& operator<<(std::ostream& os, const complex& c)
{
	os << "(" << c.get_real() << ", " << c.get_imaginary() << ")";
	return os;
}

/**
 * extracts a complex number from input stream
 * @param is: the input stream
 * @param c: the complex number
 * @param is: input stream object.
 **/
 
std::istream& operator>>(std::istream& is, complex& c)
{
	char E;
	is >> E >> c.real >> E >> c.imaginary >> E;
	return is;
}
