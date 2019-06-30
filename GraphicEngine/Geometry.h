#pragma once
#include <math.h>

	
namespace geo
{
	// Forward declarations
	template<class T> class Vector2D;
	template<class T> class Vector3D;

	template <class T>
	class Point2D
	{
	public:

		T x, y;

		Point2D(){}
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

		Point3D() {}
		Point3D(T x, T y, T z) : x(x), y(y), z(z) {}		// Constructor

		void move(geo::Vector3D<T>* vector)
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
		void add(geo::Vector2D<T>* vector)
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


		inline void rotate(double sinus, double cosinus)
		{
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
	public:
		T x, y, z;

		Vector3D()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		Vector3D(T x, T y, T z) : x(x), y(y), z(z) {}		// Constructor

		Vector3D(geo::Point3D<T>* head, geo::Point3D<T>* tail)		// Constructs vector from two points, where "head" is the arrow in the vector
			:	x(head->x - tail->x),
				y(head->y - tail->y),
				z(head->z - tail->z)	{}


		void reset(geo::Point3D<T>* head, geo::Point3D<T>* tail)
		{
			x = head->x - tail->x;
			y = head->y - tail->y;
			z = head->z - tail->z;
		}

		geo::Vector3D<T>* createFromAddition(geo::Vector3D<T>* vector)
		{
			return new geo::Vector3D<T>((vector->x + x), (vector->y + y), (vector->z + z));
		}

		// Methods
		void add(geo::Vector3D<T>* vector)
		{
			x += vector->x;
			y += vector->y;
			z += vector->z;
		}

		// Rotation towards Z axis
		void rotateZ(double radians)
		{
			double cosinus = cos(radians);
			double sinus = sin(radians);

			T newX = x;

			x = (x * cosinus) - (y * sinus);
			y = (newX * sinus) + (y * cosinus);
		}

		inline void rotateZ(double sinus, double cosinus)
		{
			T newX = x;

			x = (x * cosinus) - (y * sinus);
			y = (newX * sinus) + (y * cosinus);
		}

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

		void rotateX(double radians)
		{
			double cosinus = cos(radians);
			double sinus = sin(radians);

			T newY = y;

			y = (y * cosinus) - (z * sinus);
			z = (newY * sinus) + (z * cosinus);
		}

		inline void rotateX(double sinus, double cosinus)
		{
			T newY = y;

			y = (y * cosinus) - (z * sinus);
			z = (newY * sinus) + (z * cosinus);
		}

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
		void rotateY(double radians)
		{
			double cosinus = cos(radians);
			double sinus = sin(radians);

			T newZ = z;

			z = (z * cosinus) - (x * sinus);
			x = (newZ * sinus) + (x * cosinus);
		}

		inline void rotateY(double sinus, double cosinus)
		{
			T newZ = z;

			z = (z * cosinus) - (x * sinus);
			x = (newZ * sinus) + (x * cosinus);
		}


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

	template <class T>
	class PolygonCorner
	{
		geo::Point3D<T> sceneLocalization;
		geo::Point2D<int> screenPosition;

	public:
		geo::Point2D<int>* getScreenPositionPoint() { return &screenPosition; }
	};

	template <class T>
	class Polygon
	{
		PolygonCorner<T> corner1, corner2, corner3;
	public:

	};

	/*namespace flat
	{*/
		
	
		template<class T>
		class Line
		{
		protected:
			Line();
		public:
			//T getA() const { return a; }
			//T getB() const { return b; }
			virtual T getX(T y) = 0;
			virtual T getY(T x) = 0;

			//static Line<T>* createFromPoints(Point<T>* point1, Point<T>* point2);
			//static Line<T>* createFromOffset(Line<T>* line, Vector2D<T>* vector);

			virtual void move(Vector2D<T>* vector);
			//virtual void rotate(Point<T>* point, double radians);
		};



		template <class T>
		class ZeroPointLine		// y = ax
		{
			T a;

		public:
			ZeroPointLine(geo::Vector3D<T>* vector)
				: a(vector->x / vector->y) {}

			bool reset(geo::Vector3D<T>* vector)		// returns false if the line is horisontal
			{
				if (vector->y == 0) return false;
				else
				{
					a = vector->x / vector->y;
					return true;
				}
			}

			T getY(T x) 
			{
				return a * x;
			}

			T getX(T y)
			{
				return y / a;
			}
		};


		template<class T>
		class SkewLine
			: public Line<T>
		{
			T a, b;
		public:
			void reset(Point2D<T>* point1, Point2D<T>* point2)
			{
				a = (point2->y - point1->y) / (point2->x - point1->x);
				b = point1->y - (a * point1->x);
			}


			T getX(T y) override
			{
				return (y - b) / a;
			}


			T getY(T x) override
			{
				return (a * x) + b;
			}
		};


		/*template<class T>
		class HorisontalLine
			: private Line<T>
		{
			T y;
			T getX(T y) override
			{
				return;
			}
			T getY(T x) override
			{
				return y;
			}
		};*/


	//}
}