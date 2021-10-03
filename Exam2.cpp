#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{

public:
Date(int = 1, int = 1, int = 1900);
int getday() const;
int getmonth() const;
int getyear() const;
void setday(int);
void setmonth(int);
void setyear(int);

bool operator==(const Date&);
friend std::ostream& operator<<(std::ostream&, const Date&);

private:
int month, day, year;

};
#endif

int Date::getday() const
{
	return day;
}

void Date::setday(int day)
{
	if(day<1 || day>31)
	{
		this->day = 1;
		return;
	}
	this->day = day;
}

int Date::getmonth() const
{
	return month;
}

void Date::setmonth(int month)
{
		if(month<1 || month>12)
	{
		this->month = 1;
		return;
	}
	this->month = month;
}

int Date::getyear() const
{
	return year;
}

void Date::setyear(int year)
{
	this->year = year;
}

Date::Date(int month, int day, int year)
{
	setday(day);
	setmonth(month);
	setyear(year);
}


bool Date::operator==(const Date& d)
{
	if(day == d.day && month == d.month && year == d.year)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& o, const Date& d)
{
	o << d.month << "/" << d.day << "/" << d.year;
	return o; 
}

int main()
{
    Date d1;
    Date d2(2,2,2222);
    Date d3(15,33,1900);

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;    

    if(d1==d2){std::cout << "no";}else{std::cout << "yes";}std::cout<<std::endl;
    if(d1==d3){std::cout << "yes";}else{std::cout << "no";}std::cout<<std::endl;	
}

