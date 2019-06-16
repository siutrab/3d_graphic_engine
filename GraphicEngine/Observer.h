#pragma once
#include "Geometry.h"

template <class T>
class Observer
{
	geo::Point3D<T> eye;
	geo::Vector3D<T> viewDirection;

public:
	Observer();
	~Observer();

	void moveForward(Vector3D<T>* direction)
	{
		eye.move(direction);
	}

	void moveBackward(Vector3D<T>* direction)
	{

	}

	void moveLeft(Vector3D<T>* direction)
	{

	}
	
	void moveRight(Vector3D<T>* direction)
	{

	}
};

