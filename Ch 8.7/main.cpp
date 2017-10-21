//Christopher Alexman              CSC 17A	          Chapter 8, P. 493, #07
//
/*******************************************************************************
 * SORT AND SEARCH AN ARRAY OF NAMES
 * _____________________________________________________________________________
 * This program uses a preexisting piece of code. It asks to sort the binary 
 * array of names. Then it wants us to search the array as an array of strings
 * rather than an array of int values.
 *
 * Computations are based on the formula:
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
#include <string> 
using namespace std;

//function prototypes
void srtArry(string [], int); 
int bnrySrc(string [], int, string);

int main()
{
//create constant for array
    const int NUM_NMS = 20;
    
//create and assign all string values to the array
    string names[NUM_NMS] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                             "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                             "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                             "Looney, Joe", "Wolfe, Bill", "James, Jean",
                             "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                             "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                             "Pike, Gordon", "Holland, Beth" };

//define variables
    string empName; 
    int results;  

 //call sort array function to first sort the array
    srtArry(names, NUM_NMS); 

//prompt for user input to enter an employee name 
    cout << "Please enter an employee's name: "; 
    getline(cin, empName); 

//call binary search function to see if it finds the name entered
    results = bnrySrc(names, NUM_NMS, empName);     //return value = to results

//if it returned -1 the name was not found
    if (results == -1)
        cout << "That name does not exist in the array.\n";
    else
    {
//if not -1 the result equal the location of the name in the array
        cout << "That name is found at element " << results;
        cout << " in the array.\n";
    } 

    return 0;
}

//**************************************************************
// Definition of function srtArry                              *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array.         *
//**************************************************************
void srtArry(string names[], int size)
{
//variables needed for sorting
    int startScan;
    int minIndex; 
    string minValue;

//the sorting strategy is as follows below
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

//***************************************************************
// Definition of function bnrySrc                               *
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its array subscript is returned. Otherwise, -1 is     *
// returned indicating the value was not in the array.          *
//***************************************************************
int bnrySrc(string names[], int size, string value)
{
    int first = 0,                        // First array element
        last = size - 1,                  // Last array element
        middle,                           // Mid point of search
        position = -1;                    // Position of search value
    bool found = false;                   // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;      // Calculate mid point
        if (names[middle] == value)       // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)   // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}