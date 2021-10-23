// OptionData.hpp
// [Author] Cliff Chen
// [Description] Save the data of option.
// 2021-10-14

#ifndef OptionData_HPP
#define OptionData_HPP


#include "Configuration.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class OptionData
{
public:
	char OptType;

public:
	OptionData() : OptType(Call)
	{// Default Constructor
	}
	OptionData(char option_type) :OptType(option_type)
	{// Constructor Accepts option type
	}
	OptionData(const OptionData& source) :OptType(source.OptType)
	{// Copy constructor
	}

	virtual ~OptionData()
	{// Destructor
	}

	OptionData& operator = (const OptionData& source)
	{ // Assignment operator

		if (this == &source)
		{
			return *this;
		}

		Copy(source);

		return *this;
	}
	void Copy(const OptionData& source)
	{
		OptType = source.OptType;
	}

	string GetMsg() const
	{
		stringstream stream;

		stream << "OptionType: " << OptType;

		return stream.str();
	}
};
#endif