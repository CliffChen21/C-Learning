// EurpoeanOption.hpp
// [Author] Cliff Chen
// [Description] Interface for the European option class.
// 2021-10-14


#ifndef EuropeanOption_HPP
#define EuropeanOption_HPP

#include "Option.hpp"
#include "EuropeanOptionData.hpp"
#include <string>
#include <vector>
using namespace std;

class EuropeanOption : public Option
{
private:
	virtual void Init();	// Initialise all default values
	virtual void Copy(const EuropeanOption& source);
	virtual double CallPrice() const; // Call option price
	virtual double PutPrice() const; // Put option price
	virtual double CallDelta() const; // Call option Delta
	virtual double PutDelta() const; // Put option Delta
	virtual double CallGamma() const; // Call option Gamma
	virtual double PutGamma() const; // Put Option Gamma
	virtual double CallVega() const; // Call Option Vega
	virtual double PutVega() const; // Put Option Vega
	virtual double CallTheta() const; // Call Option Theta
	virtual double PutTheta() const; // Put option Theta

public:
	double T; // Expiry time
	double K; // Strike price
	double sig; // Volatility
	double r; // Risk free interest rate
	double S; // Underlying price
	double b; // Cost of carry

public:
	EuropeanOption(); // Default constructor
	EuropeanOption(const EuropeanOption& source); // Copy constructor
	EuropeanOption(char source_ot); // Constructor with option type
	EuropeanOption(char source_ot, double T, double K, double sig, double r, double S, double b); // Constructor with option param
	EuropeanOption(const EuropeanOptionData& source); // Constructor with option data
	virtual ~EuropeanOption(); // Destructor

	// Member operator overloading
	EuropeanOption& operator = (const EuropeanOption& source);

	// Additional Functions that calculate option price and sensitivities
	double PutCallParity(double price) const; // Use put-call parity to calculate put price
	bool PutCallParity(double call_price, double put_price) const; // validate the put call parity.
		
	// Functions that calculate option price and sensitivities
	double Price() const;
	double Delta() const; // Option Delta
	double Gamma() const; // Option Gamma
	double Vega() const; // Option Vega
	double Theta() const; // Option Theta

	double Price(double T, double K, double sig, double r, double S, double b) const;
	double Delta(double T, double K, double sig, double r, double S, double b) const; // Option Delta
	double Gamma(double T, double K, double sig, double r, double S, double b) const; // Option Gamma
	double Vega(double T, double K, double sig, double r, double S, double b) const; // Option Vega
	double Theta(double T, double K, double sig, double r, double S, double b) const; // Option Theta
	double NumericDelta(double S, double h); // Using difference and division to compute the delta.
	double NumericGamma(double S, double h); // Using difference and division to compute the gamma.

	double Price(string parm, double value) const; // Option price
	double Delta(string parm, double value) const; // Option Delta
	double Gamma(string parm, double value) const; // Option Gamma
	double Vega(string parm, double value) const; // Option Vega
	double Theta(string parm, double value) const; // Option Theta

};

// Global Functions
double CallPrice(double T, double K, double sig, double r, double S, double b);
double PutPrice(double T, double K, double sig, double r, double S, double b);
double CallDelta(double T, double K, double sig, double r, double S, double b);
double PutDelta(double T, double K, double sig, double r, double S, double b);
double CallGamma(double T, double K, double sig, double r, double S, double b);
double PutGamma(double T, double K, double sig, double r, double S, double b);
double CallVega(double T, double K, double sig, double r, double S, double b);
double PutVega(double T, double K, double sig, double r, double S, double b);
double CallTheta(double T, double K, double sig, double r, double S, double b);
double PutTheta(double T, double K, double sig, double r, double S, double b);
double PutCallParity(double T, double K, double r, double S); //P-C
vector<double> MeshArray(double start, double end, int n); // Generate uniform mesh array
vector<vector<double>> MatrixPricer(const EuropeanOption& option, vector<vector<double>> option_data); // price an option for a matrix of different data.
vector<vector<double>> MatrixPricer_Delta(const EuropeanOption& option, vector<vector<double>> option_data); // delta of an option for a matrix of different data.
vector<vector<double>> MatrixPricer_Gamma(const EuropeanOption& option, vector<vector<double>> option_data); // Gamma of an option for a matrix of different data.
#endif