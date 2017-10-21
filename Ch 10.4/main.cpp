//Christopher Alexman		  CSC 17A		 Chapter 10, P. 594, #04
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
 *		numOfWords			: the number of words
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
	int numOfWords;			//OUTPUT - the number of words
 
//call function, set equal to numOfWords
	numOfWords = strSize(cstring);
 
//output result
	cout << numOfWords << endl;
 
	return 0;
}
 
//******************************************************************************
// Definition of function stringSize
// This function accepts a pointer to a string as an argument. It uses a while
// to find spaces between words to determine how many words there are in the
// string.
//******************************************************************************
int strSize(char* cstr)
{
	int pos,sizeofstr;
	sizeofstr = 0;
	string copy;
	string cplusstr(cstr);
 
	while ((pos = cplusstr.find(' ')) != -1)
	{
		pos = cplusstr.find(' ');
		copy.assign(cplusstr,0,pos);
		cplusstr.erase(0,pos+1);
		copy.erase(0,pos);
		sizeofstr = sizeofstr + 1;
	}
 
	int length = cplusstr.size();
	char* cstring = new char[length + 1];
	strcpy(cstring,cplusstr.c_str());
 
	if(cstring != NULL)
	{
		sizeofstr = sizeofstr + 1;
	}
	return sizeofstr;
}