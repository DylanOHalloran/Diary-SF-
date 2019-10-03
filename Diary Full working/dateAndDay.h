#pragma once
#include <stdexcept>
#include <iostream>
#include "date.h"
// weeks begin on Monday according to ISO 8601, hence the following
enum weekday
{
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
	sunday
}; //
class dateAndDay : public date
{
  public:
	dateAndDay(int y, int m, int d);
	weekday dayOfWeek();
};