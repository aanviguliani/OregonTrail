//include statements
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Miles.h"
#include <string>

using namespace std;



//constructor
Miles::Miles()
{
    month = 0;
    day = 0;
    year = 0;
    miles = 0;
    endDay = 0;
    endMonth = 0;
    endYear = 0;
}

Miles::Miles(int numMiles, int numDays,int numMonth,int numYear,int endGameDay,int endGameMonth,int endGameYear)
{
    miles = numMiles;
    month = numMonth;
    day = numDays;
    year = numYear;
    endMonth = endGameMonth;
    endDay = endGameDay;
    endYear = endGameYear;
}

void Miles::setNumMiles(int m)
{
    miles = m;
}

void Miles::setDate(int numDays,int Month,int numYear)
{
    day = numDays;
    month = Month;
    year = numYear;
}

void Miles::setEndDate(int dayEnd,int monthEnd,int yearEnd)
{
    endDay = dayEnd;
    endMonth = monthEnd;
    endYear = yearEnd;
}

int Miles::getNumMiles()
{
    return miles;
}

int Miles::getDay()
{
    if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        day = day -  30;
        month++;
        return day;
    }
    
    else if(day > 31 && (month == 1 || month ==3 ||month==5 || month ==7 || month == 8))
    {
        day = day - 31;
        month++;
        return day;
    }
    
    else if(day > 28 && month == 2 && year == 1847)
    {
        day = day - 28;
        month++;
        return day;
    }
    
    else
        return day;
}

int Miles::getMonth()
{
    if(month > 12)
    {
        month = month - 12;
        year++;
    }
    
    return month;
}

int Miles::getYear()
{
    return year;
}

int Miles::getEndYear()
{
    return endYear;
}

int Miles::getEndMonth()
{
    return endMonth;
}

int Miles::getEndDay()
{
    return endDay;
}





