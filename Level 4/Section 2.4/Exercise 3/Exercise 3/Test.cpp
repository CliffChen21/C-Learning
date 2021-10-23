// Section 2.4 Exercise 3
// Test.cpp
// [Author] Cliff Chen
// [Description] Test constructor as implicit conversion operator.
// [Modifications]
// 2021-07-18 CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	// Create a Point object through constructor accepts two values.
	Point p(1.0, 1.0);

	// if (p==1.0) cout << "Equal!" << endl;
	// else cout << "Not equal" << endl;
	// [Output]
	//         - No explicit declaration of single-value constructor
	//           Equal!
	//         - Use explicit declaration of single-value constructor
	//			 Error	

	if (p==(Point)1.0) cout << "Equal!" << endl;
	else cout << "Not equal" << endl;
	//         - No explicit declaration of single-value constructor
	//           Equal!

}

