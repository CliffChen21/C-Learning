// Section 4.2b Exercise 3
// Array.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class PointArray inherits from Array:
//                 - Fields : 
//                   1) m_data : store Point array.
//                   2) arr_size : size of array.
//                 - Canonical header.
//                 - Member operator overloadings: = and []
//                 - GetElement() and SetElement
//				   - Length() 
// [Modifications]
// 2021-10-06 CC Establish the 1st Version.

#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.cpp"
#include "Point.hpp"

class PointArray : public Array<Point>
{
public:
	PointArray(); // Default constructor.
	PointArray(int size); // Constructor accepts arguments.
	PointArray(const PointArray& source); // Copy constructor.

	virtual ~PointArray(); // Destructor.

	// Member operator overloading
	PointArray& operator = (const PointArray& source);  // Assignment operator

	// Accessing function
	double Length() const; // Get the total length between the points in the array.

};


#endif