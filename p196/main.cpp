#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <time.h>
#include "P196.h"

void testNumDigits()
{
	// Tests num_digits() for various values from 0 to ULONG_MAX - 1. 
	std::cout << "There is (are) " << num_digits(0) << " digit(s) in 0" << std::endl;
	for (unsigned long l = 1; l < ULONG_MAX - 1; (l * 2 != 0) ? l *= 2 : l = ULONG_MAX) 
	{
		std::cout << "There is (are) " << num_digits(l) << " digit(s) in " << l << std::endl;
    }
}

void testNthDigit()
{
	// Tests nth_digit() with each valid position in 10 random numbers from 0 to ULONG_MAX - 1.
	for (int i = 1; i <= 10; i++) 
	{
		unsigned long number = rand() % ULONG_MAX;
		for (int position = 0; position <= num_digits(number); position++)
		{
			std::cout << "The number in position " << position << " of " << number << " is " << nth_digit(number, position) << std::endl;
		}
	}
}

void testRevDigits()
{
	// Tests rev_digits() with 10 random numbers from 0 to ULONG_MAX - 1.
	for (int i = 1; i <= 10; i++) 
	{
		unsigned long number = rand() % ULONG_MAX;
		std::cout << "When reversed, " << number << " is " << rev_digits(number) << std::endl;
	}
}

void testIsPalindrome()
{
	// Tests is_palindrome by running random numbers from 0 to ULONG_MAX - 1 until one is found
	unsigned long number = rand() % ULONG_MAX;
	while (!is_palindrome(number))
	{
		std::cout << number << " is not a palindrome." << std::endl;
		number = rand() % ULONG_MAX;
	}
	std::cout << number << " is a palindrome." << std::endl;
}

bool testIsP196()
{
	// Tests P196() by randomly selecting numbers from 0 to ULONG_MAX -1
	int countIS = 0;
	int countISNT = 0;
	double ratio;
	unsigned long number = rand() % ULONG_MAX;
	for (int i = 0; i < 100000; i++)
	{
		number = rand() % ULONG_MAX;
		if (!P196(number))
		{
			std::cout << number << " is not a p196 number." << std::endl; 
			countISNT++;
		}
		else
		{
	    	std::cout << number << " is a p196 number." << std::endl;
			countIS++;
		}
	}
	ratio = ((countIS + countISNT) / countIS);
	std::cout << "Numbers that fit: " << countIS << "\nNumbers that didn't: " << countISNT << std::endl;
}

void testLychrel()
{
	int lychrel[35] = 
	{ 
196, 879, 1997, 7059, 10553, 10563, 10577, 10583, 10585, 10638, 10663, 10668, 10697, 10715, 10728, 10735, 10746, 10748, 10783, 10785, 10787, 10788, 10877, 10883, 10963, 10965, 10969, 10977, 10983, 10985, 12797, 12898, 13097, 13197, 13694
	};
	for (int i = 0; i < 35; i++) {
		P196(lychrel[i]) ? std::cout << "Lychrel " << lychrel[i] << ": Fail!" << std::endl
		: std::cout <<"Lychrel " << lychrel[i] << ": Pass!" << std::endl;
	}
}


int main() 
{
	srand(time(NULL));
	testNumDigits();
	testNthDigit();
	testRevDigits();
	testIsPalindrome();
	testIsP196();
	testLychrel();
}
