#pragma once
#include "Geometry.h"
#include "Units.h"

namespace persp
{
	class Camera
	{
		struct Rotation
		{
			double radians;
			double negativeRotationSinus, negativeRotationCosinus;		

			Rotation(unit::Radians angle)
			{
				radians = 0;
				change(angle.value);
			}

			void change(double angleRadians)
			{
				radians += angleRadians;
				negativeRotationSinus = sin(-radians);
				negativeRotationCosinus = cos(-radians);
			}
		};

		struct Screen
		{
			short width, height;
			short halfWidth, halfHeight;
			double depth;					// distance between eye and background plane

			Screen(unit::Pixels widthSize, unit::Pixels heightSize, unit::Radians viewRange)
			{
				reset(widthSize, heightSize, viewRange);
				 
			}

			void reset(unit::Pixels widthSize, unit::Pixels heightSize, unit::Radians viewRange)
			{
				width = widthSize.value;
				height = heightSize.value;

				halfWidth = width / 2;
				halfHeight = width / 2;

				depth = halfWidth / tan(viewRange.value);
			}
		};


		//const double screenDepth;	// distance between eye and background plane

		Rotation verticalRotation;	// top bottom
		Rotation horisontalRotation;	// left right
		Screen screen;		// Screen data

		geo::Point3D<double> eye;
		geo::Vector3D<double> moveDirection;
		

		// Elements needed for tracing point on screen
		geo::Point3D<double>* scenePoint;
		geo::Point2D<int>* screenTracePoint;
		
		geo::Vector3D<double> matchingVector;	// vector made from matching eye with the printing point. Needed for printing point
	
public:
		void setScreenTracePoint(geo::Point3D<double>* point, geo::Point2D<int>* screenPoint)		// sets the localization of 3D point on screen and sets it to screenPoint(0,0 is top left corner of the screen)
		{
			screenTracePoint = screenPoint;
			matchingVector.reset(point, &eye);

			rotateMatchingVector();
			findTracePoint();
		}

		inline void rotateMatchingVector()
		{
			matchingVector.rotateZ(horisontalRotation.negativeRotationSinus, horisontalRotation.negativeRotationCosinus);
			matchingVector.rotateY(verticalRotation.negativeRotationSinus, horisontalRotation.negativeRotationCosinus);
		}

		inline void findTracePoint()
		{
			double tauX = matchingVector.y * screen.depth / matchingVector.x;
			double tauY = matchingVector.z * screen.depth / matchingVector.x;

			screenTracePoint->x = static_cast<int>(screen.halfWidth + tauX);
			screenTracePoint->y = static_cast<int>(screen.halfHeight - tauY);
		}


		Camera(	geo::Point3D<double> eye, 
					unit::Radians rotationHorisontal, unit::Radians rotationVertical,
					unit::Radians viewRange, unit::Pixels screenResolutionX, unit::Pixels screenResolutionY)

			:	screen(screenResolutionX, screenResolutionY, viewRange),
				eye(eye),
				moveDirection(),
				horisontalRotation(rotationHorisontal),
				verticalRotation(rotationVertical),
				matchingVector()
		{

		}



		~Camera() {}


		void moveForward()
		{
			eye.move(&moveDirection);
		}

		void moveBackward()
		{
			moveDirection.rotate_Z_180deg();
			eye.move(&moveDirection);
			moveDirection.rotate_Z_180deg();
		}

		void moveLeft()
		{
			moveDirection.rotate_Z_90deg();
			eye.move(&moveDirection);
			moveDirection.rotate_Z_270deg();
		}

		void moveRight()
		{
			moveDirection.rotate_Z_270deg();
			eye.move(&moveDirection);
			moveDirection.rotate_Z_90deg();
		}

		void rotateUp(unit::Radians angle)
		{
			moveDirection.rotateZ(-horisontalRotation.radians);
			moveDirection.rotateY(angle.value);
			moveDirection.rotateZ(horisontalRotation.radians);

			verticalRotation.change(angle.value);
		}

		void rotateLeft(double radians)
		{
			moveDirection.rotateZ(radians);

			horisontalRotation.change(radians);
		}
	};


	

}


