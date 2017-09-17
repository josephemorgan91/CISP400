/*********************
Joseph Morgan
CISP 400 - MW 3:00PM
Programming Progect 3
February 7, 2017
*********************/

#include "Rational.h"
#include <iostream>

void validate (long long, long long);

int gcd (long long, long long);

Rational::Rational()
{
	_p = 0;
	_q = 1;
}

Rational::Rational (long long p, long long Q)
{
	validate (p, Q);
	_p = p;
	_q = Q;
}

Rational::Rational (const Rational& rat)
{
	this->_p = rat._p;
	this->_q = rat._q;
}
void Rational::simplify()
{
	// Fixes negative denominators.
	if (_q < 0)
	{
		_p *= -1;
		_q *= -1;
	}

	// Simplifies Rational Numbers.
	int denom = gcd(_p, _q);
	_p /= denom;
	_q /= denom;

}

Rational& Rational::operator= (const Rational& rat)
{
	_p = rat._p;
	_q = rat._q;

	return *this;
}

Rational& Rational::operator+= (const Rational& rat)
{
	_p = ((_p * rat._q) + (_q * rat._p));
	_q *= rat._q;

	this->simplify();

	return *this;
}

Rational& Rational::operator-= (const Rational& rat)
{
	_p = ((_p * rat._q) - (_q * rat._p));
	_q *= rat._q;

	this->simplify();

	return *this;
}

Rational& Rational::operator*= (const Rational& rat)
{
	_p *= rat._p;
	_q *= rat._q;

	this->simplify();

	return *this;
}

Rational& Rational::operator/= (const Rational& rat)
{
	if (rat._p == 0)
	{
		throw "Division by zero not allowed";
	}
	_p *= rat._q;
	_q *= rat._p;

	this->simplify();

	return *this;
}

ostream& operator<< (ostream& os, const Rational& rat)
{
	os << rat._p << ":" << rat._q;

	return os;
}

istream& operator>> (istream& is, Rational& rat)
{
	long long p, q;

	is >> p >> q;
	validate(p, q);
	rat._p = p;
	rat._q = q;
	rat.simplify();

	return is;
}

Rational Rational::operator+ (const Rational& rat)
{
	Rational result(*this);

	result += rat;
	result.simplify();

	return result;
}

Rational Rational::operator+ (long long num) const
{
	Rational result(*this);
	Rational temp(num);

	result += temp;
	result.simplify();

	return result;
}

Rational operator+ (long long num, const Rational& rat)
{
	Rational result(num);
	result += rat;
	result.simplify();

	return result;
}

Rational Rational::operator- (const Rational& rat)
{
	Rational result(*this);

	result -= rat;
	result.simplify();

	return result;
}

Rational Rational::operator- (long long num) const
{
	Rational result(*this);
	Rational temp(num);

	result -= temp;
	result.simplify();

	return result;
}

Rational operator- (long long num, const Rational& rat)
{
	Rational result(num);
	result -= rat;
	result.simplify();

	return result;
}

Rational Rational::operator* (const Rational& rat)
{
	Rational result(*this);

	result *= rat;
	result.simplify();

	return result;
}

Rational Rational::operator* (long long num) const
{
	Rational result(*this);
	Rational temp(num);
	result *= temp;
	result.simplify();

	return result;
}

Rational operator* (long long num, const Rational& rat)
{
	Rational result(num);
	result *= rat;
	result.simplify();

	return result;
}

Rational Rational::operator/ (const Rational& rat)
{
	Rational result(*this);

	result /= rat;
	result.simplify();

	return result;
}

Rational Rational::operator/ (long long num) const
{
	Rational result(*this);
	Rational temp(num);

	result /= temp;
	result.simplify();

	return result;
}

Rational operator/ (long long num, const Rational& rat)
{
	Rational result(num);
	result /= rat;
	result.simplify();

	return result;
}

bool Rational::operator== (const Rational& rat) const
{
	bool result;

	if ((this->_p == rat._p) && (this->_q == rat._q))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool Rational::operator== (long long num) const
{
	bool result;
	Rational temp(num);

	result = (*this == temp);

	return result;
}

bool operator== (long long num, const Rational& rat)
{
	bool result;

	result = (rat == num);

	return result;
}

bool Rational::operator!= (const Rational& rat) const
{
	return !(*this == rat);
}

bool Rational::operator!= (long long num) const
{
	return !(*this == num);
}

bool operator!= (long long num, const Rational& rat)
{
	return !(num == rat);
}

bool Rational::operator> (const Rational& rat) const
{
	bool result;

	if ((this->_p / this->_q) > (rat._p / rat._q))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool Rational::operator> (long long num) const
{
	bool result;
	Rational temp(num);

	result = (*this > temp);

	return result;
}

bool operator> (long long num, const Rational& rat)
{
	bool result;

	result = (rat < num);

	return result;
}

bool Rational::operator< (const Rational& rat) const
{
	bool result;

	if (!(*this > rat) && !(*this == rat))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool Rational::operator< (long long num) const
{
	bool result;
	Rational temp(num);

	result = (*this < temp);

	return result;
}

bool operator< (long long num, const Rational& rat)
{
	bool result;

	result = (rat > num);

	return result;
}

bool Rational::operator>= (const Rational& rat) const
{
	bool result;

	if (!(*this < rat))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool Rational::operator>= (long long num) const
{
	bool result;
	Rational temp(num);

	result = (*this >= temp);

	return result;
}

bool operator>= (long long num, const Rational& rat)
{
	bool result;

	result = (rat <= num);

	return result;
}

bool Rational::operator<= (const Rational& rat) const
{
	bool result;

	if (!(*this > rat))
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool Rational::operator<= (long long num) const
{
	bool result;
	Rational temp(num);

	result = (*this <= temp);

	return result;
}

bool operator<= (long long num, const Rational& rat)
{
	bool result;

	result = (rat >= num);

	return result;
}

Rational Rational::operator++ (int) // Postfix
{
	Rational temp(*this);

	this->_p++;
	this->_q++;

	return temp;
}

Rational Rational::operator-- (int) // Postfix
{
	Rational temp(*this);

	this->_p--;
	this->_q--;

	return temp;
}

Rational& Rational::operator++()
{
	this->_p++;
	this->_q++;

	return *this;
}

Rational& Rational::operator--()
{
	this->_p--;
	this->_q--;

	return *this;
}

Rational Rational::operator-() const
{
	Rational temp(-(this->_p), (this->_q));

	return temp;
}

Rational Rational::operator+() const
{
	Rational temp(+(this->_p), +(this->_q));

	return temp;
}

Rational Rational::pow (unsigned exp) const
{
	Rational result(*this);
	Rational temp(*this);

	if (exp == 0)
	{
		result = 1;
	}
	else
	{
		for (unsigned i = 1; i < exp; i++)
		{
			result *= temp;
		}
	}

	return result;
}

Rational Rational::inverse() const
{
	Rational temp(this->_q, this->_p);

	return temp;
}

void validate(long long p, long long q)
{
	p++; // Supress error for unused value. Decided to keep value in parameter list to maintain clarity.
	if (q == 0)
	{
		throw "Zero Denominator";
	}
}

int gcd(long long p, long long q)
{
	// Euclid's Algorithm
	if (q == 0)
	{
		return p;
	}
	return gcd (q, p%q);
}
