#include "Short.h"

Short::Short() : _n(0), _dt(DEC) {}

Short::Short (signed char c, display_type dt) : _n(c), _dt(dt) {}

void Short::_display_BIN(ostream& out) const
{
	for (int i = 0; i < 8; i++)
	{
		if (i == 4)
		{
			out << " ";
		}
		out << !!((_n << i) & 0x80);
	}
	out << "b";
}

void Short::_display_HEX(ostream& out) const
{
	out << hex << uppercase 
	<< (((_n < 16) && (_n >= 0)) ? "0" : "") << ((_n == 0) ? "0" : "")
	<< (+_n & 0xFF) << 'h'
	<< dec << nouppercase;
}

void Short::add (const Short& s)
{
	_n += s._n;
}

void Short::sub (const Short& s)
{
	_n -= s._n;
}

void Short::mult (const Short& s)
{
	_n *= s._n;
}

void Short::div (const Short& s)
{
	_n /= s._n;
}

void Short::display() const
{
	switch (_dt)
	{
		case DEC:
			cout << dec <<(int)(_n);
			break;
		case HEX:
			_display_HEX(cout);
			break;
		case BIN:
			_display_BIN(cout);
			break;
		default:
			cout << "Oops! Looks like there's something wrong here." << endl;
			break;
	}
}

void Short::set_display_type (display_type dt)
{
	_dt = dt;
}

void Short::set_value (signed char c)
{
	_n = c;
}
