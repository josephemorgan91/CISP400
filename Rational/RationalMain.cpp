/*********************
Joseph Morgan
CISP 400 - MW 3:00PM
Programming Progect 3
February 7, 2017
*********************/

#include <string>
#include <iostream>
#include "Rational.h"

int main()
{
	while (true)
	{
		Rational rat1;
		Rational rat2;
		Rational rat3;
		long long num;
		unsigned exp;
		Rational power(rat1);
		string hello = "hello";

		// Get input
		try
		{
			cout << "Please enter a numerator and denominator separated by a space: ";
			cin >> rat1;
			cout << endl;
			cout << "Please enter a second numerator and denomintator seperated by a space: ";
			cin >> rat2;
			cout << endl;
			cout << "Please enter a numerator and denominator separated by a space for a third Rational number: ";
			cin >> rat3;
			cout << endl;
			cout << "Enter a number to use for arithmetic operations: ";
			cin >> num;
			cout << endl;
			cout << "Please enter a positive integer to use an exponent :";
			cin >> exp;
			cout << endl;
		}
		catch (char const* err)
		{
			cerr << err << " - Non-Zero denominators only ya big goon.\n";
		}

		cout << endl;

		cout << "You put: " << rat1 << " and: " << rat2 << endl;

		Rational plusequals (rat1);
		Rational minusequals (rat1);
		Rational timesequals (rat1);
		Rational divequals (rat1);

		plusequals += rat2;
		minusequals -= rat2;
		timesequals *= rat2;
		try
		{
			divequals /= rat2;
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
		}

		cout << "+= : " << plusequals << "\n-= : " << minusequals << "\n*= : " << timesequals << "\n/= : " << divequals << endl;

		plusequals = rat1;
		minusequals = rat1;
		timesequals = rat1;
		divequals = rat1;

		plusequals += num;
		minusequals -= num;
		timesequals *= num;
		try
		{
			divequals /= num;
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
		}

		cout << "\nRational = " << rat1<< ", num = " << num << "  :\n";
		cout << rat1 << " += " << num << ": " << plusequals << endl << rat1 << " -= " << num << ": " << minusequals << endl << rat1 <<" *= " << num << ": " << timesequals << endl << rat1 << " /= " << num << ": " << divequals << endl;

		plusequals = rat1;
		minusequals = rat1;
		timesequals = rat1;
		divequals = rat1;

		plusequals += rat3;
		minusequals -= rat3;
		timesequals *= rat3;
		try
		{
			divequals /= rat3;
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
		}

		cout << "\nRational = " << rat1<< ", Rational = " << rat3 << "  :\n";
		cout << rat1 << " += " << rat3 << ": " << plusequals << endl << rat1 << " -= " << rat3 << ": " << minusequals << endl << rat1 << " *= " << rat3 << ": " << timesequals << endl << rat1 << " /= " << rat3 << ": " << divequals << endl;


		power = rat1.pow(exp);
		cout << endl << rat1 << " raised to the power of " << exp << " : ";
		cout << power << endl;

		cout << "The multiplicative inverse of " << rat1 << " is " << rat1.inverse() << endl;

		// Comparison
		cout << endl << endl;
		if (rat1 == rat2)
		{
			cout << rat1 << " = " << rat2 << endl;
		}
		if (rat1 != rat2)
		{
			cout << rat1 << " != " << rat2 << endl;
		}
		if (rat1 <= rat2)
		{
			cout << rat1 << " <= " << rat2 << endl;
		}
		if (rat1 >= rat2)
		{
			cout << rat1 << " >= " << rat2 << endl;
		}
		if (rat1 < rat2)
		{
			cout << rat1 << " < " << rat2 << endl;
		}
		if (rat1 > rat2)
		{
			cout << rat1 << " > " << rat2 << endl;
		}
	}
}
