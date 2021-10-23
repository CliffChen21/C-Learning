// Section 4.2b Exercise 4
// Stack.cpp
// [Author] Cliff Chen
// [Description] Source file contains implementation of Stack class in Stack.hpp
// [Modifications]
// 2021-10-10 CC Establish the 1st Version.

#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"
#include "Array.hpp"
#include "StackException.hpp"

// Constructors
template <typename T, int size>
Stack<T, size>::Stack() : m_current(0)
{ // Default constructor.
}

template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& source) : m_current(source.m_current), m_array(source.m_array)
{ // Copy constructor
}

template <typename T, int size>
Stack<T, size>::~Stack()
{ // Destructor
}

template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_current = source.m_current;
	m_array = source.m_array;

	return *this;
}

template <typename T, int size>
T& Stack<T, size>::Pop()
{//  Decrements the current position and then returns the element at that position.
	try
	{
		if (m_current == 0)
		{
			return m_array[-1];
		}
		else
		{
			return m_array[--m_current];
		}
	}
	catch (ArrayException& ex)
	{
		throw StackEmptyException();
	}

}

template <typename T, int size>
void Stack<T, size>::Push(const T& newT)
{
	try
	{
		// Increment the current position afterwards.
		m_array[m_current] = newT;
		m_current++;
	}
	catch (ArrayException& ex)
	{
		throw StackFullException();
	}
}

#endif