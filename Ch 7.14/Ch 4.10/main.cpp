//Christopher Alexman                 CSC 17A	          Chapter 4, P. 221, #10
//
/*******************************************************************************
* OUTPUT NUMBER OF DAYS IN A MONTH
* 
*_______________________________________________________________________________
* This program asks the user to enter the month and year it is. It then displays
* the number of days in the month. It uses conditionals of the year to determine
* if it is a leap year or not and makes a change accordingly.
*
* Computations are based on the formulas: 
*
*_______________________________________________________________________________
* INPUT
*       month;              //the user inputted month
*       year;               //the user inputted year
*
* OUTPUT
*	days;               //the number of days in the month
*	
*******************************************************************************/
#include <iostream>         //for cin and cout

using namespace std;
 
int main() 
{
//define variables
    int month;              //the user inputted month
    int year;               //the user inputted year
    int days;               //the number of days in the month
    
//acquire the month value
    cout << "Enter a month (1-12): ";
    cin >> month;
    
//check if input value is outside of the parameters
    if ((month < 1) || (month > 12))
    {
        cout << "\nThat value is outside of the parameters. \n";
        cout << "Enter a month (1-12): ";
        cin >> month;
    }
    
//acquire the year value
    cout << "Enter a year : ";
    cin >> year;
    
//determine if year is a leap year,
    if ((year % 100 == 0) && (year % 400 == 0))
    {
        days = 29;
    }
    else if ((year % 100 != 0) && (year % 4))
    {
        days = 29;
    }
    
//conditional if used to not enter switch loop if leap year found
//switch statement used to determine day amount based on month
    if (days != 29)
    {
        switch(month)
        {
            case 1: days = 31;
                    break;
            case 2: days = 28;
                    break;
            case 3: days = 31;
                    break;
            case 4: days = 30;
                    break;
            case 5: days = 31;
                    break;
            case 6: days = 30;
                    break;
            case 7: days = 31;
                    break;
            case 8: days = 31;
                    break;
            case 9: days = 30;
                    break;
            case 10: days = 31;
                    break;
            case 11: days = 30;
                    break;
            case 12: days = 31;
                    break;
        }
    }
    
//output the amount of days in the month
    cout << days << " days";
           
    return 0;
}