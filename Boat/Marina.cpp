// Joseph Morgan
// CISP 400 MoWe 3:00pm
// Project 5
// 2017-04-03

#include "Marina.h"

namespace util
{
	const char* tabline = "\n    ";
}

Boat* Helper_Boat_Config(TYPE_OF_BOAT); // TODO: Doesn't have to access member data, should be a helper function... right?

Marina::Marina() : _index(-1)
{
	for (int i = 0; i < SIZE; i++)
	{
		_boats[i] = NULL;
	}
}

Marina::~Marina()
{
	if (_index != -1)
	{
		for (int i = 0; i <= _index; i++)
		{
			delete _boats[i];
			_boats[i] = NULL;
		}

	_index = -1;
	}
}

void Marina::Add_Boat()
{
	if (_index < SIZE - 1)
	{
		_index++;

		char type;

		cout << "What kind of boat would you like to add?\nOptions are:" << util::tabline <<
		"[s] - Ski." << util::tabline <<
		"[c] - Cabin Cruiser." << util::tabline <<
		"[k] - Kayak." << util::tabline <<
		"[t] - Shanty." << endl << endl;
		cout << "Please make a seleciton. *note that selections are case-sensitive*: ";
		cin >> type;
		cout << endl;

		switch (type)
		{
			case 'c':
				_boats[_index] = Helper_Boat_Config(CABINCRUISER);
				break;
			case 'k':
				_boats[_index] = Helper_Boat_Config(KAYAK);
				break;
			case 't':
				_boats[_index] = Helper_Boat_Config(SHANTY);
				break;
			case 's':
				_boats[_index] = Helper_Boat_Config(SKI);
				break;
			default:
				cout << "Invalid TYPE_OF_BOAT\n";
		}

	}
	else
	{
		cout << "The Marina is full!\n";
	}
}

void Marina::Display_Boats()
{
	for (int i = 0; i <= _index; i++)
	{
		_boats[i]->Display();
	}
}

void Marina::Display_Emergency_Procedures(Boat* boat)
{
	boat->Emergency_Procedures();
}

void Marina::Display_Propulsion_Maintenance(Boat* boat)
{
	boat->Propulsion_Maintenance();
}

void Marina::Run()
{
	bool exit = false;

	char selection;
	cout << "--- Marina Simulation Initializing ---\n" << endl << endl;

	while (!exit)
	{
		cout << "Your options are" << util::tabline <<
		"[a] - Add a new boat." << util::tabline <<
		"[d] - Display all boats in marina." << util::tabline << 
		"[e] - Display Emergency Procedures each boat." << util::tabline <<
		"[p] - Display Propulsion Maintenance for each boat." << util::tabline <<
		"[q] - Exit the simulation" << endl;
		cout << "Please make a selection *note that selections are case-sensitive*: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
			case 'a':
				Add_Boat();
				break;

			case 'd':
				if (_index != -1)
				{
					for (int i = 0; i <= _index; i++)
					{
						_boats[i]->Display();
					}
				}
				else
				{
					cout << "The marina is empty!\n";
				}
				break;

			case 'e':
				if (_index != -1)
				{
					for (int i = 0; i <= _index; i++)
					{
						_boats[i]->Emergency_Procedures();
					}
				}
				else
				{
					cout << "The marina is empty!\n";
				}
				break;

			case 'p':
				if (_index != -1)
				{
					for (int i = 0; i <= _index; i++)
					{
						_boats[i]->Propulsion_Maintenance();
					}
				}
				else
				{
					cout << "The marina is empty!\n";
				}
				break;

			case 'q':
				exit = true;
				break;

			default:
				cout << "That didn't appear to be a valid option!\n";
		}
	}
}

