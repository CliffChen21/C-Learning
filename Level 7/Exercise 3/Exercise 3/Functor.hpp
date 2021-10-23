// Functor.hpp
// [Author] Cliff Chen
// [Description] Header file declares several function objects would be used in the STL
// [Modifications]
// 2021-10-10 CC Establish the 1st Version.

#ifndef Functor_HPP
#define Functor_HPP

template <typename T>
class Functor
{
private:
	T limit;

public:
	// Constructors
	Functor();
	Functor(const T& t);
	Functor(const Functor<T>& source);

	// Destructor
	~Functor();

	// Member operator overloading
	Functor<T>& operator = (const Functor<T>& source);
	int operator () (const T& t) const;
};

#endif