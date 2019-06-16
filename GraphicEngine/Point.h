#pragma once
#include "Line.h"

template <class T>
struct Point
{
	T x;
	T y;
public:
	Point(T x, T y)
		: x(x), y(y)
	{	}

	Point(Line* line1, Line* line2);

	~Point();
};

template <class T>
struct Point3D
{
	T x;
	T y;
	T z;
};
