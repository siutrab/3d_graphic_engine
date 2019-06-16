#pragma once
#include "Point.h"

template class Point<double>;

template<class T>
struct Vector2D
{
	T x;
	T y;

	Vector2D(T x, T y) : x(x), y(y) {}

	void add(Vector2D* vector)
	{
		x += vector->x;
		y += vector->y;
	}

	static Vector2D* createFromAddition(Vector2D* vector);
};

template <class T>
struct Vector3D
{
	T x;
	T y;
	T z;

	Vector3D(T x, T y, T z) : x(x), y(y), z(z)	{}
};

template<class T>
class Line
{
protected:
	//T a, b;

	Line();
public:
	T getA() const { return a; }
	T getB() const { return b; }
	virtual T getX(T y) = 0;
	virtual T getY(T x) = 0;
	
	static Line<T>* createFromPoints(Point<T>* point1, Point<T>* point2);
	static Line<T>* createFromOffset(Line<T>* line, Vector2D<T>* vector);
	
	virtual void move(Vector2D<T>* vector);
	virtual void rotate(Point<T>* point, double radians);
};


template<class T>
class SkewLine
	: public Line<T>
{
	T a, b;
public:
	T getX(T y) override
	{
		return (y - b) / a;
	}

	T getY(T x) override
	{
		return (a * x) + b;
	}
};


template<class T>
class HorisontalLine
	: private Line<T>
{
	T y;
	T getX(T y) override
	{
		return ;
	}
	T getY(T x) override
	{
		return y;
	}
};

