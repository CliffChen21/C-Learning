// Sum.hpp
// [Author] Cliff Chen
// [Description] Template headers for Sum.
// [Modifications]
// 2021-10-10  CC established the 1st version.

#include <list>
#include <vector>
#include <map>
#include <iostream>
#include<string>
using namespace std;

// Create a template function called Sum() that accepts the template argument T as input
// and returns a double.The template argument will be a container.
template <typename T>
double Sum(const T& t);

// Sum for map
template <typename K, typename V>
double Sum(const map<K, V>& t);

// Sum between two iterators in a container 
template <typename T>
double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end);

// Sum between two iterators in a container for map
template <typename T1, typename T2>
double Sum(const typename map<T1, T2>::const_iterator& start, const typename map<T1, T2>::const_iterator& end);
