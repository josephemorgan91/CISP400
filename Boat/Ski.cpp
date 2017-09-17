// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#include "Ski.h"

Ski::Ski() : MotorPowered()
{
	Set_Fuel_Type(GASOLINE);
	Set_Motor_Drive_Type(OUTBOARD);
	Set_Hull_Type(PLANING);
}

Ski::Ski(double disp, double len, double beam, const char* name, const char* motor_manual, bool bp)
	: MotorPowered(disp, len, beam, PLANING, name, GASOLINE, OUTBOARD, motor_manual), _barefoot_pole(bp) {}

Ski::Ski(const char* name) : MotorPowered(name)
{
	Set_Fuel_Type(GASOLINE);
	Set_Motor_Drive_Type(OUTBOARD);
	Set_Hull_Type(PLANING);
}

Ski::~Ski(){}

void Ski::Set_Barefoot_Pole(bool bp)
{
	_barefoot_pole = bp;
}

bool Ski::Get_Barefoot_Pole() const
{
	return _barefoot_pole;
}

void Ski::Propulsion_Maintenance ( )
{
	cout <<endl<<"Propulsion Maintenance for ski vessel \"" << Get_Name() <<"\""
		<< endl<< "   Wash and repair the motor"<<endl
		<< "   Lubricate the motor" << endl
		<< "   Inspect and belay the motor and motor"<<endl;
}

void Ski::Emergency_Procedures ( )
{
	MotorPowered::Emergency_Procedures();
	cout <<endl<< "   Get off Ski's" << endl;
}
void Ski::Display() const
{
	MotorPowered::Display();
	cout << (Get_Barefoot_Pole() ? "Is a barefoot pole." : "Isn't a barefoot pole.");
}
