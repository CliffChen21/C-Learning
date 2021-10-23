// PerpetualAmericanOptionData.hpp
// [Author] Cliff Chen
// [Description] Save the data of option.
// 2021-10-14

#ifndef PerpetualAmericanOptionData_HPP
#define PerpetualAmericanOptionData_HPP 
#include "OptionData.hpp"
#include <vector>

class PerpetualAmericanOptionData : public OptionData
{
public:
	double K; // Strike price
	double sig; // Volatility
	double r; // Risk free interest rate
	double S; // Underlying price
	double b; // Cost of carry
public:
	PerpetualAmericanOptionData() : OptionData()
	{ // Default constructor
		K = 100;
		sig = 0.5;
		r = 0.05;
		S = 100;
		b = 0;
	}

	PerpetualAmericanOptionData(const PerpetualAmericanOptionData&source) : OptionData(source)
	{ // Copy constructor
		Copy(source);
	}

	PerpetualAmericanOptionData(char source_ot, double newK, double newsig, double newr, double newS, double newb) : OptionData(source_ot)
	{ // Constructor accepts arguments
		K = newK;
		sig = newsig;
		r = newr;
		S = newS;
		b = newb;
	}  

	PerpetualAmericanOptionData(char source_ot, vector<double> data_vec) : OptionData(source_ot)
	{ // Constructor accepts arguments
		PerpetualAmericanOptionData();
		if (data_vec.size() > 1) K = data_vec[1];
		if (data_vec.size() > 2) sig = data_vec[2];
		if (data_vec.size() > 3) r = data_vec[3];
		if (data_vec.size() > 4) S = data_vec[4];
		if (data_vec.size() > 5) b = data_vec[5];
	}

	virtual ~PerpetualAmericanOptionData() 
	{ // Destructor 
	};
	
	PerpetualAmericanOptionData &operator = (const PerpetualAmericanOptionData& source)
	{ // Assignment operator

		OptionData::operator = (source);

		if (this == &source)
		{
			return *this;
		}

		Copy(source);

		return *this;
	}


	void Copy(const PerpetualAmericanOptionData& source)
	{
		OptionData::Copy(source);
		K = source.K;
		sig = source.sig;
		r = source.r;
		S = source.S;
		b = source.b;
	}

	string GetMsg() const
	{
		stringstream stream;

		stream << OptionData::GetMsg() << ","
			<< "K=" << K << ","
			<< "sig=" << sig << ","
			<< "r=" << r << ","
			<< "S=" << S;

		return stream.str();
	}
};
#endif