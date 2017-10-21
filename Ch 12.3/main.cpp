//Christopher Alexman		  CSC 17A		 Chapter 12, P. 706, #03
//
/*******************************************************************************
 *
 * PUNCH LINE
 * _____________________________________________________________________________
 * This program reads and prints a joke from two different files. The joke file
 * has the joke by itself while the punchline file has only the punchline but
 * on the last line of a list of garbage. The first function reads in the joke
 * from the file and the second function locates the punch line and then
 * outputs it.
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
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

// Function prototypes
void joke(fstream &);
void pnchLne(fstream &);

int main()
{
//create file stream variables
    fstream jFile;
    fstream pFile;	

//open the joke text file
    jFile.open("joke.txt", ios::in);

//if it fails to open give the error message
    if (jFile.fail())
    { 
        cout << "ERROR. The file couldn't open. Try again.\n\n"; 
    }

//call function joke, send it the fstream variable
    joke(jFile);

//let user press enter before hearing the joke
    cout << "Press ENTER to get the punchline: ";
    cin.get();
        
//format joke
    cout << "\n\n";

//open the punchline text file
    pFile.open("punchline.txt", ios::in);

////if it fails to open give the error message
    if (pFile.fail())
    { 
        cout << "ERROR. The file couldn't open. Try again.\n\n"; 
    }

//call the function punchline, send it the fstream variable
    pnchLne(pFile);

//close both of the files
    jFile.close();
    pFile.close();	

    return 0;
}

void joke(fstream &file)
{
//practice another way to read a file, looping until the end using a while loop
//and file.get
    char ch;
	
    file.get(ch);
    
//loop through the file until the end 
    while (!file.eof())
    { 
        cout << ch; 
        file.get(ch); 
    }
    cout << "\n\n";
}

void pnchLne(fstream &file)
{
    char ch;
	
    file.get(ch);
    
//loop through the file until the end 
    while (!file.eof())
    { 
        cout << ch; 
        file.get(ch); 
    }
    cout << "\n\n";
}