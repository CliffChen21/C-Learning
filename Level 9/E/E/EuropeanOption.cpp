// EuropeanOption.cpp
// [Author] Cliff Chen
// [Description] Implementation of the interface for the European option class.
// 2021-10-14

#include "EuropeanOption.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace boost::math;
using namespace std;

void EuropeanOption::Init()
{
	Option::Init();
	T = 1;
	K = 50;
	sig = 0.2;
	r = 0.05;
	S = 100;
	b = 0;

}

void EuropeanOption::Copy(const EuropeanOption& source)
{ // Copy all values

	Option::Copy(source);
	T = source.T;
	K = source.K;
	sig = source.sig;
	r = source.r;
	S = source.S;
	b = source.b;
}

EuropeanOption::EuropeanOption() : Option()
{ // Default constructor
	Init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& source) : Option(source)
{ // Copy constructor
	Copy(source);
}

EuropeanOption::EuropeanOption(char source_ot) : Option(source_ot)
{ // Constructor with option type
	Init();
}

EuropeanOption::EuropeanOption(const EuropeanOptionData& source) : Option(source)
{ // Constructor with option type
	T = source.T;
	K = source.K;
	sig = source.sig;
	r = source.r;
	S = source.S;
	b = source.b;
}

EuropeanOption::~EuropeanOption()
{ // Destructor
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source)
{ // Assignment operator

	Option::operator = (source);

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}
EuropeanOption::EuropeanOption(char source_ot, double newT, double newK, double newsig, double newr, double newS, double newb)
{
	Init();
	OptType = source_ot;
	T = newT;
	K = newK;
	sig = newsig;
	r = newr;
	S = newS;
	b = newb;
}

double EuropeanOption::CallPrice() const
{
	return ::CallPrice(T, K, sig, r, S, b);
}
double EuropeanOption::PutPrice() const
{
	return ::PutPrice(T, K, sig, r, S, b);
}
double EuropeanOption::CallDelta() const
{
	return ::CallDelta(T, K, sig, r, S, b);
}
double EuropeanOption::CallGamma() const
{
	return ::CallGamma(T, K, sig, r, S, b);
}
double EuropeanOption::CallVega() const
{
	return ::CallVega(T, K, sig, r, S, b);
}
double EuropeanOption::CallTheta() const
{
	return ::CallTheta(T, K, sig, r, S, b);
}

double EuropeanOption::PutDelta() const
{
	return ::PutDelta(T, K, sig, r, S, b);
}
double EuropeanOption::PutGamma() const
{
	return ::PutGamma(T, K, sig, r, S, b);
}
double EuropeanOption::PutVega() const
{
	return ::PutVega(T, K, sig, r, S, b);
}
double EuropeanOption::PutTheta() const
{
	return ::PutTheta(T, K, sig, r, S, b);
}

double EuropeanOption::PutCallParity(double price) const
{
	if (OptType == Call)
	{
		return ::PutCallParity(T, K, r, S) + price;
	}
	else
	{
		return price - ::PutCallParity(T, K, r, S);
	}

}

bool EuropeanOption::PutCallParity(double call_price, double put_price) const
{
	double a = (put_price - call_price);
	double b=::PutCallParity(T, K, r, S);
	return abs(a - b) <= 0.00001;
}

double EuropeanOption::Price() const
{
	return Option::Price();
}

double EuropeanOption::Delta() const
{
	return Option::Delta();
}
double EuropeanOption::Gamma() const
{
	return Option::Gamma();
}
double EuropeanOption::Vega() const
{
	return Option::Vega();
}

double EuropeanOption::Theta() const
{
	return Option::Theta();
}

double EuropeanOption::Price(double T, double K, double sig, double r, double S, double b) const
{
	if (OptType == Call)
	{
		return ::CallPrice(T, K, sig, r, S, b);
	}
	else
	{
		return ::PutPrice(T, K, sig, r, S, b);
	}
}

double EuropeanOption::Delta(double T, double K, double sig, double r, double S, double b) const
{
	if (OptType == Call)
	{
		return ::CallDelta(T, K, sig, r, S, b);
	}
	else
	{
		return ::PutDelta(T, K, sig, r, S, b);
	}
}

double EuropeanOption::Gamma(double T, double K, double sig, double r, double S, double b) const
{
	if (OptType == Call)
	{
		return ::CallGamma(T, K, sig, r, S, b);
	}
	else
	{
		return ::PutGamma(T, K, sig, r, S, b);
	}
}

