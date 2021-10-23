// Section 3.4 Exercise 2
// Shape.hpp
// [Author] Cliff Chen
// [Description] Base class for shapes:
//                - Point
//                - Line
//                - Circle
// [Modifications]
// 2021-10-03 CC establised the first version.

#ifndef Shape_H
#define Shape_H

#include <iostream>
using namespace std;

class Shape
{
private:
	int m_id; 

public:
	// Constructors and destructor
	Shape(); // Constructor
	Shape(const Shape& source); // Copy constructor
	virtual ~Shape(); // Destructor

	// Operator overloading
	Shape& operator = (const Shape& source); // Assignment operator

	virtual string ToString() const;

	// Accessing functions
	int ID() const;
	virtual void Draw() const = 0; // Draw the graph. (pure virtual member function)
};

#endif

