//Christopher Alexman                CSC 17A		 Chapter 10, P. 594, #01
//
/*******************************************************************************
 *
 * STRING LENGTH
 * _____________________________________________________________________________
 * This program asks the user to input a string. It uses a function and accepts
 * the pointer to a C-string. The function counts the number of characters in
 * the string and returns that number.
 *
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *		string			: the string entered by the user
 * 	
 * OUTPUT
 *		strCnt                  : the number of chars in string
 *
 ******************************************************************************/
#include <iostream>
using namespace std;
 
int counter(char * str);
 
int main()
{
//create a character array
	char string[100];
 
//prompt for and acquire string
	cout << "Enter string:" << endl;
	cin >> string;			//INPUT - the string entered by the user
 
//define string count variable, set equal to function call
	int strCnt;			//OUTPUT - the number of chars in string
        
//call counter function, set equal to the string count variable
	strCnt = counter(string);
 
//display results
	cout << "The number of characters in the string is: "; 
	cout << strCnt << ".\n";
 
return 0;
}
 
//******************************************************************************
// Definition of function stringCount.
// This function accepts a pointer to a C-string as an  argument. It counts the 
// number of characters in the string using a for loop, stepping through the str 
// array until it is out of characters
//******************************************************************************
int counter(char * str)
{
//define and initialize count variable for the for loop
    int count = 0;
 
//steps through array until it finds the null terminator, just returns count
//instead of making another variable
    for(count; str[count] != '\0'; count++)
    {
 
    }
    return count;
}