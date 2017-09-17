/*********************
Joseph Morgan
CISP 400 - MW 3:00PM
Programming Progect 3
February 7, 2017
*********************/

#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#include<iostream>


using namespace std;

class Rational
{
	long long _p;
	long long _q;

	void simplify();

	public:
	Rational();
	Rational (long long p, long long Q = 1);
	Rational (const Rational&);

	Rational& operator= (const Rational&);
	Rational& operator+= (const Rational&);
	Rational& operator-= (const Rational&);
	Rational& operator*= (const Rational&);
	Rational& operator/= (const Rational&);

	friend ostream& operator<< (ostream&, const Rational&);
	friend istream& operator>> (istream&, Rational&);

	Rational operator+ (const Rational&);
	Rational operator+ (long long) const;
	friend Rational operator+ (long long, const Rational&);
	Rational operator- (const Rational&);
	Rational operator- (long long) const;
	friend Rational operator- (long long, const Rational&);
	Rational operator* (const Rational&);
	Rational operator* (long long) const;
	friend Rational operator* (long long, const Rational&);
	Rational operator/ (const Rational&);
	Rational operator/ (long long) const;
	friend Rational operator/ (long long, const Rational&);

	bool operator== (const Rational&) const;
	bool operator== (long long) const;
	friend bool operator== (long long, const Rational&);
	bool operator!= (const Rational&) const;
	bool operator!= (long long) const;
	friend bool operator!= (long long, const Rational&);
	bool operator> (const Rational&) const;
	bool operator> (long long) const;
	friend bool operator> (long long, const Rational&);
	bool operator< (const Rational&) const;
	bool operator< (long long) const;
	friend bool operator< (long long, const Rational&);
	bool operator>= (const Rational&) const;
	bool operator>= (long long) const;
	friend bool operator>= (long long, const Rational&);
	bool operator<= (const Rational&) const;
	bool operator<= (long long) const;
	friend bool operator<= (long long, const Rational&);

	Rational operator++ (int);
	Rational operator-- (int);
	Rational& operator++ ();
	Rational& operator-- ();
	Rational operator- () const;
	Rational operator+ () const;

	Rational pow (unsigned exp) const;
	Rational inverse() const;
};

#endif
