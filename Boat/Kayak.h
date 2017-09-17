// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#ifndef _KAYAK_H_
#define _KAYAK_H_

#include <iostream>
#include "MusclePowered.h"

class Kayak : public MusclePowered
{
	// TODO: Limit number of seats to one or two?
	bool _whitewater;

	public:
	Kayak();
	Kayak(double disp, double len, double beam, const char* name, unsigned nos, bool is_ww);
	Kayak(const char* name);
	virtual ~Kayak();

	void Set_Whitewater(bool);
	bool Get_Whitewater();

	virtual void Emergency_Procedures();
	virtual void Display() const;
};

#endif
