// Section 4.2b Exercise 2
// Array.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class Stack with:
//                 - Fields : 
//                   1) m_current : current index in the array.
//                   2) m_array : composite an Array class.
//                 - Canonical header.
//                 - Member operator overloadings: =
//                 - Push() and Pop()
// [Modifications]
// 2021-10-10 CC Establish the 1st Version.

#ifndef Stack_HPP
#define Stack_HPP

#include "Array.cpp"

template <typename T>
class Stack
{
private:
	int m_current;
	Array<T> m_array;

public:
	Stack(); // Default constructor
	Stack(int size); // Constructor accepts size
	Stack(const Stack<T>& source); // Copy constructor

	~Stack(); // Destructor

	// Member operator overloading
	Stack<T>& operator = (const Stack<T>& source);

	// Functionalities
	T& Pop(); //  decrements the current position and then returns the element at that position.
	void Push(const T& newT); // Increment the current position afterwards. 
};

#endif