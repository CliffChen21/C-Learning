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
template <typename T>
Stack<T>::Stack() : m_current(0)
{ // Default constructor.
}

template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(size)
{ // Constructor accepts size
}

template <typename T>
Stack<T>::Stack(const Stack<T>& source) : m_current(source.m_current), m_array(source.m_array)
{ // Copy constructor
}

template <typename T>
Stack<T>::~Stack()
{ // Destructor
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_current = source.m_current;
	m_array = source.m_array;

	return *this;
}

template <typename T>
T& Stack<T>::Pop()
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

template <typename T>
void Stack<T>::Push(const T& newT)
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