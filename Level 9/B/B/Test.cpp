// Test.cpp
// [Author] Cliff Chen
// 2021-10-14
// [Description] Test the option class and answer the questions

#include "Option.hpp"
#include "PerpetualAmericanOption.hpp"
#include "PerpetualAmericanOptionData.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void main()
{
	vector<double> strike_vec = MeshArray(10, 50, 10);
	vector<double> sig_vec = MeshArray(0.1, 1, 10);
	vector<double> rf_vec = MeshArray(0.01, 0.1, 10);
	vector<double> stock_vec = MeshArray(10, 50, 41);
	cout << "B.b >>>" << endl;
	PerpetualAmericanOptionData od1(Call, 100, 0.1, 0.1, 110, 0.02);
	cout << od1.GetMsg();
	cout << " Call Price: " << PerpetualAmericanOption(od1).Price() << endl;

	PerpetualAmericanOptionData od2(Put, 100, 0.1, 0.1, 110, 0.02);
	cout << od2.GetMsg();
	cout << " Put Price: " << PerpetualAmericanOption(od2).Price() << endl;

	cout << "B.c >>>" << endl;
	
	PerpetualAmericanOption option1(od2);
	for (int i = 0; i < stock_vec.size(); i++)
	{
		cout << option1.Price("S", stock_vec[i]) << " , " ;
	}
	cout << endl;

	cout << "B.d >>>" << endl;

	vector<vector<double>> result = MatrixPricer(option1, { strike_vec, sig_vec, rf_vec, stock_vec });

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " , ";
		}
		cout << endl;
	}
}



