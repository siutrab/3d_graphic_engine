#pragma once
#include <math.h>


namespace unit
{
	struct Radians;		// forward declaration
	
	
	template <class T>
	struct Unit
	{
		T value;

		Unit(T value)
			: value(value) 
		{}
	};

	


	struct Degrees
		: public Unit<double>
	{
		Degrees(double value);
		Degrees(unit::Radians angle);

	private:
		static const double RadiansToDegreesFactor;
	};
		
	



	struct Radians
		: public unit::Unit<double>
	{
		Radians(double value);
		Radians(unit::Degrees angle);

	private:
		static const double degreeseToRadiansFactor;
	};

	



	struct Pixels
		: public Unit<unsigned short>
	{
		Pixels(unsigned short value)
			: Unit(value)
		{}
	};



	struct Meters
		: public Unit<double>
	{
		Meters(double value)
			: Unit(value)
		{}
	};
}




// Degrees
unit::Degrees::Degrees(double value)
	: unit::Unit<double>::Unit(value)
{}

unit::Degrees::Degrees(unit::Radians angle)
: unit::Unit<double>::Unit(static_cast<double>(angle.value * unit::Degrees::RadiansToDegreesFactor))
{}

const double unit::Degrees::RadiansToDegreesFactor = static_cast<double>(57.2957795130876);


// Radians
unit::Radians::Radians(double value)
	:	unit::Unit<double>::Unit(value)
{}

unit::Radians::Radians(unit::Degrees angle)
: unit::Unit<double>::Unit(static_cast<double>(angle.value * degreeseToRadiansFactor))
{}

const double unit::Radians::degreeseToRadiansFactor = static_cast<double>(0.01745329251994);