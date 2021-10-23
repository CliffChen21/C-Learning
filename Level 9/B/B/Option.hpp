// Option.hpp
// [Author] Cliff Chen
// [Description] Interface for the general option class.
// 2021-10-14


#ifndef Option_HPP
#define Option_HPP

#include <iostream>
#include <string>
#include "Configuration.hpp"
#include "OptionData.hpp"

using namespace std;



class Option
{

public:
	virtual void Init();	// Initialise all default values
	virtual void Copy(const Option& source);
	virtual double CallPrice() const = 0; // Call option price
	virtual double PutPrice() const = 0; // Put option price
	virtual double CallDelta() const; // Call option Delta
	virtual double PutDelta() const ; // Put option Delta
	virtual double CallGamma() const; // Call option Gamma
	virtual double PutGamma() const; // Put Option Gamma
	virtual double CallVega() const; // Call Option Vega
	virtual double PutVega() const; // Put Option Vega
	virtual double CallTheta() const; // Call Option Theta
	virtual double PutTheta() const; // Put option Theta

public:
	char OptType;	// Option name (call, put)

public:
	Option(); // Default constructor
	Option(const Option& source); // Copy constructor
	Option(char optionType); // Constructor using type
	Option(const OptionData& data); // Constructor using OptionData
	virtual ~Option(); // Destructor

	// Member operator overloading
	Option& operator = (const Option& source);

	// Functions that calculate option price and sensitivities
	double Price() const; // Option price
	double Delta() const; // Option Delta
	double Gamma() const; // Option Gamma
	double Vega() const; // Option Vega
	double Theta() const; // Option Theta

	// Modifier functions
	void toggle(); // Change option type // Change option type (C/P, P/C)
};



#endif
