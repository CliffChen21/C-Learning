// Section 2.5 Exercise 3
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Array class
// [Modifications]
// 2021-07-18  CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Array.hpp" // Class Array is declared in Array.hpp

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	// Test default constructor and size.
	Array arr1;
	cout << "Default Array size : " << arr1.Size() << endl;

	// Test constructor accepts size.
	Array arr2(3);

	// Test [] operator to write the value.
	arr2[0] = Point(0.0, 0.0);
	arr2[1] = Point(1.0, 0.0);
	arr2[2] = Point(2.0, 0.0);

	// Test [] operator to read.
	cout << "arr2 : ";
	for (int i = 0; i<3; i++) {
		cout << arr2[i];
	}
	cout << endl;

	// Test copy constructor.
	Array arr3(arr2);

	// Test assignment operator.
	arr1 = arr3;

	cout << "arr1 : ";
	// Test GetElement()
	for (int i = 0; i < 3; i++) {
		cout << arr1.GetElement(i);
	}
	cout << endl;

	// Test SetElement
	Array arr4(1);
	const Point p4(3.0, 0.0);
	arr4.SetElement(0, p4);

	// Test const operator [] overloadings.
	cout << arr4[0] << endl;


}


