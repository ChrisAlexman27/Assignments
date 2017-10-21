//Christopher Alexman		  CSC 17A		 Chapter 12, P. 707, #06
//
/*******************************************************************************
 *
 * STRING SEARCH
 * _____________________________________________________________________________
 * This program gets a file name from the user and a string value to search for.
 * The program searches the file for how many times that word pops up. The line
 * containing the string is displayed. The program also tells you how many times
 * the string was in the file.
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
#include <string>
using namespace std;

int main()
{
    int count = 0;		//holds the frequency of the string value	
    char fileNme[50];           //to hold the file name
    
    string search;		//the string the user is searching for
    string line;		// Holds a line read from file.

//create an input file stream called file
    ifstream file;
	
//get the file name from the user
    cout << "Enter a file name: ";
    cin >> fileNme;                    //the name of the file: lines.txt

//open the file in input mode
    file.open(fileNme, ios::in);
        
//    cin.ignore();           //to get rid of the enter key in the keyboard buffer

//display output message if the file couldnt open
    if (!file)
    {
        cout << "ERROR. File was unable to open. \n\n";
    }

//get the user input for the string to look for
    cout << "Enter a string to search for: ";
    cin  >> search;

//output a header for the results
    cout << "\nString being searched for: " << search << endl;
    cout << "The lines that contained the string are: \n\n";
    
//start at the beginning of the file, using seekg for an output file
    file.seekg(0, ios::beg);
    
//while not at end of file loop
    while (!file.fail())
    {
//gets the line just in case, store it in line
        getline(file, line);
//if the line has the string in it then output it
        if (line.find(search, 0) < line.length())
        {
            cout << line << endl;
            count++;                //for frequency of string
        }
		
    }
//output how many times the string was in the file
    cout << "\nThe string was in the file : " << count << " times." << endl;

//close the file
    file.close();
    return 0;
}
