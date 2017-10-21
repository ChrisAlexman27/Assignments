//Christopher Alexman		  CSC 17A		 Chapter 12, P. 707, #07
//
/*******************************************************************************
 *
 * SENTENCE FILTER
 * _____________________________________________________________________________
 * This program gets two file names from the user. The first is for input and
 * the second is for output. The first one contains a sentence with a period.
 * The program will read the first file and change all of the letters to 
 * lowercase except the first letter of the sentence. The program should
 * write the updated line to the second file.
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
#include <cctype>
using namespace std;

int main()
{
//create arrays for the files and a string for the line
    char old[50];
    char neww[50];
    string line;
    
//additional variables for the for and if statements below
    char ch;
    int hold;
    int holder;

//get names of files from the user
    cout << "Name of input file: ";
    cin  >> old;                                         //old.txt
    cout << "Name of output file: ";
    cin  >> neww;                                        //new.txt
    
    cout << endl << endl;

//open the file for input in input mode
    fstream inFile(old, ios::in);
        
//give error message for if the file cant open
    if (!inFile)
    {
        cout << "ERROR. Unable to open input file. Try again.\n\n";
        return 0;
    }
    
//open the output file in output mode
    fstream outFile(neww, ios::out);

//
    inFile.clear();
    inFile.seekg(0, ios::beg);
    outFile.seekp(0, ios::beg);
    hold = inFile.tellg();

//loops until end of file
//uses conditionals to determine if the letter is upper/lower/not a letter
//applies the proper change to the letter
    while (!inFile.eof())
    {
        holder = inFile.tellg();
        getline(inFile, line);
        
        for (int count = 0; count < line.length(); count++)
        {
            if(hold == holder)
            {
                if (isalpha(line[0]))               //if its a letter
                {
                    line[0] = toupper(line[0]);
                }
                if (isspace(line[0]))               //if its a space
                {
                    line[1] = toupper(line[1]);
                }
            }
            else if (line[count] == '.')            //if its a period
            {
                if (isalpha(line[count]))
                {
                    line[count] = toupper(line[count]);
                }

            if (isspace(line[count + 1]))
            {
                line[count + 2] = toupper(line[count + 2]);
                count += 2;
            }
        }
        else
            line[count] = tolower(line[count]);    //make letter lower otherwise
        }
        outFile << line;
        cout << line;               //output to console to check
    }

//close the files
    inFile.close();
    outFile.close();
    
    return 0;
}