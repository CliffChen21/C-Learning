// EuropeanOptionData.hpp
// [Author] Cliff Chen
// [Description] Save the data of option.
// 2021-10-14

#ifndef EuropeanOptionData_HPP
#define EuropeanOptionData_HPP 
#include "OptionData.hpp"
#include <vector>

class EuropeanOptionData : public OptionData
{
public:
	double T; // Expiry time
	double K; // Strike price
	double sig; // Volatility
	double r; // Risk free interest rate
	double S; // Underlying price
	double b; // Cost of carry
public:
	EuropeanOptionData() : OptionData()
	{ // Default constructor
		T = 1;
		K = 100;
		sig = 0.5;
		r = 0.05;
		S = 100;
		b = 0;
	}

	EuropeanOptionData(const EuropeanOptionData&source) : OptionData(source)
	{ // Copy constructor
		Copy(source);
	}

	EuropeanOptionData(char source_ot, double newT, double newK, double newsig, double newr, double newS, double newb) : OptionData(source_ot)
	{ // Constructor accepts arguments
		T = newT;
		K = newK;
		sig = newsig;
		r = newr;
		S = newS;
		b = newb;
	}  

	EuropeanOptionData(char source_ot, vector<double> data_vec) : OptionData(source_ot)
	{ // Constructor accepts arguments
		EuropeanOptionData();
		T = data_vec[0];
		if (data_vec.size() > 1) K = data_vec[1];
		if (data_vec.size() > 2) sig = data_vec[2];
		if (data_vec.size() > 3) r = data_vec[3];
		if (data_vec.size() > 4) S = data_vec[4];
		if (data_vec.size() > 5) b = data_vec[5];
	}

	virtual ~EuropeanOptionData() 
	{ // Destructor 
	};
	
	EuropeanOptionData &operator = (const EuropeanOptionData& source)
	{ // Assignment operator

		OptionData::operator = (source);

		if (this == &source)
		{
			return *this;
		}

		Copy(source);

		return *this;
	}


	void Copy(const EuropeanOptionData& source)
	{
		OptionData::Copy(source);
		T = source.T;
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
			<< "T=" << T << ","
			<< "K=" << K << ","
			<< "sig=" << sig << ","
			<< "r=" << r << ","
			<< "S=" << S;

		return stream.str();
	}
};
#endif