//Christopher Alexman		  CSC 17A		 Chapter 11, P. 651, #02
//
/*******************************************************************************
 *
 * STORE MOVIE DATA IN A STRUCTURE MODIFICATION
 * _____________________________________________________________________________
 * This program takes all of the description for problem 01 but adds on the two
 * additional members of production cost and the first years revenue. If there
 * is profit it will specify and if there is loss it will specify as well.
 *
 * Computation is based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *
 * 	
 * OUTPUT
 *	title;              //OUTPUT - title of the movie
 *	directr;           //OUTPUT - director of the movie
 *	yearRel;            //OUTPUT - year movie was released
 *	runTime;            //OUTPUT - running time of movie
 *	prodCst;            //OUTPUT - production cost of movie
 *	revenue;            //OUTPUT - first year revenue, profit or loss
 *
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
 
using namespace std;
 
//function prototypes
void disValu(string, string, int, int, int, int);
int profLos(int, int);
 
//structure declaration
struct First
{
	string title;               //OUTPUT - title of the movie
	string directr;             //OUTPUT - director of the movie
	int yearRel;                //OUTPUT - year movie was released
	int runTime;                //OUTPUT - running time of movie
	float prodCst;              //OUTPUT - production cost of movie
	float revenue;              //OUTPUT - first year revenue
 
};
 
//structure declaration
struct Second
{
	string title;               //OUTPUT - title of the movie
	string directr;             //OUTPUT - director of the movie
	int yearRel;                //OUTPUT - year movie was released
	int runTime;                //OUTPUT - running time of movie
	int prodCst;                //OUTPUT - production cost of movie
	int revenue;                //OUTPUT - first year revenue
 
};
 
int main()
{
//variable for structure members
	First movie;
 
	movie.title = "Batman";
	movie.directr = "Tim Burton";
	movie.yearRel = 1979;
	movie.runTime = 120;
	movie.prodCst = 16000000;
	movie.revenue = 50000000;
 
//call function, send values
	disValu(movie.title, movie.directr, movie.yearRel, movie.runTime, 
                movie.prodCst, movie.revenue);
 
//variable for structure members
	Second movies;
 
	movies.title = "Alien";
	movies.directr = "Ridley Scott";
	movies.yearRel = 1979;
	movies.runTime = 125;
	movies.prodCst = 100000000;
	movies.revenue = 75000000;
 
//call function again
	disValu(movies.title, movies.directr, movies.yearRel, movies.runTime, 
                movies.prodCst, movies.revenue);
 
	return 0;
}
 
//******************************************************************************
// Definition of function disValu
// This function outputs the values of title through running time. Then it 
// calls another function to determine production profit or loss.
//******************************************************************************
void disValu(string title, string directr, int yearRel, int runTime, 
             int prodCst, int revenue)
{
	int holder;
 
	cout << left << fixed;
	cout << setw(18) << "Movie Title: " << title << endl;
	cout << setw(18) << "Director: " << directr << endl;
	cout << setw(18) << "Year Released: " << yearRel << endl;
	cout << setw(18) << "Running Time: " << runTime << endl;
 
//call function to find profit or loss
	holder = profLos(prodCst, revenue);
 
	if (holder > 0)
	{
		cout << setw(18) << "The profit is: $" << holder;
	}
	else
	{
		cout << setw(18) << "The loss is: $" << holder;
	}
	cout << endl << endl;
}
 
//******************************************************************************
//  Definition of function profLos
// This function calculates if the movie had a profit or a loss and then 
// returns the value by how much.
//******************************************************************************
int profLos(int prodCst, int revenue)
{
	int result;
 
	result = revenue - prodCst;
 
	return result;
}