// Test.cpp
// [Author] Cliff Chen
// 2021-10-14
// [Description] Test the option class and answer the questions

#include "Option.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanOptionData.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void main()
{
	// Store Batch 1 to Batch 4 data in a vector.
	typedef boost::tuple<double, double, double, double, double> option_var;
	vector<option_var> batch;
	batch.push_back(boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0));
	batch.push_back(boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0));
	batch.push_back(boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0));
	batch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0));

	cout << "A1.a >>>" << endl;
	for (int i = 0; i < batch.size(); i++)
	{
		// A.a) b=r (b=r-q)
		double tenor = batch[i].get<0>();
		double strike = batch[i].get<1>();
		double sig = batch[i].get<2>();
		double rf = batch[i].get<3>();
		double stock = batch[i].get<4>();

		EuropeanOption call_option(Call, tenor, strike, sig, rf, stock, rf);
		EuropeanOption put_option(Put, tenor, strike, sig, rf, stock, rf);

		double call_price = call_option.Price();
		double put_price = put_option.Price();
		cout << "Batch " << i + 1 << ":"
			<< "T=" << tenor << ","
			<< "K=" << strike << ","
			<< "sig=" << sig << ","
			<< "r=" << rf << ","
			<< "S=" << stock << " (C="
			<< call_price << ", P=" << put_price << ")." << endl;
		if (call_option.PutCallParity(call_price, put_price))
		{
			cout << "Pass Put-Call Parity Test.\n";
		}
		else
		{
			cout << "Not Pass Put-Call Parity Test.\n";
		}
	}

	cout << "A1.b >>>" << endl;
	for (int i = 0; i < batch.size(); i++)
	{
		// A.b) b=r (b=r-q) Validate put-call parity
		double tenor = batch[i].get<0>();
		double strike = batch[i].get<1>();
		double sig = batch[i].get<2>();
		double rf = batch[i].get<3>();
		double stock = batch[i].get<4>();

		EuropeanOption call_option(Call, tenor, strike, sig, rf, stock, rf);

		double call_price = call_option.Price();
		double put_price = call_option.PutCallParity(call_price);
		cout << "Batch " << i + 1 << ":"
			<< "T=" << tenor << ","
			<< "K=" << strike << ","
			<< "sig=" << sig << ","
			<< "r=" << rf << ","
			<< "S=" << stock << " (C="
			<< call_price << ", P=" << put_price << ")." << endl;

	}

	cout << "A1.c >>>" << endl;
	vector<double> stock_vec = MeshArray(10, 50, 41);
	for (int i = 0; i < batch.size(); i++)
	{
		// A.c) b=r (b=r-q) Validate put-call parity
		double tenor = batch[i].get<0>();
		double strike = batch[i].get<1>();
		double sig = batch[i].get<2>();
		double rf = batch[i].get<3>();
		double stock = batch[i].get<4>();
		cout << "Batch " << i + 1 << ":" << endl;
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


	}

	cout << "A1.d >>>" << endl; // Test the matrix pricer
	vector<double> tenor_vec = MeshArray(1, 10, 10);
	vector<double> strike_vec = MeshArray(10, 50, 10);
	vector<double> sig_vec = MeshArray(0.1, 1, 10);
	vector<double> rf_vec = MeshArray(0.01, 0.1, 10);

	EuropeanOption test_option;

	vector<vector<double>> price_matrix = MatrixPricer(test_option, { tenor_vec, strike_vec, sig_vec, rf_vec });
	for (int i = 0; i < price_matrix.size(); i++)
	{
		for (int j = 0; j < price_matrix[i].size(); j++)
		{
			cout << price_matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << "A2.a >>>" << endl; // Test delta and Gamma function for future option.
	EuropeanOptionData od1(Call, 0.5, 100, 0.36, 0.1, 105, 0);

	cout << od1.GetMsg()
		<< " Delta: " << EuropeanOption(od1).Delta() << " , "
		<< " Gamma: " << EuropeanOption(od1).Gamma() << endl;

	EuropeanOptionData od2(Put, 0.5, 100, 0.36, 0.1, 105, 0);

	cout << od2.GetMsg()
		<< " Delta: " << EuropeanOption(od2).Delta() << " , "
		<< " Gamma: " << EuropeanOption(od2).Delta() << endl;

	cout << "A2.b >>>" << endl; // Test a bunch of delta

	vector<double> delta1;
	vector<double> gamma1;
	cout << od1.GetMsg() << endl;

	for (int i = 0; i < stock_vec.size(); i++)
	{
		delta1.push_back(EuropeanOption(od1).Delta("S", stock_vec[i]));
	}

	cout << "Delta : ";
	for (int i = 0; i < stock_vec.size(); i++)
	{
		cout << delta1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < stock_vec.size(); i++)
	{
		gamma1.push_back(EuropeanOption(od1).Gamma("S", stock_vec[i]));
	}

	cout << "Delta : ";
	for (int i = 0; i < stock_vec.size(); i++)
	{
		cout << gamma1[i] << " ";
	}
	cout << endl;

	cout << "A2.c >>>" << endl; // Test a bunch of delta and gamma
	EuropeanOption test_option2;

	cout << "\n Delta : \n";
	vector<vector<double>> delta_matrix = MatrixPricer_Delta(test_option2, { tenor_vec, strike_vec, sig_vec, rf_vec });
	for (int i = 0; i < delta_matrix.size(); i++)
	{
		for (int j = 0; j < delta_matrix[i].size(); j++)
		{
			cout << delta_matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n Gamma : \n";
	vector<vector<double>> gamma_matrix = MatrixPricer_Gamma(test_option2, { tenor_vec, strike_vec, sig_vec, rf_vec });
	for (int i = 0; i < gamma_matrix.size(); i++)
	{
		for (int j = 0; j < gamma_matrix[i].size(); j++)
		{
			cout << gamma_matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << "A2.d >>>" << endl; // Test a bunch of delta
	vector<double> delta2;
	vector<double> gamma2;
	EuropeanOption option_2c(od1);
	cout << od1.GetMsg() << endl;
	for (int i = 0; i < stock_vec.size(); i++)
	{
		delta2.push_back(option_2c.NumericDelta(stock_vec[i], 1));
	}

	cout << "Delta : ";
	for (int i = 0; i < stock_vec.size(); i++)
	{
		cout << delta2[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < stock_vec.size(); i++)
	{
		gamma2.push_back(option_2c.NumericGamma(stock_vec[i], 1));
	}

	cout << "Gamma : ";
	for (int i = 0; i < stock_vec.size(); i++)
	{
		cout << gamma2[i] << " ";
	}
	cout << endl;
}



