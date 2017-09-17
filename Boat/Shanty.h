// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#ifndef _SHANTY_H_
#define _SHANTY_H_

#include <iostream>
#include "MusclePowered.h"

class Shanty : public MusclePowered
{
	unsigned _number_of_berths;

	public:
	Shanty();
	Shanty(double disp, double len, double beam, const char* name, unsigned nos, unsigned nob);
	Shanty(const char* name);
	virtual ~Shanty();

	void Set_Number_Of_Berths(unsigned);
	unsigned Get_Number_Of_Berths();

	virtual void Emergency_Procedures();
	virtual void Display() const;
};

#endif
