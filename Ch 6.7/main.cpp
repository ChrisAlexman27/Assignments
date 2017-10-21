//Christopher Alexman              CSC 17A	          Chapter 6, P. 368, #07
//
/*******************************************************************************
 * DISPLAY CELSIUS VALUES USING FUNCTIONS
 * _____________________________________________________________________________
 * This program uses a function named 'celsius' that accepts a Fahrenheit 
 * value as an argument, converts it to Celsius, and returns the Celsius value.
 * It uses a loop to call the function and displays the Fahrenheit values
 * 0 through 20 in a table converted to Celsius.
 *  
 *
 * Computations are based on the formula:
 *  Celsius = (5/9)(Fahrenheit - 32)
 * _____________________________________________________________________________
 * INPUT
 *      frnheit             //the temperature in degrees Fahrenheit
 * 	
 * OUTPUT
 *      clsius             //the temperature in degrees Celsius
 *
 ******************************************************************************/

#include <iostream>         //for cin and cout
#include <iomanip>          //for setw()
using namespace std;
     
//function prototype
float celsius(float);

int main() 
{
//define variables
    float frnheit;          //the temperature in degrees Fahrenheit
    float clsius;           //the temperature in degrees Celsius
    
//initialize fahrenheit to starting value
    frnheit = 0;
 
//format the data table 
    cout << "Temp (F)" << "\t" << "Temp (C)";
    cout << "\n_______________________";
 
//use a for loop to output results and call the function
    for(int count = 0; count < 21; count++)
    {
//set precision to 2 places after the decimal, always shown
        cout << setprecision(2) << fixed << showpoint;
        cout << endl;
        cout << frnheit;
        
//call function to calculate celsius value
        clsius = celsius(frnheit);      //the value returned is = to clsius
        cout << "\t\t" << clsius;       //display result
        
//increment frnheit to get temperatures 0 through 20
        frnheit++;
    }

    return 0;
}

//******************************************************************************
//Definition of function celsius                                               *
// This function accepts the fahrenheit values 0 through 20 as arguments,      *
// converts them to celsius values using a formula, and then returns the       *
// celsius values to function main.                                            *
//******************************************************************************

float celsius(float frnheit)
{
//create temporary variable to hold celsius result and return it
    float clsius;
    
//calculate celsius value from fehrenheit input
    clsius = (frnheit - 32) * 5 / 9;
    
    return clsius;
}