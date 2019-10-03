// #include <iostream>
#include "date.h"

date::date() {
	// std::cout << "default constructor called\n";
};

date::~date() {
	// std::cout << "destructor called\n";
};

int date::getDay() {
	return this->day;
}

int date::getMonth() {
	return this->month;
}

int date::getYear() {
	return this->year;
}

int date::getDayNumber(){
	return this->dayNumber;
}

void date::setDate(int y, int m, int d) {
	
	this->year = y;
	this->month = m;
	this->day = d;

	int leapDays = (this->year - 1) / 4;
	leapDays -= (this->year - 1) / 100;
	leapDays += (this->year - 1) / 400;

	this->dayNumber = 365 * (this->year - 1) + leapDays;

	// now account for all the onths completed in the year to date
	int monthLength[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < this->month - 1; i++) {
		this->dayNumber += monthLength[i];
	};

	// if this year is a leap year and we're after february, add 1
	if ((this->month > 2) && (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0)))
		this->dayNumber++;

	this->dayNumber += this->day - 1;
};

int date::difference(date *p) {
	int d;
	d = this->dayNumber - p->dayNumber;
	return d;
}

bool date::isLeapYear(){
	int leapDays = (this->year - 1) / 4;
	leapDays -= (this->year - 1) / 100;
	leapDays += (this->year - 1) / 400;
	if(leapDays == 1){
		return 1;
	}
	else{
		return 0;
	}
}