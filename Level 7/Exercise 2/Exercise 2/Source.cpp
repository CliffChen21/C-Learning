// Source.cpp
// [Author] Cliff Chen
// [Description] Test STL Iterators.
// [Modifications]
// 2021-10-10  CC established the 1st version.

#include <list>
#include <vector>
#include <map>
#include <iostream>
#include<string>

#include "Sum.cpp"
using namespace std;


void main()
{
	// Sum of a list
	cout << "<list>" << endl;
	list<double> l;
	for (int i = 0; i < 4; ++i)
	{
		l.push_back(i/10.0);
	}

	cout << Sum(l) << ", " << Sum<list<double>>(++l.begin(), --l.end()) << endl;

	// Sum of a vector
	cout << "<vector>" << endl;
	vector<double> v;
	for (int i = 0; i < 4; ++i)
	{
		v.push_back(i/10.0);
	}

	cout << Sum(v) << ", " << Sum<vector<double>>(++v.begin(), --v.end()) << endl;

	// Sum of a map
	cout << "<map>" << endl;
	map<string, double> m;

	for (int i = 0; i < 4; i++)
	{
		m[to_string(i)] = i/10.0;
	}

	cout << Sum(m) << ", " << Sum<string, double>(++m.begin(), --m.end()) << endl;
}