/*
Joseph Morgan
CISP 400 - MoWe 3:00PM
Programming Progect 1
February 6 2017
*/

#include <cstdio>
#include <iostream>

using namespace std;

enum DATE_STYLE {MM_DD_YYYY, MON_DD_YYYY};
typedef unsigned int Date;
const unsigned MIN_DATE = 1010001;
const unsigned MAX_DATE = 12319999;

unsigned numigits (unsigned num);
int nthDigit (unsigned num, unsigned nth);
void displayDate (const Date& date, ostream& = cout, DATE_STYLE = MM_DD_YYYY);
Date incrementDate (const Date& date);
bool wellFormed (const Date& date);
unsigned month (const Date& date);
unsigned day (const Date& date);
unsigned year (const Date& date);
bool isLeapYear (const Date& date);
unsigned monthLength(const Date& date);
bool lessThan (const Date& date1, const Date& date2);
bool isPalindrome (const Date& date);

int main()
{
  DATE_STYLE ds = MM_DD_YYYY;

  for (Date date = MIN_DATE; date < MAX_DATE; date = incrementDate(date))
  {
    if (isPalindrome(date))
    {
      displayDate(date, cout, ds);
      cout << " is a palindrome.\n";
    }
  }
}

unsigned numDigits (unsigned num) 
{
	int digits;

	if (num == 0)
	{
		digits = 1;
	}
	else
	{
		digits = 0;
	}
	while (num) 
	{
		num /= 10;
		digits++;
	}
	return digits;
}

int nthDigit (unsigned num, unsigned nth) 
{
	int digit = -1; // Initializing digit to a known number
	for (int i = 0; i <= nth && nth < numDigits(num); i++)
	{
		digit = num % 10;
		num /= 10;
	}
	return digit;
}

void displayDate (const Date& date, ostream& os, DATE_STYLE ds)
{
  if (wellFormed(date))
  {
    unsigned dday = day(date);
    unsigned dmonth = month(date);
    unsigned dyear = year(date);
    char* dprefix;
    char* mprefix;
    char* yprefix;
    char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    if (dday < 10)
    {
      dprefix = "0";
    }
    else
    {
      dprefix = "";
    }

    if (dmonth < 10)
    {
      mprefix = "0";
    }

    else
    {
      mprefix = "";
    }

    if (dyear < 10)
    {
      yprefix = "000";
    }
    else if (dyear < 100)
    {
      yprefix = "00";
    }
    else if (dyear < 1000)
    {
      yprefix = "0";
    }
    else
    {
      yprefix = "";
   }

    if (ds == MM_DD_YYYY)
    {
      os << mprefix << dmonth << "/" << dprefix << dday << "/" << yprefix << dyear;
    }
    else if (ds == MON_DD_YYYY)
    {
      dmonth--;
      os << months[dmonth] << " " << dprefix << dday << ", " << yprefix << dyear;
    }
      
  }
  else 
  {
    os << "Date isn't well-formed\n";
  }
}

Date incrementDate (const Date& date)
{
  if (wellFormed(date))
  {
    unsigned dday = day(date);
    unsigned dmonth = month(date);
    unsigned dyear = year(date);

    if (dday < monthLength(date))
    {
      dday++;
    }
    else if (dmonth < 12)
    {
      dmonth++;
      dday = 1;
    }
    else if (dyear < 9999)
    {
      dyear++;
      dmonth = 1;
      dday = 1;
    }
    else
    {
      cout << "Cannot increment date further.\n";
    }
    dmonth *= 1000000;
    dday *=  10000;
    return dmonth + dday + dyear;
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return date;
  }
}

bool wellFormed (const Date& date)
{
  return (date >= MIN_DATE && date <= MAX_DATE) ? true : false;
}

unsigned month (const Date& date)
{
  if (wellFormed(date))
  {
    return (date / 1000000);
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return date;
  }
}

unsigned day (const Date& date)
{
  if (wellFormed(date))
  {
    return (date / 10000) % 100;
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return date;
  }
}
  
unsigned year (const Date& date)
{
  if (wellFormed(date))
  {
    return date % 10000;
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return date;
  }
}

bool isLeapYear (const Date& date)
{
  if (wellFormed(date))
  {
    unsigned dyear = year(date);

    if ((((dyear % 4) == 0) && dyear % 100 !=0) || ((dyear % 400) == 0))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return date;
  }
}

unsigned monthLength(const Date& date)
{
  if (wellFormed(date))
  {
    unsigned length;

    switch (month(date)) {
      case 1 : length = 31;
               break;
      case 2 : length = (isLeapYear(date)) ? 28 : 29;
               break;
      case 3 : length = 31;
               break;
      case 4 : length = 30;
               break;
      case 5 : length = 31;
               break;
      case 6 : length = 30;
               break;
      case 7 : length = 31;
               break;
      case 8 : length = 31;
               break;
      case 9 : length = 30;
               break;
      case 10 : length = 31;
               break;
      case 11 : length = 30;
               break;
      case 12 : length = 31;
               break;
      default : cout << "Not a valid month\n";
    }
    return length;
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return date;
  }
}

bool lessThan (const Date& date1, const Date& date2)
{
  if (wellFormed(date1) && wellFormed(date2))
  {
    unsigned day1 = day(date1);
    unsigned month1 = month(date1);
    unsigned year1 = year(date1);
    unsigned day2 = day(date2);
    unsigned month2 = month(date2);
    unsigned year2 = year(date2);

    if (year1 < year2)
    {
      return true;
    }
    else if ((year1 == year2) && (month1 < month2))
    {
      return true;
    }
    else if ((year1 == year2) && (month1 == month2) && (day1 < day2))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return false;
  }
}

bool isPalindrome (const Date& date)
{
  if (wellFormed(date))
  {
    unsigned dateCopy = date;
    unsigned reversedNum = 0;

    while (dateCopy != 0)
    {
      reversedNum *= 10;
      reversedNum += dateCopy % 10;
      dateCopy /= 10;
    }
    if (numDigits(date) < 8)
    {
      reversedNum *= 10;
    }
    if (reversedNum == date)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    cout << "Date isn't well-formed\n";
		return false;
  }
}
