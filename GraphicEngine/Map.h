#pragma once
#include "Geometry.h"


namespace persp
{	

	template <class T>
	class Observer
	{

		const T screenDepth;	// distance between eye and background plane

		double horisontalRotation;	// left right
		double verticalRotation;	// top bottom
		
		geo::Point3D<T> eye;
		
		geo::Vector3D<T> viewDirection;
		

	public:
		Observer(T screenDepth)
			: screenDepth(screenDepth)	{}

		~Observer();

		geo::Point2D<int> getScreenTracePoint(geo::Point3D<T>* point)		// returns the localization of 3D point on screen (0,0 is top left corner of the screen)
		{
			geo::Vector3D<T> matchingVector
		}

		void moveForward()
		{
			//eye.move(viewDirection);
		}

		void moveBackward()
		{
			/*geo::Vector3D<T> backStepVector = viewDirection;
			viewDirection.rotate_Z_180deg();*/
		}

		void moveLeft()
		{
			/*geo::Vector3D<T> leftStepVector = viewDirection;
			leftStepVector->rotate_X_90deg();
			eye.move(leftStepVector);*/
		}
	
		void moveRight()
		{

		}
	};




}
