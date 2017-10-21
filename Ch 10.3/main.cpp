//Christopher Alexman		  CSC 17A		 Chapter 10, P. 594, #03
//
/*******************************************************************************
 *
 * AVERAGE NUMBER OF LETTERS
 * _____________________________________________________________________________
 * This function accepts a pointer to a C-string as an argument and returns the
 * number of words contained in the string. The number of words is then 
 * displayed on the screen. It is modified to display the average number of 
 * letters in each word.
 *
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *
 * 	
 * OUTPUT
 *		numWrds			: the number of words
 *
 ******************************************************************************/
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
 
//function prototype
int strSize(char*);
 
int main()
{
//the pointer to a C-string
	char* cstring = "Never tell me the odds";
 
//define variable
	int numWrds;			//OUTPUT - the number of words
 
//call function, set equal to numOfWords
	numWrds = strSize(cstring);
 
//output result
	cout << numWrds << endl;
 
	return 0;
}
 
//******************************************************************************
// Definition of function strSize
// This function accepts a pointer to a string as an argument. It uses a while
// to find spaces between words to determine how many words there are in the
// string.
//******************************************************************************
int strSize(char* cstr)
{
//define variables
    int pos;
    int strSize;
     
    string copy;
    string cpstr(cstr);
        
//initialize the size of the sting to 0
    strSize = 0;
 
//finds the empty spaces between words in order to count the number of words
    while ((pos = cpstr.find(' ')) != -1)
    {
        pos = cpstr.find(' ');
        copy.assign(cpstr,0,pos);
        cpstr.erase(0,pos+1);
        copy.erase(0,pos);
        strSize += 1;
    }
 
    int length = cpstr.size();
    char* cstring = new char[length + 1];
    strcpy(cstring,cpstr.c_str());          //copy second c-string to first
 
    if(cstring != NULL)
    {
    	strSize += 1;
    }
    return strSize;
}