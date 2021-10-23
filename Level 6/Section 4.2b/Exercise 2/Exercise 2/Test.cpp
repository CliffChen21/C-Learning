// Section 4.2B Exercise 2
// Test.cpp
// [Author] Cliff Chen
// [Description] Test nUMERICArray class with templates.
// [Modifications]
// 2021-10-06  CC established the 1st version.

#include "NumericArray.cpp"
#include "Array.cpp"
#include "ArrayException.hpp"
#include <iostream>
using namespace std;

void main()
{
	NumericArray<int> a(3);
	NumericArray<int> b(a);

	for (int i = 0; i < a.Size(); i++)
	{
		a[i] = i;
		b[i] = -i;
	}
	cout << "a: " << a[0] << " " << a[1] << " " << a[2] << endl;
	cout << "b: " << b[0] << " " << b[1] << " " << b[2] << endl;

	// Test DotProduct 
	cout << a.DotProduct(b) << endl;

	// Test + operator
	NumericArray<int> c = a + b;

	cout <<"c: " << c[0] << " " << c[1] << " " << c[2] << endl;

	// Test * operator
	a = a * 10;

	cout << "a(* 10): " << a[0] << " " << a[1] << " " << a[2] << endl;

}