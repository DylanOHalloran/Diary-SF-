#pragma once
#include "dateAndDay.h"
class dateDayAndWeek : public dateAndDay
{
  public:
	dateDayAndWeek(int y, int m, int d);
	int weekNumber();
};