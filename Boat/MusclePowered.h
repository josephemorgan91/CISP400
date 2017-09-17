// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#ifndef _MUSCLE_POWERED_H_
#define _MUSCLE_POWERED_H_

#include <iostream>
#include "Boat.h"

enum MUSCLE_DRIVE_TYPE {UKMUDT, PADDLE, OAR, POLE, SWEEP};

const unsigned MAX_MUDT = 5;

class MusclePowered : public Boat
{
	MUSCLE_DRIVE_TYPE _mudt;
	unsigned _number_of_seats;
	void _check_enum();

	public:
	MusclePowered();
	MusclePowered(double disp, double len, double beam, HULL_TYPE ht, const char* name, MUSCLE_DRIVE_TYPE mudt, unsigned nos);
	MusclePowered(const char* name);
	virtual ~MusclePowered();

	void Set_Muscle_Drive_Type(MUSCLE_DRIVE_TYPE);
	MUSCLE_DRIVE_TYPE Get_Muscle_Drive_Type();

	void Set_Number_Of_Seats(unsigned);
	unsigned Get_Number_Of_Seats();

	virtual void Propulsion_Maintenance();
	virtual void Emergency_Procedures();
	virtual void Display() const;
};

#endif
