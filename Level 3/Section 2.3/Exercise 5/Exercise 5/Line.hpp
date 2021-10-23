// Section 2.3 Exercise 5
// Point.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class Line with start-point p1 and end-point p2
//               privately, and P1()/P2()/Length()/ToString() functions publicly.
// [Modifications]
// 2021-06-26 CC established the 1st version.

#ifndef LINE_H // Avoid multiple inclusion.
#define LINE_H

#include "Point.hpp"
#include <iostream>

using namespace std;


class Line
{
private:
	Point p1; // Start-point.
	Point p2; // End-point.
public:
	// Default constructor
	Line(); 
	// Constructor with a start- and end-point.
	Line(const Point& p1_val, const Point& p2_val); 
	// Copy constructor
	Line(const Line& line);

	// Destructor
	~Line(); 

	
	// Accessing functions
	
	Point P1() const; 
	// [Description] Get the value of start-point.
	// [Input] None.
	// [Output] Point objects.
	Point P2() const; 
	// [Description] Get the value of end-point.
	// [Input] None.
	// [Output] Point objects.

	
	// Modifiers
	void P1(const Point& p1_val); 
	// [Description] Set the value of start-point.
	// [Input] Point object.
	// [Output] None	
	void P2(const Point& p2_val);
	// [Description] Set the value of end-point.
	// [Input] Point object.
	// [Output] None

	// Ohters
	double Length() const; 
	// [Description] Compute the length of line.
	// [Input] None.
	// [Output] Floating-point number.
	string ToString() const; 
	// [Description] Generate the description of Line object.
	// [Input] None.
	// [Output] String of line description.
};
#endif