double EuropeanOption::Vega(double T, double K, double sig, double r, double S, double b) const
{
	if (OptType == Call)
	{
		return ::CallVega(T, K, sig, r, S, b);
	}
	else
	{
		return ::PutVega(T, K, sig, r, S, b);
	}
}

double EuropeanOption::Theta(double T, double K, double sig, double r, double S, double b) const
{
	if (OptType == Call)
	{
		return ::CallTheta(T, K, sig, r, S, b);
	}
	else
	{
		return ::PutTheta(T, K, sig, r, S, b);
	}
}

double EuropeanOption::Price(string parm, double value) const
{
	if (parm == "T")
	{
		return EuropeanOption::Price(value, K, sig, r, S, b);
	}
	if (parm == "K")
	{
		return EuropeanOption::Price(T, value, sig, r, S, b);
	}
	if (parm == "sig")
	{
		return EuropeanOption::Price(T, K, value, r, S, b);
	}
	if (parm == "r")
	{
		return EuropeanOption::Price(T, K, sig, value, S, b);
	}
	if (parm == "S")
	{
		return EuropeanOption::Price(T, K, sig, r, value, b);
	}
	if (parm == "b")
	{
		return EuropeanOption::Price(T, K, sig, r, S, value);
	}
}

double EuropeanOption::Delta(string parm, double value) const
{
	if (parm == "T")
	{
		return EuropeanOption::Delta(value, K, sig, r, S, b);
	}
	if (parm == "K")
	{
		return EuropeanOption::Delta(T, value, sig, r, S, b);
	}
	if (parm == "sig")
	{
		return EuropeanOption::Delta(T, K, value, r, S, b);
	}
	if (parm == "r")
	{
		return EuropeanOption::Delta(T, K, sig, value, S, b);
	}
	if (parm == "S")
	{
		return EuropeanOption::Delta(T, K, sig, r, value, b);
	}
	if (parm == "b")
	{
		return EuropeanOption::Delta(T, K, sig, r, S, value);
	}
}

double EuropeanOption::Gamma(string parm, double value) const
{
	if (parm == "T")
	{
		return EuropeanOption::Gamma(value, K, sig, r, S, b);
	}
	if (parm == "K")
	{
		return EuropeanOption::Gamma(T, value, sig, r, S, b);
	}
	if (parm == "sig")
	{
		return EuropeanOption::Gamma(T, K, value, r, S, b);
	}
	if (parm == "r")
	{
		return EuropeanOption::Gamma(T, K, sig, value, S, b);
	}
	if (parm == "S")
	{
		return EuropeanOption::Gamma(T, K, sig, r, value, b);
	}
	if (parm == "b")
	{
		return EuropeanOption::Gamma(T, K, sig, r, S, value);
	}
}
double EuropeanOption::Vega(string parm, double value) const
{
	if (parm == "T")
	{
		return EuropeanOption::Vega(value, K, sig, r, S, b);
	}
	if (parm == "K")
	{
		return EuropeanOption::Vega(T, value, sig, r, S, b);
	}
	if (parm == "sig")
	{
		return EuropeanOption::Vega(T, K, value, r, S, b);
	}
	if (parm == "r")
	{
		return EuropeanOption::Vega(T, K, sig, value, S, b);
	}
	if (parm == "S")
	{
		return EuropeanOption::Vega(T, K, sig, r, value, b);
	}
	if (parm == "b")
	{
		return EuropeanOption::Vega(T, K, sig, r, S, value);
	}
}
double EuropeanOption::Theta(string parm, double value) const
{
	if (parm == "T")
	{
		return EuropeanOption::Theta(value, K, sig, r, S, b);
	}
	if (parm == "K")
	{
		return EuropeanOption::Theta(T, value, sig, r, S, b);
	}
	if (parm == "sig")
	{
		return EuropeanOption::Theta(T, K, value, r, S, b);
	}
	if (parm == "r")
	{
		return EuropeanOption::Theta(T, K, sig, value, S, b);
	}
	if (parm == "S")
	{
		return EuropeanOption::Theta(T, K, sig, r, value, b);
	}
	if (parm == "b")
	{
		return EuropeanOption::Theta(T, K, sig, r, S, value);
	}
}

