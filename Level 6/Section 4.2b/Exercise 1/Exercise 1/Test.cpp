// Section 4.2a Exercise 1
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Array class with templates.
// [Modifications]
// 2021-10-06  CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Array.hpp" // Class Array is declared in Array.hpp

#include <iostream> 
#include <string>   

using namespace std; 

void main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	cout << intArray1.DefaultSize() << endl; // 3, default value.
	cout << intArray2.DefaultSize() << endl; // 3, default value.
	cout << doubleArray.DefaultSize() << endl; // 3, default value.
	intArray1.DefaultSize(15);
	cout << intArray1.DefaultSize() << endl; // 15, set new default value.
	cout << intArray2.DefaultSize() << endl; // 15, static is universal in the class which impacts all generated objects.
	cout << doubleArray.DefaultSize() << endl; // 3, Array<double> is independent with Array<int>.

}