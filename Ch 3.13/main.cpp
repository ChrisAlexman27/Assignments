//Christopher Alexman                 CSC 17A	          Chapter 3, P. 144, #13
//
/*******************************************************************************
* CALCULATE EXCHANGE RATE FOR U.S. DOLLAR TO YEN AND EURO CURRENCY
*_______________________________________________________________________________
* This program takes U.S. dollar amounts and converts them to Yen and Euro 
* amounts given an exchange rate constants. It formats the results to 2 decimal 
* places and always shows the decimal.
*
* Computations are based on the formulas: 
* Exchanged Yen = U.S. Dollar Amount x Yen exchange rate
* Exchanged Euros = U.S. Dollar Amount x Euro exchange rate
*_______________________________________________________________________________
* INPUT
*       YEN_RTE 		//exchange constant for yen
*	EUR_RTE                 //exchange number for euros
*	dlrAmnt                 //amount of US money to be exchanged
*
* OUTPUT
*	exchYen                 //amount of yen after exchange
*	excEuro                 //amount of euros after exchange
*******************************************************************************/

#include <iostream>            //for cin and cout
#include <iomanip>             //for setprecision
using namespace std;
 
int main() 
{
 
//define variables
    float dlrAmnt;              //amount of US money to be exchanged
    float exchYen;              //amount of yen after exchange
    float excEuro;              //amount of euros after exchange
 
//define and initialize constants
    float const YEN_RAT = 98.93;    //exchange constant for yen
    float const EUR_RTE = 0.74;     //exchange number for euros
 
//create 2 numbers after decimal place, always show decimal
    cout << setprecision(2) << fixed << showpoint;
 
//acquire US dollar amount
    cout << "How much money do you have in U.S. currency: ";
    cin >> dlrAmnt;
    cout << endl;           //formatting for output
 
//calculate yen after exchange using formula
    exchYen = dlrAmnt * YEN_RAT;
 
//output result
    cout << exchYen << " in Yen currency.\n";
 
//calculate euro after exchange using formula
    excEuro = dlrAmnt * EUR_RTE;
 
//output result
    cout << excEuro << " in Euro currency.\n";
 
    return 0;
}