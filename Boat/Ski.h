// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#ifndef _SKI_H_
#define _SKI_H_

#include "MotorPowered.h"

class Ski : public MotorPowered
{
	bool _barefoot_pole;

	public:
	Ski();
	Ski(double disp, double len, double beam, const char* name, const char* motor_manual, bool bp);
	Ski(const char* name);
	virtual ~Ski();

	void Set_Barefoot_Pole(bool);
	bool Get_Barefoot_Pole() const;

	virtual void Propulsion_Maintenance();
	virtual void Emergency_Procedures();
	virtual void Display() const;
};

#endif
