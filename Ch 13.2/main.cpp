//Christopher Alexman		  CSC 17A		 Chapter 13, P. 802, #02
//
/*******************************************************************************
 *
 * EMPLOYEE CLASS
 * _____________________________________________________________________________
 * This function creates a class called Employe that has specific member 
 * variables of name, id number, department, and position. It also uses
 * constructors to accept values as arguments and assign them to their 
 * appropriate member variables. Have mutator functions, accessor functions,
 * and create 3 objects to store specific employee data.
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
#include <string>
using namespace std;

//Employe class declaration
class Employe
{
    private:
        string name;
        int idNumbr;
        string dept;
        string pos;
    public:
        Employe();                                  //constructor
        Employe(string, int);                       //constructor
        Employe(string, int, string, string);       //constructor
        void setName(string);
        void setNumb(int);
        void setDept(string);
        void setPos(string);
        
        string getName()
            { return name; }
        
        int getNumb()
            { return idNumbr; }
        
        string getDept()
            { return dept; }
        
        string getPos()
            { return pos; }
};

//******************************************************************************
// The constructor initializes all of the values to 0
//******************************************************************************
Employe::Employe()
{
    name = "";
    idNumbr = 0;
    dept = "";
    pos = "";
}

//******************************************************************************
// The constructor initializes the name and idNumber, the others to blank
//******************************************************************************
Employe::Employe(string n, int i)
{
    name = n;
    idNumbr = i;
    dept = " ";
    pos = " ";
}

//******************************************************************************
// The constructor initializes the 4 variables to their member values
//******************************************************************************
Employe::Employe(string n, int i, string d, string p)
{
    name = n;
    idNumbr = i;
    dept = d;
    pos = p;
}

//******************************************************************************
// setNum assigns a value to the itemNum member                                *
//******************************************************************************
void Employe::setName(string na)
{
    name = na;
}

//******************************************************************************
// setQuan assigns a value to the qntity member                                *
//******************************************************************************
void Employe::setNumb(int nu)
{
    idNumbr = nu;
}

//******************************************************************************
// setCost assigns a value to the cost member                                  *
//******************************************************************************
void Employe::setDept(string d)
{
    dept = d;
}

//******************************************************************************
// setTotl assigns a value to the ttlCost member                               *
//******************************************************************************
void Employe::setPos(string p)
{
    pos = p;
}

int main()
{
//create 3 instances of the Employe class
    Employe person1;
    Employe person2;
    Employe person3;
    
//create temporary local variables
    string namee;
    int num;
    string deptt;
    string poss;
    
//get user input
    cout << "PERSON #1\n";
    cout << "Name: ";
    getline(cin, namee);
    cout << "ID Number: ";
    cin >> num;
    cin.ignore();
    cout << "Department: ";
    getline(cin, deptt);
    cout << "Position: ";
    getline(cin, poss);
    cout << endl;
    
//store the values in the person1 object
    person1.setName(namee);
    person1.setNumb(num);
    person1.setDept(deptt);
    person1.setPos(poss);
    
    
//get user input
    cout << "PERSON #2\n";
    cout << "Name: ";
    getline(cin, namee);
    cout << "ID Number: ";
    cin >> num;
    cin.ignore();
    cout << "Department: ";
    getline(cin, deptt);
    cout << "Position: ";
    getline(cin, poss);
    cout << endl;
    
//store the values in the person1 object
    person2.setName(namee);
    person2.setNumb(num);
    person2.setDept(deptt);
    person2.setPos(poss);
    
//get user input
    cout << "PERSON #3\n";
    cout << "Name: ";
    getline(cin, namee);
    cout << "ID Number: ";
    cin >> num;
    cin.ignore();
    cout << "Department: ";
    getline(cin, deptt);
    cout << "Position: ";
    getline(cin, poss);
    
//store the values in the person1 object
    person3.setName(namee);
    person3.setNumb(num);
    person3.setDept(deptt);
    person3.setPos(poss);
    
    cout << endl << endl;
    
//output the values from the user
    cout << "PERSON #1\n";
    cout << "Name: " << person1.getName() << endl;
    cout << "ID Number: " << person1.getNumb() << endl;
    cout << "Department: " << person1.getDept() << endl;
    cout << "Position: " << person1.getPos() << endl;
    
    cout << "PERSON #2\n";
    cout << "Name: " << person2.getName() << endl;
    cout << "ID Number: " << person2.getNumb() << endl;
    cout << "Department: " << person2.getDept() << endl;
    cout << "Position: " << person2.getPos() << endl;
    
    cout << "PERSON #3\n";
    cout << "Name: " << person3.getName() << endl;
    cout << "ID Number: " << person3.getNumb() << endl;
    cout << "Department: " << person3.getDept() << endl;
    cout << "Position: " << person3.getPos() << endl;
    
    return 0;
}