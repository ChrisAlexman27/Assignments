//Christopher Alexman		  CSC 17A		 Chapter 13, P. 802, #01
//
/*******************************************************************************
 *
 * DATE
 * _____________________________________________________________________________
 * This function creates a class called Date that stores stores the date in the
 * three integers month, day, and year. Member function print the date in
 * multiple ways. It has the input validation in that is doesn't accept days
 * below 1 or above 31 or months less than 1 or greater than 12.
 *
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 * 
 * 	
 * OUTPUT
 * 
 *
 ******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

//Date class declaration
class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        void setMnth(int);
        void setDay(int);
        void setYear(int);
        int getMnth() const;
        int getDay() const;
        int getYear() const;
        void print1(int, int, int);
        void print2(int, int, int);
        void print3(int, int, int);
    
};

//******************************************************************************
// getMnth assigns a value to the month member                                 *
//******************************************************************************
void Date::setMnth(int m)
{
    month = m;
}

//******************************************************************************
// getMnth assigns a value to the day member                                   *
//******************************************************************************
void Date::setDay(int d)
{
    day = d;
}

//******************************************************************************
// getMnth assigns a value to the year member                                  *
//******************************************************************************
void Date::setYear(int y)
{
    year = y;
}

//******************************************************************************
// getMnth returns the value in the month member                               *
//******************************************************************************
int Date::getMnth() const
{
    return month;
}

//******************************************************************************
// getMnth returns the value in the day   member                               *
//******************************************************************************
int Date::getDay() const
{
    return day;
}

//******************************************************************************
// getMnth returns the value in the year member                                *
//******************************************************************************
int Date::getYear() const
{
    return year;
}

//******************************************************************************
// print1 prints the date in the first form.                                   *
//******************************************************************************
void Date::print1(int month, int day, int year)
{
    cout << month << "/" << day << "/" << year << endl;
}

//******************************************************************************
// print2 prints the date in the second form.                                  *
//******************************************************************************
void Date::print2(int month, int day, int year)
{
    string monName;
    
//determine which month was inputted, assign to proper name
    if(month == 1)
        monName = "January";
    else if (month == 2)
        monName = "February";
    else if (month == 3)
        monName = "March";
    else if (month == 4)
        monName = "April";
    else if (month == 5)
        monName = "May";
    else if (month == 6)
        monName = "June";
    else if (month == 7)
        monName = "July";
    else if (month == 8)
        monName = "August";
    else if (month == 9)
        monName = "September";
    else if (month == 10)
        monName = "October";
    else if (month == 11)
        monName = "November";
    else
        monName = "December";
    
    cout << monName << " " << day << ", " << year << endl;
}

//******************************************************************************
// print3 prints the date in the third form.                                   *
//******************************************************************************
void Date::print3(int month, int day, int year)
{
    string monName;
    
//determine which month was inputted, assign to proper name
    if(month == 1)
        monName = "January";
    else if (month == 2)
        monName = "February";
    else if (month == 3)
        monName = "March";
    else if (month == 4)
        monName = "April";
    else if (month == 5)
        monName = "May";
    else if (month == 6)
        monName = "June";
    else if (month == 7)
        monName = "July";
    else if (month == 8)
        monName = "August";
    else if (month == 9)
        monName = "September";
    else if (month == 10)
        monName = "October";
    else if (month == 11)
        monName = "November";
    else
        monName = "December";
    
    cout << day << " " << monName << " " << year;
}

int main()
{
//define an instance of the Date class
    Date info;
    
//create local variables for month, day, and year
    int monthh;
    int dayy;
    int yearr;
    
//get the month, day, and year from the user; use input validation
    cout << "Enter the month: ";
    cin >> monthh;
    while ((monthh < 1) || (monthh > 12))
    {
        cout << "ERROR. Enter a valid month.\n";
        cout << "Enter the month: ";
        cin >> monthh;
    }
    
    cout << "Enter the day: ";
    cin >> dayy;
    while ((dayy < 1) || (dayy > 31))
    {
        cout << "ERROR. Enter a valid day.\n";
        cout << "Enter the day: ";
        cin >> dayy;
    }
    
    cout << "Enter the year: ";
    cin >> yearr;
    
    cout << endl << endl;
    
//store the 3 values in the info object
    info.setMnth(monthh);
    info.setDay(dayy);
    info.setYear(yearr);
    
//output the dates in the 3 different ways
    info.print1(monthh, dayy, yearr);
    info.print2(monthh, dayy, yearr);
    info.print3(monthh, dayy, yearr);
    
    return 0;
}