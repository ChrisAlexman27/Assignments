//Christopher Alexman		  CSC 17A		 Chapter 11, P. 653, #10
//
/*******************************************************************************
 *
 * SEARCH FUNCTION FOR SPEAKERS BUREAU PROGRAM
 * _____________________________________________________________________________
 * This program keeps track of various values of a speaker's bureau. It uses 
 * array of structures to store the values. It allows the user to enter data
 * into the array, change the contents of any element and display the data
 * stored in the array. It adds a function that allows the user to search
 * for a specific topic.
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

using namespace std;

//create structures and enumerated structures
struct Data
{
    string name;                //name of the speaker
    string phoneNum;            //phone number of speaker
    string topic;               //topic of speaker
    float fee;                  //fee of speaker  
};

enum menuSel
{
    OPTION1 = 1,
    OPTION2 = 2,
    OPTION3 = 3,
    QUIT = 4,
    SEARCH = 5
};

enum dtaMode
{
    GETINFO = 1,
    CHANGE = 2
};

//function calls
int  mnuItms();
void menu(Data [], const int);
void spkrDta(Data [], int, const int);
int  spkrID(Data [], const int);
void output(const Data [], const int);
void search(Data [], const int);

int main()
{
    const int SIZE = 10;

    Data speaker[SIZE];

    menu(speaker, SIZE);

   return 0;
}

//******************************************************************************
// Definition of function
// This function displays the menu of choices and prompts the user for
// their choice of what to do. It implements input validation for values
// not on the menu.
//******************************************************************************
int mnuItms()
{
    int menuItem = 0;

    cout << "Menu\n\n";
    cout << "1. Enter Speaker Info\n";
    cout << "2. Change Speaker Info\n";
    cout << "3. Display Speaker Info\n";
    cout << "4. Quit\n\n";
    cout << "Your Choice: ";
    cin >> menuItem;

//input validation so the user's choice is within the range
    while (menuItem < OPTION1 || menuItem > QUIT)
    {
        cout << "ERROR. Try again.\n";
        cout << "Your Choice: ";
        cin >> menuItem;
    }

    return menuItem;
}

//******************************************************************************
// Definition of function menu
// This function uses the menu input from the user to determine which of the
// functions to call based on the menu.
//******************************************************************************
void menu(Data speaker[], const int SIZE)
{
    int choice = 0;
    int mode = 0;

    do
    {
        choice = mnuItms();

        switch (choice)
        {
            case OPTION1:
            {
                mode = GETINFO;
                spkrDta(speaker, mode, SIZE);
            } break;

            case OPTION2:
            {
                mode = CHANGE;
                spkrDta(speaker, mode, SIZE);
            } break;

            case OPTION3:
            {
                spkrDta(speaker, mode, SIZE);
            } break;
            
            case SEARCH:
            {
                search(speaker, SIZE);
            } break;

            case QUIT:
            {
                cout << "Goodbye.";
            } break;
        }
    } while (choice != QUIT);
}

//******************************************************************************
// Definition of function spkrID
// This function asks the user for the ID of the speaker. The ID of the speaker
// is returned to figure out the ID the user wants to change.
//******************************************************************************
int spkrID(Data speaker[], const int SIZE)
{
    int speakerID = 0;

    for (int index = 0; index < SIZE; index++)
    {
        cout << "\n\nSpeaker #" << (index + 1) << speaker[index].name << "\n";
    }

    cout << "\nEnter speaker ID: ";
    cin >> speakerID;

    cout << "\n\n";

    return speakerID - 1;
}

//******************************************************************************
// Definition of function spkrDta
// This function gets the user info for 10 speakers. The data is then stored
// in members in the arrays of structures.
//******************************************************************************
void spkrDta(Data speaker[], int mode, const int SIZE)
{
    int index = 0;
    int numSpeakers = 0;

    if (mode == CHANGE)
    {
        index = spkrID(speaker, SIZE);
        numSpeakers = 1;
    }
    else
    {
        index = 0;
        numSpeakers = SIZE;
    }

    do
    {
        cout << "\nSpeaker's Name: ";
        cin.ignore();
        getline(cin, speaker[index].name);

        while (speaker[index].name.empty())
        {
            cout << "Speaker's Name: ";
            getline(cin, speaker[index].name);
        }

        cout << "Speaker's Telephone: ";
        getline(cin, speaker[index].phoneNum);

        while (speaker[index].phoneNum.empty())
        {
            cout << "Speaker's Telephone: ";
            getline(cin, speaker[index].phoneNum);
        }

        cout << "Speaking Topic: ";
        getline(cin, speaker[index].topic);

        while (speaker[index].topic.empty())
        {
            cout << "Speaking Topic: ";
            getline(cin, speaker[index].topic);
        }

        cout << "Required Fee: ";
        cin >> speaker[index].fee;

        while (speaker[index].fee <= 0.0)
        {
            cout << "Required Fee: ";
            cin >> speaker[index].fee;
        }

        index += 1;
    } while (index < numSpeakers);
}


//******************************************************************************
// Definition of function search
// This function accepts an array of structures as an argument. It prompts the
// user for a key word and uses a for loop to search for it. It will tell
// the user if no match is found.
//******************************************************************************
void search(Data speaker[], const int SIZE)
{
    int index = 0;
    int speakerID = 0;
    string search = " ";
    bool found = false;

    cout << "\nEnter a key word to search for: ";
    cin.ignore();
    getline(cin, search);

    for (index = 0; index < SIZE; index++)
    {
        if (speaker[index].topic.find(search) != string::npos)
        {
            found = true;

            if (found)
            {
                cout << fixed << showpoint << setprecision(2);
                
                cout << "\nSpeaker's Name: " << speaker[index].name;
                
                cout << "\nSpeaker's Telephone #: " << speaker[index].phoneNum;
                
                cout << "\nSpeaking Topic: " << speaker[index].topic;
                
                cout << "\nRequired Fee: " << speaker[index].fee;
                
                cout << "\n\n";
            }
        }
    }

    if (!found)
    {
            cout << "\nThere was no match found";
            cout << endl << endl;
    }

}

//******************************************************************************
// Definition of function output
// This function outputs all of the info specified in proper format.
//******************************************************************************
void output(const Data speaker[], const int SIZE)
{
    for (int index = 0; index < SIZE; index++)
    {
        cout << fixed << showpoint << setprecision(2);
        
        cout << "\nSpeaker's Name: " << speaker[index].name;
        cout <<  "\nSpeaker's Telephone:" << speaker[index].phoneNum;
        cout << "\nSpeaking Topic: " << speaker[index].topic;
        cout << "\nRequired Fee: " << speaker[index].fee;
    }
    cout << "\n\n";
}