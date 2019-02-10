#include<iostream>
using namespace std;
#include<iomanip>
#include "Vector.h"



Vector Vector::unitVector()
{
	long double t = (1.0 / sqrt(x * x + y * y));
	Vector v = *this * (t);
	return v;
}

Vector Vector::operator*(long double n)
{
	Vector v= Vector(this->x*n, this->y*n);
	return v;
}

Vector Vector::operator+(Vector v)
{
	return Vector(this->x + v.x, this->y + v.y);
}

Vector Vector::operator-(Vector v)
{
	return Vector(this->x - v.x, this->y - v.y);
}

long double Vector::squaredLength()
{
	return (x * x + y * y);
}

Vector::Vector()
{
	x = y = 0;
}

Vector::Vector(long double x, long double y)
{
	this->x = x;
	this->y = y;
	
}


Vector::~Vector()
{
}