double EuropeanOption::NumericDelta(double S, double h)
{
	double diff = EuropeanOption::Price("S", S + h) - EuropeanOption::Price("S", S-h);
	return diff / 2 * h;
}

double EuropeanOption::NumericGamma(double S, double h)
{
	double diff = EuropeanOption::Price("S", S + h) - 2*EuropeanOption::Price("S", S) + EuropeanOption::Price("S", S - h);
	return diff / h * h;
}

// Formula for the European Option Price, Delta, Gamma, Vega, Theta
double CallPrice(double T, double K, double sig, double r, double S, double b)
{
	if (sig == 0)
	{
		return max(0.0, exp((b-r) * T)*S - exp(-r * T)*K);
	}
	else
	{
		double tmp = sig * sqrt(T);
		double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
		double d2 = d1 - tmp;
		normal_distribution<> norm(0, 1);

		return (S * exp((b - r) * T) * cdf(norm, d1)) - (K * exp(-r * T) * cdf(norm, d2));
	}
}

double PutPrice(double T, double K, double sig, double r, double S, double b)
{
	if (sig == 0)
	{
		return max(0.0, exp(-r * T)*K - exp((b - r) * T)*S);
	}
	else
	{
		double tmp = sig * sqrt(T);
		double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
		double d2 = d1 - tmp;
		normal_distribution<> norm(0, 1);

		return (K * exp(-r * T) * cdf(norm, -d2)) - (S * exp((b - r) * T) * cdf(norm, -d1));
	}
}

double CallDelta(double T, double K, double sig, double r, double S, double b)
{
	normal_distribution<> norm(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return exp((b - r) * T) * cdf(norm, d1);
}

double PutDelta(double T, double K, double sig, double r, double S, double b)
{
	return CallDelta(T, K, sig, r, S, b) - exp((b - r) * T);
}

double CallGamma(double T, double K, double sig, double r, double S, double b)
{
	normal_distribution<> norm(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return pdf(norm, d1) * exp((b - r) * T) / (S * sig * sqrt(T));
}

double PutGamma(double T, double K, double sig, double r, double S, double b)
{
	return CallGamma(T, K, sig, r, S, b);
}

double CallVega(double T, double K, double sig, double r, double S, double b)
{
	normal_distribution<> norm(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return S * sqrt(T) * exp((b - r) * T) * pdf(norm, d1);
}

double PutVega(double T, double K, double sig, double r, double S, double b)
{
	return CallVega(T, K, sig, r, S, b);
}

double CallTheta(double T, double K, double sig, double r, double S, double b)
{
	normal_distribution<> norm(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	return -S * sig * exp((b - r) * T) * pdf(norm, d1) / (2 * sqrt(T))
		- (b - r) * S * exp((b - r) * T) * cdf(norm, d1) - r * K * exp(-r * T) * cdf(norm, d2);
}

double PutTheta(double T, double K, double sig, double r, double S, double b)
{
	return CallTheta(T, K, sig, r, S, b) + r * K * exp(-r * T) + S * exp((b - r) * T) * (b - r);
}

double PutCallParity(double T, double K, double r, double S)
{
	return K * exp(-r * T) - S;
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

vector<vector<double>> MatrixPricer(const EuropeanOption& option, vector<vector<double>> option_data)
{
	vector<string> parm = { "T", "K", "sig", "r", "S", "b" };
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

vector<vector<double>> MatrixPricer_Delta(const EuropeanOption& option, vector<vector<double>> option_data)
{
	vector<string> parm = { "T", "K", "sig", "r", "S", "b" };
	vector<vector<double>> result;
	for (int i = 0; i < option_data.size(); i++)
	{
		result.push_back(vector<double>());
		for (int j = 0; j < option_data[i].size(); j++)
		{
			result[i].push_back(option.Delta(parm[i], option_data[i][j]));
		}
	}

	return result;
}

vector<vector<double>> MatrixPricer_Gamma(const EuropeanOption& option, vector<vector<double>> option_data)
{
	vector<string> parm = { "T", "K", "sig", "r", "S", "b" };
	vector<vector<double>> result;
	for (int i = 0; i < option_data.size(); i++)
	{
		result.push_back(vector<double>());
		for (int j = 0; j < option_data[i].size(); j++)
		{
			result[i].push_back(option.Gamma(parm[i], option_data[i][j]));
		}
	}

	return result;
}