// Functor.cpp
// [Author] Cliff Chen
// [Description] Source file contains implementation of Functor class in Functor.hpp
// [Modifications]
// 2021-10-10 CC Establish the 1st Version.

#ifndef Functor_CPP
#define Functor_CPP

#include "Functor.hpp"

// Constructors
template <typename T>
Functor<T>::Functor()
{ // Default constructor
}

template <typename T>
Functor<T>::Functor(const T& t) : limit(t)
{ // Constructor accepts the limit value as input.
}

template <typename T>
Functor<T>::Functor(const Functor<T>& source) : limit(source.limit)
{ // Copy constructor
}

template <typename T>
Functor<T>::~Functor()
{ // Destructor
}

template <typename T>
Functor<T>& Functor<T>::operator = (const Functor<T>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	limit = source.limit;
	return *this;
}

template <typename T>
int Functor<T>::operator () (const T& t) const
{
	return t < limit;
}

#endif