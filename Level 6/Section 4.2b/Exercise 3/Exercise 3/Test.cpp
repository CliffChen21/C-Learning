// Section 4.2b Exercise 3
// Test.cpp
// [Author] Cliff Chen
// [Description] Test PointArray.
// [Modifications]
// 2021-10-06  CC established the 1st version.

#include "PointArray.hpp"
#include <iostream>
using namespace std;

void main()
{
	PointArray arr1;

	// Test assignment operator
	PointArray arr2 = arr1;
	cout << "arr2: " << endl;
	for (int i = 0; i < arr2.Size(); i++)
	{
		cout << arr2[i] << endl;
	}

	// Test Length()
	cout << "Len(arr2) = " << arr2.Length() << endl;
}