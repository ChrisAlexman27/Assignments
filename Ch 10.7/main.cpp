//Christopher Alexman		  CSC 17A		 Chapter 10, P. 595, #07
//
/*******************************************************************************
 *
 * NAME ARRANGER
 * _____________________________________________________________________________
 * This program prompts the user for their first, middle, and last name. Then it
 * stores those values in 3 separate arrays. It uses a fourth array to format
 * the 3 names in order of last, first middle. It displays the value on screen.
 *
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *		firName			: first name of user
 * 		midName			: middle name of user
 * 		lstName			: last name of user
 * 	
 * OUTPUT
 *
 *
 ******************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

//function prototype
void nameArr(char *, char *, char *, const int);
 
int main()
{
    const int SIZE = 25;
    
//define arrays
    char firName[SIZE];
    char midName[SIZE];
    char lstName[SIZE];
 
//get name input
    cout << "Enter your first name: ";
    cin >> firName;
    cout << endl;
 
//used in formatting the output
    int fLength = strlen(firName);
 
    firName[fLength] = ' ';
    firName[fLength + 1] = '\0';
 
    cout << "Enter your middle name: ";
    cin >> midName;
    cout << endl;
 
    cout << "Enter your last name: ";
    cin >> lstName;
    cout << endl;
 
//used in formatting the output
    int lastLen = strlen(lstName);
 
    lstName[lastLen] = 44;
    lstName[lastLen + 1] = ' ';
    lstName[lastLen + 2] = '\0';
 
 //call function
    nameArr(firName, midName, lstName, SIZE);
}
 
//******************************************************************************
// Definition of function nameArranger
// This function gets the 3 arrays the names are stored in, it accepts them as
// pointers. It uses for loops to arrange the names to format.
//******************************************************************************
void nameArr(char *first, char *middle, char *last, const int SIZE)
{
//create a character array with 3x the size
    char fullNme[SIZE * 3];
 
//set length to the sum of the lengths of the strings
    int length = (strlen(first) + strlen(middle) + strlen(last));
 
//append the second string to the first string
    strcat(first, middle);
 

    for(int count = 0; count < length; count++)
    {
//store the last name into the fullName array, until it reaches a null character
        fullNme[count] = last[count];
        if(last[count] == '\0')
//move to the start of the name array which was the second string already
//stored inside it, store that into the fullNme array
        do{
            fullNme[count] = first[count - (strlen(last))];
            count++;
 
        } while(count < length);
    }
    
//output the fullNme array
    for(int count = 0; count < length; count++)
    {
        cout << fullNme[count];
    }
}