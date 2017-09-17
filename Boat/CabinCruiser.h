// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#ifndef _CABIN_CRUISER_H_
#define _CABIN_CRUISER_H_

#include "MotorPowered.h"

class CabinCruiser : public MotorPowered
{
	bool _flying_bridge;

	public:
	CabinCruiser();
	CabinCruiser(double disp, double len, double beam, const char* name, const char* _motor_manual, bool is_fb);
	CabinCruiser(const char* name);
	virtual ~CabinCruiser();

	void Set_Flying_Bridge(bool);
	bool Get_Flying_Bridge();

	virtual void Emergency_Procedures();
	virtual void Display() const;
};

#endif
