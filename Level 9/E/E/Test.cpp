// Test.cpp
// [Author] Cliff Chen
// 2021-10-14
// [Description] Test the option class and answer the questions

#include "Option.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanOptionData.hpp"
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void create_excel(const vector<double>& x,		// X array
	const list<string>& labels,					// Names of each vector
	const list<vector<double>> & result,	// The list of Y values
	const string& title,
	const string& horizontal,
	const string& vertical)
{

	ExcelDriver& excel = ExcelDriver::Instance();

	excel.MakeVisible(true);		


	excel.CreateChart(x, labels, result, title, horizontal, vertical);

}


void main()
{
	// Store Batch 1 to Batch 4 data in a vector.
	typedef boost::tuple<double, double, double, double, double> option_var;
	vector<option_var> batch;
	list<vector<double>> result;
	list<string> labels;
	batch.push_back(boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0));
	batch.push_back(boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0));
	batch.push_back(boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0));
	batch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0));

	vector<double> stock_vec = MeshArray(10, 50, 41);
	for (int i = 0; i < batch.size(); i++)
	{
		// A.c) b=r (b=r-q) Validate put-call parity
		double tenor = batch[i].get<0>();
		double strike = batch[i].get<1>();
		double sig = batch[i].get<2>();
		double rf = batch[i].get<3>();
		double stock = batch[i].get<4>();
		stringstream ss;
		string str;
		ss << i;
		ss >> str;
		labels.push_back("Batch " + str + " Call");
		labels.push_back("Batch " + str + " Put");
		vector<double> call_price_vec, put_price_vec;
		for (int j = 0; j < stock_vec.size(); j++)
		{
			EuropeanOption call_option(Call, tenor, strike, sig, rf, stock_vec[j], rf);

			double call_price = call_option.Price();
			double put_price = call_option.PutCallParity(call_price);
			cout << "     "
				<< "T=" << tenor << ","
				<< "K=" << strike << ","
				<< "sig=" << sig << ","
				<< "r=" << rf << ","
				<< "S=" << stock_vec[j] << " (C="
				<< call_price << ", P=" << put_price << ")." << endl;
			call_price_vec.push_back(call_price);
			put_price_vec.push_back(put_price);
		}
		
		result.push_back(call_price_vec);
		result.push_back(put_price_vec);
	}
	
	create_excel(stock_vec, labels, result,
		string("Graph for all bathes"), string("Underlying value"), string("Option price"));
}



