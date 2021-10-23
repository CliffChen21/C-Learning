// Section 3.4 Exercise 2
// Line.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class Line with 
//				  - Start-point p1 and end-point p2 privately;
//                - P1()/P2()/Length()/ToString() functions publicly;
//                - Assignment operator;
// [Modifications]
// 2021-10-03 CC established the 1st version.

#ifndef LINE_H // Avoid multiple inclusion.
#define LINE_H

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>

using namespace std;

class Line : public Shape
{
private:
	Point p1; // Start-point.
	Point p2; // End-point.
public:
	// Constructor
	Line(); // Default constructor	
	Line(const Point& p1_val, const Point& p2_val);  // Constructor with a start- and end-point.	
	Line(const Line& line); // Copy constructor	
	virtual ~Line(); // Destructor

	// Member operator overloading	
	Line& operator = (const Line& source); // Assignment operator.

	// Accessing functions	
	const Point P1() const; // Get the value of start-point.
	const Point P2() const; // Get the value of end-point.

	// Modifiers
	void P1(const Point& p1_val); // Set the value of start-point.
	void P2(const Point& p2_val); //Set the value of end-point.


	string ToString() const;
	// [Description] Generate the description of Line object.
	// [Input] None.
	// [Output] String of line description.

	void Draw() const;
	// Override the PVMF to draw graph.
};

ostream& operator << (ostream& os, const Line& p); // Global << operator function for Line description.

#endif