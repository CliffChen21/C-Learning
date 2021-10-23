// Section 2.5 Exercise 2
// Test.cpp
// [Author] Cliff Chen
// [Description] Test create a Point array once and create each elements separately.
// [Modifications]
// 2021-07-18  CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	// Create an array of Point pointers with 3 elements on the heap.
	Point** p_array_ptr = new Point*[3]; // array of Point pointer.

	// Create for each element in the array a point on the heap.
	p_array_ptr[0] = new Point(0.0, 0.0);
	p_array_ptr[1] = new Point(1.0, 0.0);
	p_array_ptr[2] = new Point(*p_array_ptr[0]);

	// Iterate the array and print each point in the array.
	for (int i = 0; i < 3; i++)
	{
		cout << (*p_array_ptr[i]) << endl;
	}

	// Iterate the array again and delete each point in the array
	for (int i = 0; i < 3; i++)
	{
		delete p_array_ptr[i];
	}

	// Delete the array itself.
	delete[] p_array_ptr;
}


