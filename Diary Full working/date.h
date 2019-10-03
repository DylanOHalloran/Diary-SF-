#pragma once
class date {
private:
	int year, month, day;

protected:
	int dayNumber;

public:
	date();
	~date();
	void setDate(int y, int m, int d);
	int difference(date *p);
	int getYear();
	int getMonth();
	int getDay();
	int getDayNumber();
	bool isLeapYear();
};