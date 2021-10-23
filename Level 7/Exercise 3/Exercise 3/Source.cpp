// Source.cpp
// [Author] Cliff Chen
// [Description] Test integer as a template argument.
// [Modifications]
// 2021-10-10  CC established the 1st version.

#include <vector>
#include <algorithm>
#include <iostream>
#include "Functor.cpp"
using namespace std;

// Global function checking the input is less than a certain value.
bool LessThanLimit(double input)
{
	return input < 0.5;
}

void main()
{

	vector<double> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i/10.0);
	}

	// Less than a certain value.
	cout << "The number of elements that are smaller than 0.5 is " << count_if(v.begin(), v.end(), LessThanLimit) << endl;

	// Less than a given value.
	cout << "The number of elements that are smaller than 0.5 is " << count_if(v.begin(), v.end(), Functor<double>(0.5)) << endl;
}