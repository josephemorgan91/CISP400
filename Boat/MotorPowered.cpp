// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#include "MotorPowered.h"

namespace Util
{
	const char* generic_manual = "Please read carefully before operation";
} // Getting weird errors about this already being defined, namespace is a workaround

MotorPowered::MotorPowered() :Boat(), _ft(UKFT), _modt(UKMODT), _motor_manual(Util::generic_manual) {}

MotorPowered::MotorPowered(double disp, double len, double beam, HULL_TYPE ht, const char* name, FUEL_TYPE ft, MOTOR_DRIVE_TYPE modt, const char* _motor_manual)
	:Boat(disp, len, beam, ht, name), _ft(ft), _modt(modt), _motor_manual(Util::generic_manual)
{
	_check_enum();
}

MotorPowered::MotorPowered(const char* name) :Boat(name), _ft(UKFT), _modt(UKMODT), _motor_manual(Util::generic_manual)
{
}

MotorPowered::~MotorPowered(){}

void MotorPowered::Set_Fuel_Type(FUEL_TYPE ft)
{
	_ft = ft;
	_check_enum();
}

FUEL_TYPE MotorPowered::Get_Fuel_Type() const
{
	return _ft;
}

void MotorPowered::Set_Motor_Drive_Type(MOTOR_DRIVE_TYPE modt)
{
	_modt = modt;
	_check_enum();
}

MOTOR_DRIVE_TYPE MotorPowered::Get_Motor_Drive_Type() const
{
	return _modt;
}

void MotorPowered::Set_Motor_Manual(const char* mm)
{
	_motor_manual = mm;
}

const char* MotorPowered::Get_Motor_Manual() const
{
	return _motor_manual;
}
void MotorPowered::Propulsion_Maintenance ( )
{
	cout << endl <<"Propulsion Maintenance for motor-powered vessel \"" << Get_Name() <<"\""
		<< endl << "   Inspect propellors for damage." << endl;
}

void MotorPowered::Emergency_Procedures ( )
{
	Boat::Emergency_Procedures();
	cout <<endl<< "   Turn off the motor" << endl;
}
void MotorPowered::Display() const
{
	Boat::Display();

	cout << "   Fuel Type: ";
	switch(_ft)
	{
		case DIESEL: cout << "Diesel"; break;
		case ELECTRIC: cout << "Electric"; break;
		case GASOLINE: cout << "Gasoline"; break;
		default: cout << "Unknown";
	}
	cout << endl << "   Motor Drive Type: ";
	switch(_modt)
	{
		case INBOARD: cout << "Inboard"; break;
		case IOBOARD: cout << "IOboard"; break;
		case OUTBOARD: cout << "Outboard"; break;
		default: cout << "Unknown";
	}
	cout << endl << "   Motor Manual: " << _motor_manual << endl;
}

void MotorPowered::_check_enum()
{
	_ft = (_ft < MAX_FT) ? _ft : UKFT;
	_modt = (_modt < MAX_MODT) ? _modt : UKMODT;
}
