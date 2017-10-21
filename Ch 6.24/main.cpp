//Christopher Alexman                CSC 17A		  Chapter 6, P. 373, #24
//
/*******************************************************************************
 *
 * PLAY ROCK, PAPER, SCISSORS VS THE COMPUTER
 * _____________________________________________________________________________
 * 	This program simulates the game of rock, paper, scissors. A random 
 * number between 1 and 3 is generated. 1, 2, 3 is rock, paper, scissors
 * respectively. It takes the players input of their choice and compares it to
 * the generated choice of the computer. Depending on the pairing it will
 * display either rock smashes scissors, scissors cuts paper, or paper wraps 
 * rock. It will tell the user if the game is a tie.
 *
 * Calculations are based on the formula:
 * 
 * _____________________________________________________________________________
 * INPUT
 *	userChoice;		//users choice of rock, paper, or scissors
 * 	
 * OUTPUT
 *
 ******************************************************************************/
#include <iostream>         //for cin and cout
#include <cstdlib>          //for rand and srand
#include <ctime>            //for the time function
using namespace std;

//function prototypes
void computerChoiceFunction(int);
void userChoiceFunction(int);
void winnerFunction(int, int);
 
int main() 
{
//define variables
	int computerChoice;   //CALC - randomly generated value 1-3
	int userChoice;       //INPUT - users choice of rock, paper, or scissors
 
//the random number generator creates a number 1-3
	unsigned seed = time(0);            //get the system time
	srand(seed);                        //seed the random number generator
	computerChoice = rand() % 3 + 1;    //create the random values
 
//prompt user to choose rock, paper, or scissors by picking 1, 2, or 3
	cout << "User, enter\n 1. For Rock\n 2. For Paper\n "
                "3. For Scissors\n Enter your choice: \n\n";
	cin >> userChoice;
 
//calling the functions
	userChoiceFunction(userChoice);
 
	computerChoiceFunction(computerChoice);
 
	winnerFunction(userChoice, computerChoice);
 
	return 0;
}
 
//***************************************************************************
// Definition of function userChoiceFunction.
// This function determines which of the user
// choices equate to either rock, paper, or
// scissors based on their input of 1, 2, or 3.
// It outputs the value they chose in text.
//***************************************************************************
 
void userChoiceFunction(int userChoice)
{
	if (userChoice == 1)
		cout << "The user chose Rock.\n";
	else if (userChoice == 2)
		cout << "The user chose Paper.\n";
	else if (userChoice == 3)
		cout << "The user chose Scissors.\n";
}
 
//***************************************************************************
// Definition of function computerChoiceFunction
// This function determines which of the randomly
// generated computer number
// choices equate to either rock, paper, or
// scissors based on 1, 2, or 3.
// It outputs the value they chose in text.
//***************************************************************************
 
void computerChoiceFunction(int computerChoice)
{
	if (computerChoice == 1)
		cout << "The computer chose Rock.\n";
	else if (computerChoice == 2)
		cout << "The computer chose Paper.\n";
	else if (computerChoice == 3)
		cout << "The computer chose Scissors.\n";
}
 
//***************************************************************************
// Definition of function winnerFunction
// This function checks which pairs resulted from
// the pairings. If tied it will notify the user. For the 
// other 3 possibilities of pairs it will notify the user
// whether rock, paper, or scissors won.
//***************************************************************************
 
void winnerFunction(int userChoice, int computerChoice)
{
//uses combinations of comparative statements to determine the outcome
	if (((userChoice == 1) && (computerChoice == 3)) || 
            ((userChoice == 3) && (computerChoice == 1)))
		cout << "The rock smashes the scissors.\n";
	else if (((userChoice == 3) && (computerChoice == 2)) || 
                 ((userChoice == 2) && (computerChoice == 3)))
		cout << "Scissors cuts paper.\n";
	else if (((userChoice == 2) && (computerChoice == 1)) || 
                 ((userChoice == 1) && (computerChoice == 2)))
		cout << "Paper wraps rock.\n";
	else
		cout << "Its a tie!\n";
}

