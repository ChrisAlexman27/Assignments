//Christopher Alexman		  CSC 17A		  Chapter 9, P. 545, #04
//
/*******************************************************************************
 *
 * ALLOCATE TEST SCORES DYNAMICALLY
 * _____________________________________________________________________________
 * This program has the user enter test scores which are then passed to a 
 * function that sorts them in ascending order. Another function is used to
 * calculate the average score of the test scores. Then the program displays
 * the sorted list of scores and averages. It also has input validation, it
 * doesn't accept negative test scores.
 *
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *		scoreSize			: to hold number of scores
 * 	
 * OUTPUT
 *
 *
 ******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
 
// Function prototypes
void getData(float *, int);
void selectionSort(float *, int);
float getAverage(float *, int);
void displayData(float *, int, float);
 
int main()
{
//define variable
	int scoreSize;		//INPUT - To hold number of scores
 
	float *Test = NULL;	// To dynamically allocate an array
	float average;		// To hold the average of the scores
        
        string char[scoreSize];
 
//attain array size
	cout << "How many test scores do you want to average: ";
	cin  >> scoreSize;
 
//call functions, set some equal to holder variables
	Test = new float[scoreSize];
 
	getData(Test, scoreSize);
 
	selectionSort(Test, scoreSize);
 
	average = getAverage(Test, scoreSize);
 
	displayData(Test, scoreSize, average);
 
	return 0;
}
 
//function gets the test scores, uses input validation
void getData(float *Test, int scoreSize)
{
	cout << "\nEnter test scores: \n";
	for (int count = 0; count < scoreSize; count++)
	{
		do
		{
			cout << "Score #" << (count + 1) << ": ";
			cin  >> *(Test + count);
			cout << endl;
 
			if (*(Test + count) < 0)
			{
                            cout << "Scores must be greater than 0, try again";
                            cout << endl;
			}
 
		} while (*(Test + count) < 0);
	}
}
 
//function sorts the values
void selectionSort(float *Test, int scoreSize)
{
	int startscan;
	int minIndex;
	float minValue;
 
	for (startscan = 0; startscan < (scoreSize - 1); startscan++)
	{
		minIndex = startscan;
		minValue = *(Test + startscan);
		for (int count = startscan + 1; count < scoreSize; count++)
		{
			if (*(Test + count) < minValue)
			{
				minValue = *(Test + count);
				minIndex = count;
			}
		}
		*(Test + minIndex) = *(Test + startscan);
		*(Test + startscan) = minValue;
	}
} 
 
//function gets the average of the values
float getAverage(float *Test, int scoreSize)
{
	float total;
 
	for (int count = 0; count < scoreSize; count++)
	{
		total += *(Test + count);
	}
 
	return total / scoreSize;
} 
 
//function outputs the the results
void displayData(float *Test, int scoreSize, float avg) 
{
	cout << "Test scores\n";
	cout << "Number of scores: " << scoreSize << endl;
	cout << "Scores in ascending-order:\n";
 
	for (int count = 0; count < scoreSize; count++)
	{
		cout << "#" << (count + 1) << ": " << *(Test + count) << endl;
	}
 
	cout << fixed << showpoint << setprecision(2);
	cout << "Average score: " << avg << endl; 
}
