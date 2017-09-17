// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#ifndef _MARINA_H_
#define _MARINA_H_

#include "Ski.h"
#include "CabinCruiser.h"
#include "Kayak.h"
#include "Shanty.h"

enum TYPE_OF_BOAT {SKI, CABINCRUISER, KAYAK, SHANTY};
enum CONSTRUCTOR {ZERO, ONE, MAX};

const int SIZE = 20;

class Marina
{
	Boat* _boats[SIZE];
	int _index; // Index of last boat added - Also equal to (number of boats - 1)

	void Add_Boat(); // Gets info about type of boat to be created and desired detail with which to create, calls Create_Boat()

	void Display_Emergency_Procedures (Boat*);
	void Display_Propulsion_Maintenance (Boat*);
	void Display_Boats();

	public:

	Marina();
	virtual ~Marina();

	void Run();

};

#endif