Boat* Helper_Boat_Config(TYPE_OF_BOAT type)
{
	Boat* new_boat = NULL;
	CONSTRUCTOR cons = ZERO;
	char response = 'n';

	cout << "Would you like to specify exact dimensions and specifications of your boat? (y/n): ";
	cin >> response;
	cout << endl;

	if (response == 'y')
	{
		cons = MAX;
	}

	else
	{
		cout << "Would you like to name your boat? (y/n): ";
		cin >> response;
		cout << endl;

		if (response == 'y')
		{
			cons = ONE;
		}
	}

	response = 'n';

	switch (type)
	{
		case CABINCRUISER:
			{
				if (cons == ZERO) new_boat = new CabinCruiser();

				else if (cons == ONE)
				{
					char* name =  new char[30];
					
					cout << "What would you like to name your boat?\n";
					cin >> name;
					cout << endl;

					new_boat = new CabinCruiser(name);
				}

				else if (cons == MAX)
				{
					double disp, len, beam;
					char* name = new char[30];
					char* mm = new char[30];
					bool is_fb = false;
					char y_n;

					cout << "What's the displacement of your boat? ";
					cin >> disp;
					cout << endl;

					cout << "What's the length of your boat? ";
					cin >> len;
					cout << endl;

					cout << "What's the beam length of your boat? ";
					cin >> beam;
					cout << endl;

					cout << "What would you like to name your boat? ";
					cin >> name;
					cout << endl;

					cout << "Does this boat have a flying bridge? (y/n): ";
					cin >> y_n;
					if (y_n == 'y') is_fb = true;
					cout << endl;

					new_boat = new CabinCruiser(disp, len, beam, name, mm, is_fb);
				}

				break;
			}

		case KAYAK:
			{
				if (cons == ZERO) new_boat = new Kayak();

				else if (cons == ONE)
				{
					char* name =  new char[30];
					
					cout << "What would you like to name your boat?\n";
					cin >> name;
					cout << endl;

					new_boat =new Kayak(name);
				}

				else if (cons == MAX)
				{
					double disp, len, beam;
					char* name =  new char[30];
					unsigned nos;
					bool is_ww = false;
					char y_n;

					cout << "What's the displacement of your boat? ";
					cin >> disp;
					cout << endl;

					cout << "What's the length of your boat? ";
					cin >> len;
					cout << endl;

					cout << "What's the beam length of your boat? ";
					cin >> beam;
					cout << endl;

					cout << "What would you like to name your boat? ";
					cin >> name;
					cout << endl;

					cout << "How many seats are on your boat? ";
					cin >> nos;
					cout << endl;

					cout << "Is your boat white-water capable? (y/n): ";
					cin >> y_n;
					if (y_n == 'y') is_ww = true;
					cout << endl;

					new_boat = new Kayak(disp, len, beam, name, nos, is_ww);
				}

				break;
			}

		case SHANTY:
			{
				if (cons == ZERO) new_boat = new Shanty();

				else if (cons == ONE)
				{
					char* name =  new char[30];
					
					cout << "What would you like to name your boat?\n";
					cin >> name;
					cout << endl;

					new_boat =new Shanty(name);
				}

				else if (cons == MAX)
				{
					double disp, len, beam;
					char* name =  new char[30];
					unsigned nos;
					unsigned nob;

					cout << "What's the displacement of your boat? ";
					cin >> disp;
					cout << endl;

					cout << "What's the length of your boat? ";
					cin >> len;
					cout << endl;

					cout << "What's the beam length of your boat? ";
					cin >> beam;
					cout << endl;

					cout << "What would you like to name your boat? ";
					cin >> name;
					cout << endl;

					cout << "How many seats are on your boat? ";
					cin >> nos;
					cout << endl;

					cout << "How many berths are on your boat? ";
					cin >> nob;
					cout << endl;

					new_boat = new Shanty(disp, len, beam, name, nos, nob);
				}

				break;
			}

		case SKI:
			{
				if (cons == ZERO) new_boat = new Ski();

				else if (cons == ONE)
				{
					char* name =  new char[30];
					
					cout << "What would you like to name your boat?\n";
					cin >> name;
					cout << endl;

					new_boat = new Ski(name);
				}

				else if (cons == MAX)
				{
					double disp, len, beam;
					char* name =  new char[30];
					char* mm =  new char[300];
					bool is_bp = false;
					char y_n;

					cout << "What's the displacement of your boat? ";
					cin >> disp;
					cout << endl;

					cout << "What's the length of your boat? ";
					cin >> len;
					cout << endl;

					cout << "What's the beam length of your boat? ";
					cin >> beam;
					cout << endl;

					cout << "What would you like to name your boat? ";
					cin >> name;
					cout << endl;

					cout << "Does your boat have a barefoot pole? (y/n): ";
					cin >> y_n;
					if (y_n == 'y') is_bp = true;
					cout << endl;

					new_boat = new Ski(disp, len, beam, name, mm, is_bp);
				}
				
				break;
			}

			default:
			cerr << "Cannot Create: Invalid Boat\n" ;
	}

	return new_boat;
}
