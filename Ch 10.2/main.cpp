//Christopher Alexman		  CSC 17A		 Chapter 10, P. 594, #02
//
/*******************************************************************************
 *
 * BACKWARD STRING	
 * _____________________________________________________________________________
 * This program uses a function that accepts a pointer as a C-string as an
 * argument. The function takes that string name and flips the order, making
 * the word backwards. The string is also a user inputted one.
 *
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *		line			: the string word entered by the user
 * 	
 * OUTPUT
 *
 *
 ******************************************************************************/
#include <iostream>
using namespace std;
 
//function Prototype
void backwrd (char *);
 
int main ()
{
//create a character array of 200 characters
	char line[201];		   //INPUT - the string word entered by the user
 
	cout << "Enter a string word, I will display is backwards: \n";
	cin >> line;	
	cout << "The entered string word backward is: \n";
 
//call function, send it the string entered
	backwrd(line);
        
	cout << endl;
}
 
//******************************************************************************
// Definition of function backwrd
// This function accepts a pointer to a C-string as an argument. It uses while
// loops to flip the orientation of the string entered.
//******************************************************************************
void backwrd (char *sentPtr)        //stands for sentence pointer
{
//can point to a char, set equal to C-string
    char *ptr = sentPtr;
 
//increment pointer when the space in not equal to the null terminator character
//this is to get to the last character in the string
    while (*ptr != '\0')
    {
        ++ptr;
    }
//while the incremented pointer equals the sentence pointer
//use cout to output the string backwards, staring from the last character
    while (ptr != sentPtr)
    {
        cout << ( *--ptr );
    }
}