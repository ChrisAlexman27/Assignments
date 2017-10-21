//Christopher Alexman              CSC 17A	          Chapter 5, P. 144, #11
//
/*******************************************************************************
 * PREDICT POPULATION SIZE
 * _____________________________________________________________________________
 * This program uses various values to predict the population size of an
 * organism. It uses the starting population size, average % increase per day,
 * and the number of days to determine this. It displays the number gained
 * each day using a loop. It uses input validation so the starting size cannot
 * be less than 2, no negative numbers for the percent increase, and nothing
 * below zero for the number of days.
 * 
 *
 * Computations are based on the formulas:
 * Decimal of percent value = Percent value / 100
 * Population Increase = Starting Population Size * Decimal of percent value
 * _____________________________________________________________________________
 * INPUT
 *      strtSze;                //the initial size of the population
 *      dlyGrow;                //average daily % population increase
 *      numDays;                //the number of days they will multiply
 *      perHold;                //holds the decimal value of the percent
 *      popIncr;                //the increase in population per day
 * 	
 * OUTPUT
 *      popSize;                //the size of the population
 *
 ******************************************************************************/

#include <iostream>             //for cin and cout
#include <iomanip>              //for setw()
using namespace std;
     
int main() 
{
//define variables
    int strtSze;                //the initial size of the population
    float dlyGrow;              //average daily % population increase
    int numDays;                //the number of days they will multiply
    float perHold;              //holds the decimal value of the percent
    float popIncr;              //the increase in population per day
    int popSize;                //the size of the population
    
//acquire strtSze value
    cout << "Enter the Starting number of Organisms: ";
    cin >> strtSze;
    
//input validation, loops until correct value is inputted
    while (strtSze < 2)
    {
        cout << "\nError, starting population cannot be below 2.\n";
        cout << "Enter the Starting number of Organisms: ";
        cin >> strtSze;
    }
    
//acquire dlyGrow value
    cout << "\nEnter the average daily population increase as a percent: ";
    cin >> dlyGrow;
    
//input validation, loops until correct value is inputted
    while (dlyGrow < 0)
    {
        cout << "\nError, average daily population increase cannot be below 0.";
        cout << "\nEnter the average daily population increase as a percent: ";
        cin >> dlyGrow;
    }
    
//calculate the decimal value of the percentage given
    perHold = dlyGrow / 100;
    
//acquire numDays value
    cout << "\nEnter the number of days they will multiply: ";
    cin >> numDays;
    
//input validation, loops until correct value is inputted
    while (numDays < 1)
    {
        cout << "\nError, number of days cannot be below 1.\n";
        cout << "Enter the number of days they will multiply: ";
        cin >> numDays;
    }
    
//calculate how many organisms per day will be made based on initial population
//and the percent growth
    popIncr = strtSze * perHold;
    
//format days and population chart for output
    cout << left << fixed;
    cout << setw(9) << "\n\nDays" << "Population Size\n";
    cout << "______________________\n";
    
//use a for loop based on the number of days to display a chart of how many will
//be added to the population each day
    for (int count = 0; count < numDays; count++)
    {
        cout << setw(7) << (count + 1) << strtSze;
        strtSze += popIncr;     //adds increase value to initial population size
        cout << endl;
    }
    
//this program is only an estimate and truncates the values after the decimal
//per each iteration
    
    return 0;
}