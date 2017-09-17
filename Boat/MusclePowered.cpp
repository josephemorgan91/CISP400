// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#include "MusclePowered.h"

MusclePowered::MusclePowered() : Boat(), _mudt(UKMUDT), _number_of_seats(1) {}

MusclePowered::MusclePowered(double disp, double len, double beam, HULL_TYPE ht, const char* name, MUSCLE_DRIVE_TYPE mudt, unsigned nos)
	: Boat(disp, len, beam, ht, name), _mudt(mudt), _number_of_seats(nos)
{
	_check_enum();
}

MusclePowered::MusclePowered(const char* name) : Boat(name), _mudt(UKMUDT), _number_of_seats(1) {}

MusclePowered::~MusclePowered() {}

void MusclePowered::Set_Muscle_Drive_Type(MUSCLE_DRIVE_TYPE mudt)
{
	_mudt = mudt;
	_check_enum();
}

MUSCLE_DRIVE_TYPE MusclePowered::Get_Muscle_Drive_Type()
{
	return _mudt;
}

void MusclePowered::Set_Number_Of_Seats(unsigned nos)
{
	_number_of_seats = nos;
}

unsigned MusclePowered::Get_Number_Of_Seats()
{
	return _number_of_seats;
}

void MusclePowered::Propulsion_Maintenance()
{
	cout << endl << "Propulsion Maintenance for muscle-powered vessel \"" << Get_Name() << "\" Feed the crew." << endl;
}

void MusclePowered::Emergency_Procedures()
{
	Boat::Emergency_Procedures();

	cout << "If crew are injured, allow them to rest.";
}

void MusclePowered::Display() const
{
	Boat::Display();
	cout << "   Muscle Drive Type: ";
	switch(_mudt)
	{
		case PADDLE: cout << "Paddle"; break;
		case OAR: cout << "Oar"; break;
		case POLE: cout << "Pole"; break;
		case SWEEP: cout << "Sweep"; break;
		default: cout << "Unknown";
	}
	cout << endl << "   Number of Seats: " << _number_of_seats << endl;
}

void MusclePowered::_check_enum()
{
	_mudt = (_mudt < MAX_MUDT) ? _mudt : UKMUDT;
}
