#include "dateAndDay.h"

dateAndDay::dateAndDay(int y, int m, int d) : date()
{
	bool isLeapYear;
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
			{
				isLeapYear = true;
			}
			else
			{
				isLeapYear = false;
			}
		}
		else
		{
			isLeapYear = true;
		}
	}
	else
	{
		isLeapYear = false;
	}

	if (y < 1)
	{
		throw std::out_of_range("Error out_of_range: Year must be greater than 0\n");
	}
	if (m < 1)
	{
		throw std::out_of_range("Error out_of_range: Month must be greater than 0\n");
	}
	if (m > 12)
	{
		throw std::out_of_range("Error out_of_range: Month must be within the range of 1-12.\n");
	}
	if (d < 1)
	{
		throw std::out_of_range("Error out_of_range: Day must be greater than 0\n");
	}
	if ((m == 4 || m == 6 || m == 9 || m == 10) && d > 30)
	{
		throw std::out_of_range("Error out_of_range: During April(4), June(6), September(9), and November(11), the day may not be greater than 30,\n otherwise it must be less than 31.\n");
	}
	if ((m == 1 || m == 2 || m == 3 || m == 5 || m == 7 || m == 8 || m == 11 || m == 12) && d > 31)
	{
		throw std::out_of_range("Error out_of_range: During April(4), June(6), September(9), and November(11), the day may not be greater than 30,\n otherwise it must be less than 31.\n");
	}
	//std::cout << "is leap year: " << isLeapYear << std::endl;
	if ((m == 2) && (isLeapYear == true) && d > 29)
	{
		throw std::out_of_range("Error out_of_range: During a leap year, the month of Feburary only has 29 days.\n");
	}
	if ((m == 2) && (isLeapYear == false) && d > 28)
	{
		throw std::out_of_range("Error out_of_range: During a common year, the month of Feburary has 28 days.\n");
	}
	else
	{
		this->setDate(y, m, d);
	}
}

weekday dateAndDay::dayOfWeek()
{

	// use the fact that October 17 is a wednesday.
	date *p = new date;

	p->setDate(2018, 10, 17);
	int d = this->difference(p);
	delete p;
	weekday result;
	switch (d % 7)
	{
	case 0:
		result = wednesday;
		break;
	case -1:
	case 6:
		result = tuesday;
		break;
	case -2:
	case 5:
		result = monday;
		break;
	case -3:
	case 4:
		result = sunday;
		break;
	case -4:
	case 3:
		result = saturday;
		break;
	case -5:
	case 2:
		result = friday;
		break;
	case -6:
	case 1:
		result = thursday;
		break;
	}
	return result;
};