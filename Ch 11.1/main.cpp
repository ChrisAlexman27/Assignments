//Christopher Alexman		   CSC 17A		 Chapter 11, P. 651, #01
//
/*******************************************************************************
 *
 * STORE MOVIE DATA IN A STRUCTURE
 * _____________________________________________________________________________
 * This program uses a structure named MovieData to store the title, director,
 * year released, and running time. It created two MovieData variables and 
 * stores values in their members. Display values in a clear and formatted
 * matter.
 * 
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *
 * 	
 * OUTPUT
 *	title            //title of the movie
 *	director         //director of the movie
 *	yearRel          //year movie was released
 *	runTime          //running time of the movie
 *
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
 
using namespace std;
 
//function prototype
void display(string, string, int, int);
 
//structure declaration for first structure
struct First
{
	string title;			//OUTPUT - title of the movie
	string directr;                 //OUTPUT - director of the movie
	int yearRel;                    //OUTPUT - year movie was released
	int runTime;                    //OUTPUT - running time of the movie
};
 
//structure declaration for second movie
struct Second
{
	string title;			//OUTPUT - title of the movie
	string directr;                 //OUTPUT - director of the movie
	int yearRel;                    //OUTPUT - year movie was released
	int runTime;                    //OUTPUT - running time of the movie
};
 
int main()
{
//create variable for structure function
	First movie;
 
	movie.title = "Batman";
	movie.directr = "Tim Burton";
	movie.yearRel = 1979;
	movie.runTime = 120;
 
//call function
	display(movie.title, movie.directr, movie.yearRel, movie.runTime);
 
//create variable for structure function
	Second movies;
 
	movies.title = "Alien";
	movies.directr = "Ridley Scott";
	movies.yearRel = 1979;
	movies.runTime = 125;
 
//call function again
	display(movies.title, movies.directr, movies.yearRel, movies.runTime);
 
	return 0;
}
 
//******************************************************************************
// Definition of function display
// This function accepts the various values stored in the structures. It
// displays them in a nice format.
//******************************************************************************
void display(string title, string directr, int yearRel, 
                   int runTime)
{
//output the data in the proper format
	cout << left << fixed;
	cout << setw(18) << "Movie Title: " << title << endl;
	cout << setw(18) << "Director: " << directr << endl;
	cout << setw(18) << "Year Released: " << yearRel << endl;
	cout << setw(18) << "Running Time: " << runTime << endl << endl;;
}
