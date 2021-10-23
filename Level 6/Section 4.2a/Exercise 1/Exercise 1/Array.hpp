// Section 2.5 Exercise 3
// Array.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class point with:
//                 - Fields : 
//                   1) m_data : store Point array.
//                   2) arr_size : size of array.
//                 - Canonical header.
//                 - Member operator overloadings: = and []
//                 - GetElement() and SetElement
// [Modifications]
// 2021-07-18 CC Establish the 1st Version.

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"

#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
class Array
{
private:
	T* m_data; // Dynamic C array of Point objects
	int arr_size; // Size of array

public:
	// Constructors
	Array(); // Default constructor
	Array(const Array<T>& a); // Copy constructor
	Array(int size); // Constructor with size of array
	~Array(); // Destructor

	// Member operator overloading	
	Array<T>& operator = (const Array<T>& source); // Assignment operator.
	T& operator [] (int index);  // read and write elemebt by index.
	const T& operator [] (int index) const;  // read elemebt by index.
	// Reason for extra [] operator:
	// Make [] able to read const Point elements in the Array.

	// Accessing functions
	int Size() const;
	T& GetElement(int index) const;

	// Modifers
	void SetElement(int index, const T& T_val);


};


#ifndef Array_cpp
#include "Array.cpp"
#endif // Array_cpp
// The client wont include source file, since the Array_cpp has been already claimed in the header file.

#endif