// Section 5.1 Exercise 2
// Tuple.cpp
// [Author] Cliff Chen
// [Description] Test tuple in Boost.
// [Modifications]
// 2021-10-10  CC established the 1st version.

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>
using namespace std;

void Print(const boost::tuple<string, int, int>& person)
{ // Function that prints the person tuple.
	cout << "Name: " << person.get<0>() << "; Age: "
		<< person.get<1>() << "; Length: " << person.get<2>() << endl;
}

void main()
{
	using boost::tuple;
	typedef boost::tuple<string, int, int> Person; // name, age, length

	Person p1 = boost::make_tuple(string("Cliff"), 24, 16);
	Person p2 = boost::make_tuple(string("Angel"), 26, 2);

	
	p1.get<2>() += 2; // change length of Cliff
	Print(p1);
	Print(p2);
}