// Section 2.5 Exercise 1
// Point.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class point with:
//					- Members x and y privately;
//					- X()/Y()/Distance() functions publicly.
//                  - Also declare default constructor, destructor, copy constructor and constructor accepting x- and y- coordinates.
//                  - User-defined operator -, *, +, ==, = and *=.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add Distance() and DistanceOrigin() functions to compute the distance between any two points and the origin.
// 2021-06-26 CC Add copy constructor and constructor accepts x-/y-coordinates.
//            CC Change call-by-value in Distance to call-by-constant-reference.
//            CC Overload SetX()/GetX() tO X(), SetY()/GetY() tO Y(), DistanceOrigin() to Distance()
//            and three constructor to the same name Point.
//            CC Change the getter functions, ToString() and Distance() to constant member functions.
// 2021-07-11 CC Add operator functions based on the mathematically logic.
// 2021-07-18 CC Add << operator for description output.
//            CC Change << operator as a friend function.

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
	// Constructors
	Point(); // Default constructor
	Point(const Point& p); // Copy constructor
	Point(double x_val, double y_val); // Constructor with x, y values
	~Point(); // Destructor

	// Accessing functions
	double X() const; // Getter function for x.
	double Y() const; // Getter function for y.

	//  Modifiers
	void X(double x_val); // Setter function for x.
	void Y(double y_val); // Setter function for y.

	// Member operator overloading	
	Point operator - () const; // Negate the coordinates.
	Point operator * (double factor) const; // Scale the coordinates.
	Point operator + (const Point& p) const; // Add coordinates.
	bool operator == (const Point& p) const; // Equally compare operator.
	Point& operator = (const Point& source); // Assignment operator.
	Point& operator *= (double factor); // Scale the coordinates & assign.
	
	// Functionality
	string ToString() const;
	// [Description] Return string description of the point.
	// [Input] None.
	// [Output] (string) "Point(x, y)".
	double Distance() const;
	// [Description] Calculate the distance to the origin (0, 0).
	// [Input] None.
	// [Output] Distance between this point and origin.
	double Distance(const Point& p) const;
	// [Description] Calculate the distance between two points.
	// [Input] Pint objects.
	// [Output] Distance between this point and user input point.

	// Global friend operator overloading
	friend ostream& operator << (ostream& os, const Point& p); // Global << operator function for Point description.
};

#endif // POINT_H
