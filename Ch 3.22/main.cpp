//Christopher Alexman		    CSC17A  		  Chapter 3, P. 146, #22
//
/*******************************************************************************
* CALCULATE SIN, COS, TAN FROM RADIAN VALUE
*_______________________________________________________________________________
* This program calculates the sin, cos, and tan values after being given the 
* value of an angle in radians. 
*
* The formulas are:
* y = sin(x)
* y = cos(x)
* y = tan(x)
*_______________________________________________________________________________
* INPUT
*	rdnValu                     //the angel value in radians
*
* OUTPUT
*	sinValu                     //the sin of the angle
*	cosValu                     //the cos of the angle
*	tanValu                     //the tan of the angle
*******************************************************************************/
#include <iostream>                 //for cin and cout
#include <iomanip>                  //for setprecision
#include <cmath>                    //for sin,cos,tan
using namespace std;
 
int main() {
 
//define variables
    float rdnValu;                  //the angel value in radians
    float sinValu;                  //the sin of the angle
    float cosValu;                  //the cos of the angle
    float tanValu;                  //the tan of the angle
 
//acquire radian value
    cout << "Enter your angle value, in radians: ";
    cin >> rdnValu;
 
//calculate sin, cos, tan
    sinValu = sin(rdnValu);
    cosValu = cos(rdnValu);
    tanValu = tan(rdnValu);
 
//set precision after decimal to 4 places
    cout << setprecision(4) << fixed << endl;
 
//output values in nice format
    cout << "The sin value is: " << sinValu << endl;
    cout << "The cos value is: " << cosValu << endl;
    cout << "The tan value is: " << tanValu << endl;
 
    return 0;
}
