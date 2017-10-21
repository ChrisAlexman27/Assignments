//Christopher Alexman              CSC 17A	          Chapter 3, P. 144, #12
//
/*******************************************************************************
 * CONVERT CELSIUS TO FAHRENHEIT
 * _____________________________________________________________________________
 * This program uses a formula to convert Celsius temperatures to Fahrenheit 
 * temperatures. 
 *
 * Computations are based on the formula:
 *  Fahrenheit = (9/5) x Celsius + 32
 * _____________________________________________________________________________
 * INPUT
 *      frnheit             //the temperature in degrees Fahrenheit
 * 	
 * OUTPUT
 *      celsius             //the temperature in degrees Celsius
 *
 ******************************************************************************/

#include <iostream>         //for cout
using namespace std;
     
int main() 
{
//define variables
    float frnheit;          //the temperature in degrees Fahrenheit
    float celsius;          //the temperature in degrees Celsius
 
//acquire Celsius input value
    cout << "Enter the temperature in celcius: ";
    cin >> celsius;
 
//calculate Fahrenheit output value using the formula
    frnheit = (9.0 / 5.0 ) * celsius + 32;
 
//output results	
    cout << endl;           //format output
    cout << "The temperature in Celsius is: " << celsius << endl;
    cout << "The temperature in Fahrenheit is: " << frnheit << endl;
 
    return 0;
}
