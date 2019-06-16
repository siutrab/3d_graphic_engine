#pragma once
#include <math.h>

	// Forward declarations
	template<class T> class Vector2D;
	template<class T> class Vector3D;

namespace geo
{
	template <class T>
	class Point2D
	{
	public:

		T x, y;


		Point2D(T x, T y) : x(x), y(y)	{}				// Constructor
	
		void move(Vector2D<T>* vector)
		{
			x += vector->x;
			y += vector->y;
		}
	};

	template <class T>
	class Point3D
	{
	public:
		T x, y, z;

		Point3D(T x, T y, T z) : x(x), y(y), z(z) {}		// Constructor

		void move(Vector3D<T>* vector)
		{
			x += vector->x;
			y += vector->y;
			z += vector->z;
		}

	};


	template <class T>
	class Vector2D
	{
	public:

		T x, y;


		Vector2D(T x, T y) : x(x), y(y) {}				// Constructor
		add(Vector2D<T>* vector)
		{
			x += vector->x;
			y += vector->y;
		}

		// Rotates the whole vector of around 0,0 point;
		void rotate(double radians)
		{
			double cosinus = cos(radians);
			double sinus = sin(radians);

			T newX = x;

			x = (x * cosinus) - (y * sinus);
			y = (newX * sinus) + (y * cosinus);
		}		

		void rotate_90deg()
		{
			T newX = x;
			
			x = -y;
			y = newX;
		}

		void rotate_180deg()
		{
			x = -x;
			y = -y;
		}

		void rotate_270deg()
		{
			T newX = x;

			x = y;
			y = -newX;
		}
	};


	template <class T>
	class Vector3D
	{
		Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}		// Constructor

	public:
		T x, y, z;


		void add(Vector3D<T>* vector)
		{
			x += vector->x;
			y += vector->y;
			z += vector->z;
		}

		// Rotation towards Z axis
		void rotate_Z_90deg()
		{
			T newX = x;

			x = -y;
			y = newX;
		}

		void rotate_Z_180deg()
		{
			x = -x;
			y = -y;
		}

		void rotate_Z_270deg()
		{
			T newX = x;

			x = y;
			y = -newX;
		}

		// Rotation towards X axis
		void rotate_X_90deg()
		{
			T newZ = z;
			z = y;
			y = -newZ;
		}

		void rotate_X_180deg()
		{
			z = -z;
			y = -y;
		}

		void rotate_X_270deg()
		{
			T newZ = z;
			z = -y;
			y = newZ;
		}

		// Rotation towards Y axis
		void rotate_Y_90deg()
		{
			T newZ = z;
			z = -x;
			x = -newZ;
		}

		void rotate_Y_180deg()
		{
			z = -z;
			x = -x;
		}

		void rotate_Y_270deg()
		{
			T newZ = z;
			z = x;
			x = -newZ;
		}

	};
}