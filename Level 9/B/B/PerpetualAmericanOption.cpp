// PerpetualAmericanOption.cpp
// [Author] Cliff Chen
// [Description] Implementation of the intertmpe for the European option class.
// 2021-10-14

#include "PerpetualAmericanOption.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace boost::math;
using namespace std;

void PerpetualAmericanOption::Init()
{
	Option::Init();
	K = 50;
	sig = 0.2;
	r = 0.05;
	S = 100;
	b = 0;

}

void PerpetualAmericanOption::Copy(const PerpetualAmericanOption& source)
{ // Copy all values

	Option::Copy(source);
	K = source.K;
	sig = source.sig;
	r = source.r;
	S = source.S;
	b = source.b;
}

PerpetualAmericanOption::PerpetualAmericanOption() : Option()
{ // Default constructor
	Init();
}

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) : Option(source)
{ // Copy constructor
	Copy(source);
}

PerpetualAmericanOption::PerpetualAmericanOption(char source_ot) : Option(source_ot)
{ // Constructor with option type
	Init();
}

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOptionData& source) : Option(source)
{ // Constructor with option type
	K = source.K;
	sig = source.sig;
	r = source.r;
	S = source.S;
	b = source.b;
}

PerpetualAmericanOption::~PerpetualAmericanOption()
{ // Destructor
}

PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source)
{ // Assignment operator

	Option::operator = (source);

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}
PerpetualAmericanOption::PerpetualAmericanOption(char source_ot, double newK, double newsig, double newr, double newS, double newb)
{
	Init();
	OptType = source_ot;
	K = newK;
	sig = newsig;
	r = newr;
	S = newS;
	b = newb;
}

double PerpetualAmericanOption::CallPrice() const
{
	return ::CallPrice(K, sig, r, S, b);
}
double PerpetualAmericanOption::PutPrice() const
{
	return ::PutPrice(K, sig, r, S, b);
}

double PerpetualAmericanOption::Price() const
{
	return Option::Price();
}


double PerpetualAmericanOption::Price(double K, double sig, double r, double S, double b) const
{
	if (OptType == Call)
	{
		return ::CallPrice(K, sig, r, S, b);
	}
	else
	{
		return ::PutPrice(K, sig, r, S, b);
	}
}

double PerpetualAmericanOption::Price(string parm, double value) const
{
	if (parm == "K")
	{
		return PerpetualAmericanOption::Price(value, sig, r, S, b);
	}
	if (parm == "sig")
	{
		return PerpetualAmericanOption::Price(K, value, r, S, b);
	}
	if (parm == "r")
	{
		return PerpetualAmericanOption::Price(K, sig, value, S, b);
	}
	if (parm == "S")
	{
		return PerpetualAmericanOption::Price(K, sig, r, value, b);
	}
	if (parm == "b")
	{
		return PerpetualAmericanOption::Price(K, sig, r, S, value);
	}
}

double PerpetualAmericanOption::NumericDelta(double S, double h)
{
	double diff = PerpetualAmericanOption::Price("S", S + h) - PerpetualAmericanOption::Price("S", S-h);
	return diff / 2 * h;
}

double PerpetualAmericanOption::NumericGamma(double S, double h)
{
	double diff = PerpetualAmericanOption::Price("S", S + h) - 2*PerpetualAmericanOption::Price("S", S) + PerpetualAmericanOption::Price("S", S - h);
	return diff / h * h;
}

// Formula for the European Option Price, Delta, Gamma, Vega, Theta
double CallPrice(double K, double sig, double r, double S, double b)
{
	double sig2 = sig * sig;
	double tmp = b / sig2 - 0.5;
	tmp *= tmp;
	double y1 = 0.5 - b / sig2 + sqrt(tmp + 2.0 * r / sig2);



	double tmp2 = ((y1 - 1.0) * S) / (y1 * K);
	double c = K * pow(tmp2, y1) / (y1 - 1.0);

	return c;

}

double PutPrice(double K, double sig, double r, double S, double b)
{

	double sig2 = sig * sig;
	double tmp = b / sig2 - 0.5;
	tmp *= tmp;
	double y2 = 0.5 - b / sig2 - sqrt(tmp + 2.0 * r / sig2);


	double tmp2 = ((y2 - 1.0) * S) / (y2 * K);
	double p = K * pow(tmp2, y2) / (1.0 - y2);

	return p;
}

vector<double> MeshArray(double start, double end, int n)
{
	vector<double> mesh_arr;
	double intvl = (end - start) / (n - 1);
	for (int i = 0; i < n; i++)
	{
		mesh_arr.push_back(start + i * intvl);
	}

	return mesh_arr;
}

vector<vector<double>> MatrixPricer(const PerpetualAmericanOption& option, vector<vector<double>> option_data)
{
	vector<string> parm = {"K", "sig", "r", "S", "b" };
	vector<vector<double>> result;
	for (int i = 0; i < option_data.size(); i++)
	{
		result.push_back(vector<double>());
		for (int j = 0; j < option_data[i].size(); j++)
		{
			result[i].push_back(option.Price(parm[i], option_data[i][j]));
		}
	}

	return result;
}

