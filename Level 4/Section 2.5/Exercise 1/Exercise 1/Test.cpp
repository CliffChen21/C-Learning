// Section 2.5 Exercise 1
// Test.cpp
// [Author] Cliff Chen
// [Description] Test the free store for class Point
// [Modifications]
// 2021-07-18  CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	Point* p1_ptr = new Point(); // new a Pointer by default constructor.
	Point* p2_ptr = new Point(1.0, 0.0); // new a Pointer by constructor accepts two values.
	Point* p3_ptr = new Point(*p2_ptr); // new a Pointer by copy constructor.

	// Test Distance function.
	cout << "The distance between " << (*p1_ptr) << " and " << (*p2_ptr) << " is " << p1_ptr->Distance(*p2_ptr) << endl;
	cout << "The distance between " << (*p3_ptr) << " and (0.0, 0.0) is " << p3_ptr->Distance() << endl;

	// Delete the points
	delete p1_ptr;
	delete p2_ptr;
	delete p3_ptr;

	// Create a Point array.
	int size; // size of array

	// Ask user to input the array size.
	cout << "Please enter the array size in positive integer." << endl;
	cin >> size;
	// Create array using free store.
	// Point p_array[size]; Error.
	Point* p_array = new Point[size]; // Can only use default constructor.

	// Delete Point array.
	delete[] p_array;

}


