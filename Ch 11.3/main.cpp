//Christopher Alexman		   CSC 17A		 Chapter 11, P. 651, #03
//
/*******************************************************************************
 *
 * CORPORATE SALES DATA
 * _____________________________________________________________________________
 * This program uses structures of data variables for the user to enter. It
 * uses 4 variables of this structure to represent a corporate division. It
 * asks for the 4 quarter sales of each division. The total and average of
 * each division is calculates and stores in a structure variable. These 
 * figures are then outputted.
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
#include <iomanip>
#include <string>
 
using namespace std;
 
int main()
{
    string east;
    string west;
    string north;
    string south;
    
    return 0;
}
struct Sales
{
    string divName;
    float firstS;
    float secondS;
    float thirdS;
    float fourthS;
    float totalS;
    float avgS;
};