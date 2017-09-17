// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#include "CabinCruiser.h"

CabinCruiser::CabinCruiser() : MotorPowered(), _flying_bridge(false)
{
	Set_Hull_Type(SEMI_DISP);
	Set_Motor_Drive_Type(OUTBOARD);
	Set_Fuel_Type(GASOLINE);
}

CabinCruiser::CabinCruiser(double disp, double len, double beam, const char* name, const char* mm, bool is_fb)
	: MotorPowered(disp, len, beam, SEMI_DISP, name, GASOLINE, OUTBOARD, mm), _flying_bridge(is_fb)
{
}

CabinCruiser::CabinCruiser(const char* name) : MotorPowered(name), _flying_bridge(false)
{
	Set_Hull_Type(SEMI_DISP);
	Set_Motor_Drive_Type(OUTBOARD);
	Set_Fuel_Type(GASOLINE);
}

CabinCruiser::~CabinCruiser() {}

void CabinCruiser::Set_Flying_Bridge(bool is_fb)
{
	_flying_bridge = is_fb;
}

bool CabinCruiser::Get_Flying_Bridge()
{
	return _flying_bridge;
}

void CabinCruiser::Emergency_Procedures()
{
	MotorPowered::Emergency_Procedures();

	cout << "   Get off of the flying bridge\n";
}

void CabinCruiser::Display() const
{
	MotorPowered::Display();

	cout << (_flying_bridge ? "Has a flying bridge\n" : "Doesn't have a flying bridge\n");
}
