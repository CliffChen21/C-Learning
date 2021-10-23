// EurpoeanOption.hpp
// [Author] Cliff Chen
// [Description] Interface for the European option class.
// 2021-10-14


#ifndef PerpetualAmericanOption_HPP
#define PerpetualAmericanOption_HPP

#include "Option.hpp"
#include "PerpetualAmericanOptionData.hpp"
#include <string>
#include <vector>
using namespace std;

class PerpetualAmericanOption : public Option
{
private:
	virtual void Init();	// Initialise all default values
	virtual void Copy(const PerpetualAmericanOption& source);
	virtual double CallPrice() const; // Call option price
	virtual double PutPrice() const; // Put option price


public:
	double K; // Strike price
	double sig; // Volatility
	double r; // Risk free interest rate
	double S; // Underlying price
	double b; // Cost of carry

public:
	PerpetualAmericanOption(); // Default constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& source); // Copy constructor
	PerpetualAmericanOption(char source_ot); // Constructor with option type
	PerpetualAmericanOption(char source_ot, double K, double sig, double r, double S, double b); // Constructor with option param
	PerpetualAmericanOption(const PerpetualAmericanOptionData& source); // Constructor with option data
	virtual ~PerpetualAmericanOption(); // Destructor

	// Member operator overloading
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);

	// Functions that calculate option price and sensitivities
	double Price() const;
	double Price(double K, double sig, double r, double S, double b) const;
	double Price(string parm, double value) const; // Option price

	double NumericDelta(double S, double h); // Using difference and division to compute the delta.
	double NumericGamma(double S, double h); // Using difference and division to compute the gamma.



};

// Global Functions
double CallPrice(double K, double sig, double r, double S, double b);
double PutPrice(double K, double sig, double r, double S, double b);
vector<double> MeshArray(double start, double end, int n); // Generate uniform mesh array
vector<vector<double>> MatrixPricer(const PerpetualAmericanOption& option, vector<vector<double>> option_data); // price an option for a matrix of different data.
#endif