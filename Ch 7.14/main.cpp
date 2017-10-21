//Christopher Alexman		  CSC 17A		  Chapter 7, P. 452, #14
//
/*******************************************************************************
 * ENTER NUMBERS AND SEE IF YOU WIN, LOTTERY SIMULATION
 * _____________________________________________________________________________
 * This program prompts the user to enter 5 integer values and stores them in an
 * array called user. It has the computer generate 5 random digits, 0-9, and 
 * stores them in an array called lottery. The two arrays are compared, the 
 * program keeps track of how many numbers match. It then displays the two 
 * strands of numbers. If they match it will display 'grand prize winner'.
 * 
 * Calculations are based on the following formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *
 * 	
 * OUTPUT
 *      matchValue          //the number of matches between the arrays
 *
 ******************************************************************************/
#include <iostream>     //for cin and cout
#include <cstdlib>      //for rand and srant
#include <ctime>        //for timing
using namespace std;
 
//declare constants
const int lotteryDigits = 10;
const int SIZE = 5;
 
//function prototypes
int grtLtry(int[], int, int);       //generates random lottery numbers
int usrInpt(int[], int);            //gets users lottery numbers
int mchCntr(int[], int[], int);     //compares the two and checks for matches
 
int main()
{
//create the arrays and initialize them
	int lottery[5] = {0, 0, 0, 0, 0};
	int user[5] = {0, 0, 0, 0, 0};
 
//initialize then define variable
	int matchValue = 0;  //OUTPUT - the number of matches between the arrays
 
//calls functions
	grtLtry(lottery, SIZE, lotteryDigits);
 
	usrInpt(user, SIZE);
 
	matchValue = mchCntr(lottery, user, matchValue);
 
//output the random winning lottery numbers
	cout << "\nThe winning lottery numbers are: " << lottery[0] << " ";
	cout << lottery[1] << " " << lottery[2] << " " << lottery[3] << " ";
	cout << lottery[4] << endl;
	cout << "Your lottery numbers are: "<< user[0] << " " << user[1] << " ";
	cout << user[2] << " " << user[3] << " " << user[4] << endl;
 
//output how many the user guessed right
	cout << "You matched " << matchValue << " numbers";
 
//if else statement used if they got all 5 right
	if (matchValue != SIZE)
		cout << "\nSorry, you have lost.\n";
	else
		cout << "\nGRAND PRIZE WINNER!!!\n";
 
	return 0;
}
 
//******************************************************************************
// Definition of function grtLtry
// This function generates random lottery numbers using the random number
// generator. It then uses a for loop to place those random numbers into an
// array. It returns all 5 values created.
//******************************************************************************
int grtLtry(int lottery[], int, int)
{
	unsigned seed = time(0);
	srand(seed);
 
//used to create 5 random numbers
	for (int count = 0; count < SIZE; count++)
	{
		lottery[count] = rand() % lotteryDigits;    //creates random num
	}
//return the 5 random values created
	return lottery[0], lottery[1], lottery[2], lottery[3], lottery[4];
}
 
//******************************************************************************
// Definition of function usrInpt
// This function asks the user to enter 5 random digits 0-9. It uses a for loop
// to ask 5 times and store those values into an array.
//******************************************************************************
int usrInpt(int user[], int)
{	
	cout << "This program will simulate a lottery.\n\n";
 
//steps through for loop to have user input 5 random numbers
	for (int count = 0; count < SIZE; count++)
	{
		cout << "Enter a digit between 0 and 9: ";
		cin >> user[count];     //adds it to array
                cout << endl;
 
//uses input validation if user enters something outside of bounds
		while (user[count] < 0 || user[count] > 9)
		{
		cout << "Error! Entry must be between 0 and 9: \n";
		cin >> user[count];
		}
	}
 //returns the 5 random user inputted values
	return user[0], user[1], user[2], user[3], user[4];
}
 
//******************************************************************************
// Definition of function mchCntr
// This function compares the two arrays of the random values. If two elements
// are the same a match incrementer is used to count the number of matches.
//******************************************************************************
int mchCntr(int lotto[], int input[], int)
{
//temp variable created, counts the number of matches
	int match = 0;
 
//compares the elements of both arrays to each other one by one
	for (int count = 0; count < SIZE; ++count)
	{
		if (lotto[count] == input[count])
			match += 1;         //adds 1 to itself if match is found
	}
 
	return match;
}