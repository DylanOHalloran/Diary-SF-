#include "dateDayAndWeek.h"

dateDayAndWeek::dateDayAndWeek(int y, int m, int d) : dateAndDay(y, m, d) {}

int dateDayAndWeek::weekNumber()
{
	int result = 0; // zero or negative means something went wrong It should be positive non-zero
	// weeks begin on Monday according to ISO 8601.
	// week 1 of a year is the week of the first thursday

	//get the day of jan 1 of the year
	int firstDayOfAWeekInThisYear;
	dateAndDay *p = new dateAndDay(this->getYear(), 1, 1);
	weekday jan1Day = p->dayOfWeek();
	switch (jan1Day)
	{
	case sunday:
		// this means monday 2 jan is the first day of the first week contained in this year
		firstDayOfAWeekInThisYear = 2;
		break;
	case monday:
		// this means monday 1 jan is the first day of the first week contained in this year
		firstDayOfAWeekInThisYear = 1;
		break;
	case tuesday:
		// this means tuesday 1 jan is the first day of the first week contained in this year
		firstDayOfAWeekInThisYear = 1;
		break;
	case wednesday:
		// this means wednesday 1 jan is the first day of the first week contained in this year
		firstDayOfAWeekInThisYear = 1;
		break;
	case thursday:
		// this means thursday 1 jan is the first day of the first week contained in this year
		firstDayOfAWeekInThisYear = 1;
		break;
	case friday:
		// this means monday 4 jan is the first day of the first week contained in this year
		firstDayOfAWeekInThisYear = 4;
		break;
	case saturday:
		// this means monday 3 jan is the first day of the first week contained in this year
		firstDayOfAWeekInThisYear = 3;
		break;
	}
	// now, we can check that the date does not belong to the previous year.
	if ((this->getDay() < firstDayOfAWeekInThisYear) && (this->getMonth() == 1))
	{
		result = -1;
	}
	else if (this->getMonth() == 12)
	{
		// now see if the date belongs to the next year
		//get the day of december 31 of the year
		int lastDayOfAWeekInThisYear;
		p->setDate(this->getYear(), 12, 31);
		weekday dec31Day = p->dayOfWeek();
		switch (dec31Day)
		{
		case sunday:
			// this means sunday 31 dec is the last day of the last week contained in this year
			lastDayOfAWeekInThisYear = 31;
			break;
		case monday:
			// this means sunday 30 dec is the last day of the last week contained in this year
			lastDayOfAWeekInThisYear = 30;
			break;
		case tuesday:
			// this means sunday 29 dec is the last day of the last week contained in this year
			lastDayOfAWeekInThisYear = 29;
			break;
		case wednesday:
			// this means sunday 28 dec is the last day of the last week contained in this year
			lastDayOfAWeekInThisYear = 28;
			break;
		case thursday:
			// this means thursday 31 dec is the last day of the last week contained in this year
			lastDayOfAWeekInThisYear = 31;
			break;
		case friday:
			// this means friday 31 dec is the last day of the last week contained in this year
			lastDayOfAWeekInThisYear = 31;
			break;
		case saturday:
			// this means saturday 31 dec is the last day of the last week contained in this year
			lastDayOfAWeekInThisYear = 31;
			break;
		}
		if (this->getDay() > lastDayOfAWeekInThisYear)
			result = -2;
	}

	if (result == 0)
	{ // i.e. no error discovered so far...
		p->setDate(this->getYear(), 1, firstDayOfAWeekInThisYear);
		int daysElapsed = this->difference(p);
		result = 1 + daysElapsed / 7;
	}
	delete p;
	return result;
};