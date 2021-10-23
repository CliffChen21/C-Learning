// Option.cpp
// [Author] Cliff Chen
// [Description] Implementation of the interface for the general option class.
// 2021-10-14

#include "Option.hpp"
#include "OptionData.hpp"
void Option::Init()
{ // Initialise all default values

	OptType = Call;
}

void Option::Copy(const Option& source)
{ // Copy all values

	OptType = source.OptType;
}

Option::Option()
{// Default constructor
	Init();
}

Option::Option(const Option& source)
{ // Copy constructor
	Copy(source);
}

Option::Option(char source_ot) : OptType(source_ot)
{ // Constructor by option type
}

Option::Option(const OptionData& data) : OptType(data.OptType)
{// Constructor using Option Data
}

Option::~Option()
{// Destructor
}

Option& Option::operator = (const Option& source)
{ // Assignment operator

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}

double Option::Price() const
{
	if (OptType == Call)
	{
		return CallPrice();
	}
	else
	{
		return PutPrice();
	}
}

double Option::CallDelta() const
{
	throw - 1;
}

double Option::PutDelta() const
{
	throw - 1;
}

double Option::CallGamma() const
{
	throw - 1;
}
double Option::PutGamma() const
{
	throw - 1;
}
double Option::CallVega() const
{
	throw - 1;
}
double Option::PutVega() const
{
	throw - 1;
}
double Option::CallTheta() const
{
	throw - 1;
}
double Option::PutTheta() const
{
	throw - 1;
}

double Option::Delta() const
{
	if (OptType == Call)
	{
		return CallDelta();
	}
	else
	{
		return PutDelta();
	}
}

double Option::Gamma() const
{
	if (OptType == Call)
	{
		return CallGamma();
	}
	else
	{
		return PutGamma();
	}
}

double Option::Vega() const
{
	if (OptType == Call)
	{
		return CallVega();
	}
	else
	{
		return PutVega();
	}
}

double Option::Theta() const
{
	if (OptType == Call)
	{
		return CallTheta();
	}
	else
	{
		return PutTheta();
	}
}


// Modifier functions
void Option::toggle()
{// Change option type C/P P/C

	OptType = ((OptType == Call) ? Put : Call);
}