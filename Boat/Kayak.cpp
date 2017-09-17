// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#include "Kayak.h"

Kayak::Kayak() : MusclePowered(), _whitewater(false)
{
	Set_Muscle_Drive_Type(PADDLE);
	Set_Hull_Type(DISPLACEMENT);
}

Kayak::Kayak(double disp, double len, double beam, const char* name, unsigned nos, bool is_ww)
	: MusclePowered(disp, len, beam, DISPLACEMENT, name, PADDLE, nos), _whitewater(is_ww)
{
	if (Get_Number_Of_Seats() > 2)
	{
		cout << "Maximum of 2 seats possible in a Kayak!\n";
		Set_Number_Of_Seats(2);
	}
}

Kayak::Kayak(const char* name) : MusclePowered(name), _whitewater(false) {}

Kayak::~Kayak() {}

void Kayak::Set_Whitewater(bool is_ww)
{
	_whitewater = is_ww;
}

bool Kayak::Get_Whitewater()
{
	return _whitewater;
}

void Kayak::Emergency_Procedures()
{
	MusclePowered::Emergency_Procedures();

	cout << "If crew are injured, allow them to rest." << endl;
}

void Kayak::Display() const
{
	MusclePowered::Display();

	cout << (_whitewater ? "Is whitewater capable" : "Is not whitewater capable");
}
