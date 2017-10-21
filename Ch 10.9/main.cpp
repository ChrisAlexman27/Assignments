//Christopher Alexman		  CSC 17A		 Chapter 10, P. 595, #09
//
/*******************************************************************************
 *
 * MOST FREQUENT CHARACTER
 * _____________________________________________________________________________
 * This program uses a function that accepts a pointer to a C-string as its
 * argument. The function returns the character that appears most frequently in
 * the string.
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
#include <cstring>
using namespace std;
 
//function prototypes
char mostFreq(char *);
void selSort(char *);
 
int main()
{
    const int LENGTH = 101;
    char list[LENGTH]; 
 
//ask user to enter a string
    cout << "Enter a string no longer than " << (LENGTH - 1) << " characters.\n";
    cin.getline(list, LENGTH);
 
    selSort(list);
 
    cout << "The character that appears the most frequently is: ";
    cout << mostFreq(list) << endl;
 
    return 0;
}
 
//******************************************************************************
// Definition of function selectSort                                                                   
// This function performs a selection sort on the array of characters.                                                                   *
//******************************************************************************
void selSort(char * array)
{
//a normal selection sort from the textbook
	int scan, minIndex;
	char minValue;
 
	for (scan = 0; scan < (strlen(array) - 1); scan++)
	{
		minIndex = scan;
		minValue = array[scan];
		for (int index = scan + 1; index < strlen(array); index++)
		{
			if (toupper(array[index]) < toupper(minValue))
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[scan];
		array[scan] = minValue;
	}
}
 
//******************************************************************************
// Definition of function mostFreq                                              
// This function accepts a pointer to a C-string as its argument. The function  
// returns the character that appears most frequently in the string.            
//******************************************************************************
char mostFreq(char *charac)
{
    char value = charac[0], freq[1];
    int largst = 0; 
 
    for (int count = 0; count < strlen(charac); count++)
    {
        count++;            
        if (toupper(charac[count]) != toupper(charac[count + 1]))
        {
            if (count > largst)
            {
                largst = count;
                freq[0] = charac[count];
            }
        value = charac[count + 1];
        count = 0;
        }
    }
    return freq[0];
}