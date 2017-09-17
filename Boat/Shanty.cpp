// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#include "Shanty.h"

Shanty::Shanty() : MusclePowered(), _number_of_berths(false)
{
	Set_Muscle_Drive_Type(SWEEP);
	Set_Hull_Type(DISPLACEMENT);
}

Shanty::Shanty(double disp, double len, double beam, const char* name, unsigned nos, unsigned nob)
	: MusclePowered(disp, len, beam, DISPLACEMENT, name, SWEEP, nos), _number_of_berths(nob) {}

Shanty::Shanty(const char* name) : MusclePowered(name)
{
	Set_Muscle_Drive_Type(SWEEP);
	Set_Hull_Type(DISPLACEMENT);
}

Shanty::~Shanty() {}

void Shanty::Set_Number_Of_Berths(unsigned nob)
{
	_number_of_berths = nob;
}

unsigned Shanty::Get_Number_Of_Berths()
{
	return _number_of_berths;
}

void Shanty::Emergency_Procedures()
{
	MusclePowered::Emergency_Procedures();

	cout << "If crew are injured, allow them to rest." << endl;
}

void Shanty::Display() const
{
	MusclePowered::Display();

	cout << "Number of berths: " << _number_of_berths << endl;
}
