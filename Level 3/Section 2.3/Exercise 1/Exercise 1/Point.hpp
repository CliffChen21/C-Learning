// Section 2.3 Exercise 1
// Point.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class point with members x and y
//               privately, and Get()/Set()/ToString()/Distance()/DistanceOrigin() functions publicly.
//               Also declare default constructor, destructor, copy constructor and constructor accepting x- and y- coordinatesN.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add Distance() and DistanceOrigin() functions to compute the distance between any two points and the origin.
// 2021-06-26 CC Add copy constructor and constructor accepts x-/y-coordinates.


#ifndef POINT_H
#define POINT_H

#include <iostream>  // Library contains count/cin.

using namespace std;


class Point
{
private:
	double x; // x-coordinate.
	double y; // y-coordinate.

public:
	// Default Constructors
	Point();
	// Copy constructor.
	Point(const Point& p);
	// Constructor accepts x-/y-coordinates.
	Point(double x_val, double y_val);

	// Default destructor.
	~Point();


	// ********Member Functions********
	// Accessing functions

	double GetX();
	// [Description] Getter function for x.
	// [Input] None.
	// [Output] (double) x-coordinates.
	double GetY();
	// [Description] Getter function for y.
	// [Input] None.
	// [Output] (double) y-coordinates.

	//  Modifiers

	void SetX(double x_val);
	// [Description] Setter function for x.
	// [Input] (double) x-coordinate value.
	// [Output] None.
	void SetY(double y_val);
	// [Description] Setter function for y.
	// [Input] (double) y-coordinate value.
	// [Output] None.

	// Others

	string ToString();
	// [Description] Return string description of the point.
	// [Input] None.
	// [Output] (string) "Point(x, y)".
	double DistanceOrigin();
	// [Description] Calculate the distance to the origin (0, 0).
	// [Input] None.
	// [Output] Distance between this point and origin.
	double Distance(Point p);
	// [Description] Calculate the distance between two points.
	// [Input] Pint objects.
	// [Output] Distance between this point and user input point.
};


#endif
