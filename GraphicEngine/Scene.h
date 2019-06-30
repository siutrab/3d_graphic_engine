#pragma once
#include "Geometry.h"
#include "Camera.h"
#include "Units.h"
#include "SFML/Graphics.hpp"



class Map
{
public:
	void print()
	{
		unit::Pixels screenWidth = unit::Pixels(1000);
		unit::Pixels screenHeight = unit::Pixels(800);


		geo::Point3D<double> eye = geo::Point3D<double>(0, 0, 0);
		unit::Radians verticalRotation = unit::Radians(0.1);
		unit::Radians horisontalRotation = unit::Radians(0.2);
		
		unit::Radians viewRange = unit::Radians(unit::Degrees(70));

		

		persp::Camera observr = persp::Camera(eye, horisontalRotation, verticalRotation, viewRange, screenWidth, screenHeight); //(1000, geo::Point3D<double>(0,0,0), 0.1, 0.1, screenWidth, screenHeight);
		geo::Point3D<double> pointArray[8];


		pointArray[0] = geo::Point3D<double>(300, -150, -150);
		pointArray[1] = geo::Point3D<double>(300, -150, 150);
		pointArray[2] = geo::Point3D<double>(300, 150, -150);
		pointArray[3] = geo::Point3D<double>(300, 150, 150);
		pointArray[4] = geo::Point3D<double>(600, -150, -150);
		pointArray[5] = geo::Point3D<double>(600, -150, 150);
		pointArray[6] = geo::Point3D<double>(600, 150, -150);
		pointArray[7] = geo::Point3D<double>(600, 150, 150);

		geo::Point2D<int> screenArray[8];

		
		sf::RenderWindow window(sf::VideoMode(screenWidth.value, screenHeight.value), "---");
		
		for (int i = 0; i < 8; i++)
		{
			observr.setScreenTracePoint(&pointArray[i], &screenArray[i]);
		}

		sf::Vertex front[] =
		{
			sf::Vertex(sf::Vector2f(screenArray[0].x, screenArray[0].y)),
			sf::Vertex(sf::Vector2f(screenArray[1].x, screenArray[1].y)),
			sf::Vertex(sf::Vector2f(screenArray[2].x, screenArray[2].y)),
			sf::Vertex(sf::Vector2f(screenArray[3].x, screenArray[3].y))
			
		};


		sf::Vertex back[] =
		{
			sf::Vertex(sf::Vector2f(screenArray[4].x, screenArray[4].y)),
			sf::Vertex(sf::Vector2f(screenArray[5].x, screenArray[5].y)),
			sf::Vertex(sf::Vector2f(screenArray[6].x, screenArray[6].y)),
			sf::Vertex(sf::Vector2f(screenArray[7].x, screenArray[7].y))

		};

		window.clear();
		window.draw(front, 5, sf::Lines);
		window.draw(back, 5, sf::Lines);
		window.display();
		while (true)
		{

		}
	}

};

