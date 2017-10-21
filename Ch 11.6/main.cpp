//Christopher Alexman                 CSC 17A		 Chapter 11, P. 652, #06
//
/*******************************************************************************
 *
 * STORE SOCCER DATA INTO A STRUCTURE
 * _____________________________________________________________________________
 * This program stores various soccer related data into a structure. The 
 * program keeps an array of 12 of these structures. Each element is for a 
 * different player. Then it displays all of the values is a table. It also
 * calculates and displays the total points earned by each team.
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
#include <iomanip>
#include <string>

using namespace std;

struct Player
{
    string plyrNme;             //name of player
    int    plyrNum;             //the number of the player
    int    ptsScrd;             //how many points the player scored
};

struct Results
{
    string topPlyr;             //name of top player
    int    highScr;             //highest score, from top player
    int    totlPts;             //total points scored by entire team
    int    topNum;              //the number of the top player
};

void plyrDta(Player [], const int);
void findTop(Player [], Results &, const int);
void fndTotl(Player [], Results &, const int);
void output(const Player [], const Results &, const int);

int main()
{
    const int NUM_PLAYERS = 12;

//create an array of structures
    Player plyr[NUM_PLAYERS];

//structure for all the calculated results, initialize
    Results players = { "\0", 0, 0, 0 };

//call functions one by one
    plyrDta(plyr, NUM_PLAYERS);
    findTop(plyr, players, NUM_PLAYERS);
    fndTotl(plyr, players, NUM_PLAYERS);
    output(plyr, players, NUM_PLAYERS);

   return 0;
}

//******************************************************************************
// Definition of function plyrDta
// This function gets the players name, number, and point values.
// It uses getline to do this for the name and just cin for the other two.
// It uses input validation to make sure there are no negative values
//******************************************************************************
void plyrDta(Player pData[], const int NUM_PLAYERS)
{
    for (int index = 0; index < NUM_PLAYERS; index++)
    {
        cout << "Enter name of Player # " << (index + 1) << ": ";
        getline(cin, pData[index].plyrNme);

        cout << "Enter " << pData[index].plyrNme << "'s number: ";
        cin >> pData[index].plyrNum;
        
//input validation, wont accept values below 0
        while (pData[index].plyrNum < 0)
        {
            cout << "ERROR. Enter a positive value.\n";
            cout << "Enter " << pData[index].plyrNme << "'s number: ";
            cin >> pData[index].plyrNum;
        }

        cout << "Enter " << pData[index].plyrNme << "'s points scored: ";
        cin >> pData[index].ptsScrd;
        
//input validation, wont accept values below 0
        while (pData[index].ptsScrd < 0)
        {
            cout << "ERROR. Enter a positive value.\n";
            cout << "Enter " << pData[index].plyrNme << "'s points scored: ";
            cin >> pData[index].ptsScrd;
        }
        cout << endl;
        cin.ignore();
    }
}

//******************************************************************************
// Definition of function findTop
// This function uses a for loop to determine which score is the highest score
//******************************************************************************
void findTop(Player pData[], Results &players, const int NUM_PLAYERS)
{
//set the highscore member equal to element 0 in the points scored array
    players.highScr = pData[0].ptsScrd;

//step through the values, compare values until the biggest is found
    for (int index = 0; index < NUM_PLAYERS; index++)
    {
        if (pData[index].ptsScrd >= players.highScr)
        {
            players.highScr   = pData[index].ptsScrd;
            players.topPlyr   = pData[index].plyrNme;
            players.topNum = pData[index].plyrNum;
        }
    }
}

//******************************************************************************
// Definition of function fndTotl
// This function uses a for loop and the += operator to add together all of the
// scores from the players.
//******************************************************************************
void fndTotl(Player pData[], Results &players, const int NUM_PLAYERS)
{
//step through the array to sum up all the scores
    for (int index = 0; index < NUM_PLAYERS; index++)
    {
        players.totlPts += pData[index].ptsScrd;
    }
}

//******************************************************************************
// Definition of function output
// This function uses setw and cout to format the output to look nice
//******************************************************************************
void output(const Player pData[], const Results &players, const int NUM_PLAYERS)
{
    cout << setw(17) << left  << "PLAYER NAME"; 
    cout << setw(13) << right << "PLAYER NUMBER";
    cout << setw(16) << right << "PLAYER SCORE" << "\n";
   
    cout << "------------------------------------------------------------\n";
   
    for (int index = 0; index < NUM_PLAYERS; index++)
    {
        cout << setw(17) << left  << pData[index].plyrNme; 
        cout << setw(13) << right << pData[index].plyrNum;
        cout << setw(12) << right << pData[index].ptsScrd;
        cout << endl;
    }
    
    cout << "------------------------------------------------------------\n";

    cout << "Overall Team Score: " << players.totlPts;

    cout << "\n\nTOP PLAYER\n";

    cout << "------------------------------------------------------------\n";

    cout << "\nTop player name: " << players.topPlyr;
    cout << "\nTop player number: " << players.topNum;
    cout << "\nTop player score: " << players.highScr;     
}
