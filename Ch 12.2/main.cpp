//Christopher Alexman		  CSC 17A		 Chapter 12, P. 706, #02
//
/*******************************************************************************
 *
 * FILE DISPLAY PROGRAM
 * _____________________________________________________________________________
 * This program asks for the name of a file. It displays the contents of the
 * file on screen it should display them 24 at a time with a pause for the user
 * to press the enter key between each set of 44.
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
using namespace std;
int main()
{
//create two character arrays for the file name and the lines in the file
    const int SIZE = 100;
    char fileNme[SIZE];
    char line[SIZE];
    
//create an input file stream called file
    ifstream file;
	
//get the file name from the user
    cout << "Enter a file name: ";
    cin >> fileNme;                    //the name of the file: lines.txt

//open the file in input mode
    file.open(fileNme, ios::in);
        
    cin.ignore();           //to get rid of the enter key in the keyboard buffer
	
//loops while it is not at the end of the file
    for(int count = 1; !file.eof(); count++)
    {
//get one line at a time, output it
        file.getline(line, SIZE);
        cout << line << endl;
        
//if the 24th line is reached it pauses and waits for the user to hit enter
        if (count % 24 == 0) 
        {
            cout << "Press any key to continue." << endl;
            getchar();          //waits for the enter key
        }	
    }
	
//close the file
    file.close();
    return 0;
}