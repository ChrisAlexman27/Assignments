//Christopher Alexman		  CSC 17A		 Chapter 12, P. 705, #01
//
/*******************************************************************************
 *
 * FILE HEAD PROGRAM
 * _____________________________________________________________________________
 * This program gets a file name from the user and opens that file. It displays
 * the first 10 lines onto the screen. There is also a message displayed if
 * the amount of lines is under 10 that the entire file has been displayed.
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
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream file;          // input stream file called file
    char word[250];         //create a character array
	
//open the file
    file.open("TenLines.txt");

//if the file didnt open display error message
    if (!file.is_open())
    {
    	cout << "There has been a problem opening the file. Try again.";
    }


    int count = 0;
    
//while loop for 0-9 and while it is not at the end of the file
    while (count < 10 && !file.eof())
    {
//get the line from the file, increment count, cout the line
        file.getline(word, 250);
        count++;
        cout << word << endl;
    }
	
//if there weren't at least 10 lines to read it will display the message
    if (count < 10) // if fewer than 10 lines
    {
        cout << "\nThe entire file was read.\n";
    }
	
    return 0;
	
}