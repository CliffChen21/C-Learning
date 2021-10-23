// Source.cpp
// [Author] Cliff Chen
// [Description] Test STL.
// [Modifications]
// 2021-10-10  CC established the 1st version.

#include <list>
#include <vector>
#include <map>
#include <iostream>
#include<string>
using namespace std;

void main()
{
	// list
	list<double> list1;
	for (int i = 0; i < 3; i++)
	{
		list1.push_back(i/10.0);
	}
	cout << "<list>" << endl;
	cout << "The first element: " << list1.front() << endl;
	cout << "The last element: " << list1.back() << endl;

	// vector
	vector<double> vector1;
	for (int i = 0; i < 4; i++)
	{
		vector1.push_back(i/10.0);
	}

	cout << "<vector>" << endl;
	for (int i = 0; i < vector1.size(); i++)
	{
		cout << vector1[i] << endl;
	}

	cout << endl;

	// map
	map<string, double> map1;

	for (int i = 0; i < 4; i++)
	{
		map1[to_string(i)] = i/10.0;
	}

	cout << "<map>" << endl;
	for (int i = 0; i < map1.size(); i++)
	{
		cout << map1[to_string(i)] << endl;
	}
}