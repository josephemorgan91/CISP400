// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#ifndef _MOTOR_POWERED_H_
#define _MOTOR_POWERED_H_

#include <iostream>
#include "Boat.h"

enum FUEL_TYPE {UKFT, DIESEL, GASOLINE, ELECTRIC};
enum MOTOR_DRIVE_TYPE {UKMODT, INBOARD, OUTBOARD, IOBOARD};

const unsigned MAX_FT = 4;
const unsigned MAX_MODT = 4;

class MotorPowered : public Boat
{
	FUEL_TYPE _ft;
	MOTOR_DRIVE_TYPE _modt;
	const char* _motor_manual;
	void _check_enum();

	public:
	MotorPowered();
	MotorPowered(double disp, double len, double beam, HULL_TYPE ht, const char* name, FUEL_TYPE ft, MOTOR_DRIVE_TYPE modt, const char* _motor_manual);
	MotorPowered(const char* name);
	virtual ~MotorPowered();

	void Set_Fuel_Type(FUEL_TYPE);
	FUEL_TYPE Get_Fuel_Type() const;

	void Set_Motor_Drive_Type(MOTOR_DRIVE_TYPE);
	MOTOR_DRIVE_TYPE Get_Motor_Drive_Type() const;

	void Set_Motor_Manual(const char*);
	const char* Get_Motor_Manual() const;

	virtual void Propulsion_Maintenance();
	virtual void Emergency_Procedures();
	virtual void Display() const;
};

#endif
