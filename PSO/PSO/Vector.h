#pragma once
#include<math.h>
class Vector
{

public:
	long double x, y;

	Vector unitVector();
	Vector operator *(long double x);
	Vector operator +(Vector v);
	Vector operator -(Vector v);
	long double squaredLength();

	Vector();
	Vector(long double x, long double y);
	~Vector();
};

