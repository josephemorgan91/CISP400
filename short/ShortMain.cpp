#include "Short.h"

display_type toDisplayType (int num)
{
	display_type dt = static_cast<display_type>(num);
	return dt;
}

Short s;
Short t;

void display()
{
	s.set_display_type(DEC);
	s.display();
	cout << " : ";
	s.set_display_type(HEX);
	s.display();
	cout << " : ";
	s.set_display_type(BIN);
	s.display();
	cout << endl;
}

int main()
{
	short i;
	signed char c = 0;
	int dt = DEC;
	bool cont = true;
	char input;
	while (cont == true)
	{
		cout << "Please enter the number the short will contain: ";
		cin >> i;
		c = i;
		cout << endl;
		s.set_value(c);
		display();
		cout << "Please enter the number the second short will contain: ";
		cin >> i;
		c = i;
		cout << endl;
		t.set_value(c);
		display();

		cout << "add: \n";
		s.add(t);
		display();
		cout << "sub: \n";
		s.sub(t);
		display();
		cout << "mult: \n";
		s.mult(t);
		display();
		cout << "div: \n";
		s.div(t);
		display();
	}
}
