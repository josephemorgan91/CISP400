/*
Joseph Morgan
CISP 400 - MW 3:00PM
Programming Progect 1
February 10, 2016
*/

unsigned num_digits (unsigned long l) 
{
	// Returns the number of digits in l
	int digits;
	if (l == 0)
	{
		digits = 1;
	}
	else
	{
		digits = 0;
	}
	while (l) 
	{
		l /= 10;
		digits++;
	}
	return digits;
}

int nth_digit (unsigned long l, unsigned n) 
{
	// Returns the position of n in l

	int digit = -1;
	for (int i = 0; i <= n && n < num_digits(l); i++)
	{
		digit = l % 10;
		l /= 10;
	}
	return digit;
}

unsigned long rev_digits (unsigned long l)
{
	// Returns a reversed version of l
	unsigned long reversedNum = 0;
	while (l != 0)
	{
		reversedNum *= 10;
		reversedNum += l % 10;
		l /= 10;
	}
	return reversedNum;
}

bool is_palindrome (unsigned long l) {
	bool isPalindrome = false;
	if (l == rev_digits(l))
	{
		isPalindrome = true;
	}
	return isPalindrome;
}

bool P196 (unsigned long l)
{
   bool result = false;
   unsigned long previousL;
   if (is_palindrome(l + rev_digits(l)))
   {
	   result = true; //yay
   } else 
   {
	   previousL = l;
	   l += rev_digits(l);
	   if (l > previousL)
	   {
		   result = P196(l);
	   }
   }
   return result;
}
