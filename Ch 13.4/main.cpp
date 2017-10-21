//Christopher Alexman		  CSC 17A		 Chapter 13, P. 803, #04
//
/*******************************************************************************
 *
 * PERSONAL INFORMATION CLASS
 * _____________________________________________________________________________
 * This function creates a class that holds the personal data of name, address,
 * age, and phone number. It has accessor and mutator functions. The class is
 * demonstrated by 3 instances. One holds your personal info and the other two
 * hold info of your friends/family.
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

//Data class declaration
class Data
{
    private:
        string name;
        string address;
        int age;
        int number;
        
    public:
        void setName(string);
        void setAdr(string);
        void setAge(int);
        void setNumb(int);
        string getName() const;
        string getAdr() const;
        int getAge() const;
        int getNumb() const;
};

//******************************************************************************
// setName assigns a value to the name member.                                 *
//******************************************************************************
void Data::setName(string na)
{
    name = na;
}

//******************************************************************************
// setAdr assigns a value to the address member.                               *
//******************************************************************************
void Data::setAdr(string ad)
{
    address = ad;
}

//******************************************************************************
// setAge assigns a value to the age member.                                   *
//******************************************************************************
void Data::setAge(int ag)
{
    age = ag;
}

//******************************************************************************
// setNumb assigns a value to the number member.                               *
//******************************************************************************
void Data::setNumb(int nu)
{
    number = nu;
}

//******************************************************************************
// getName returns the value in the name member.                               *
//******************************************************************************
string Data::getName() const
{
    return name;
}

//******************************************************************************
// getNAdr returns the value in the address member.                            *
//******************************************************************************
string Data::getAdr() const
{
    return address;
}

//******************************************************************************
// getAge returns the value in the age member.                                 *
//******************************************************************************
int Data::getAge() const
{
    return age;
}

//******************************************************************************
// getNumb returns the value in the number member.                             *
//******************************************************************************
int Data::getNumb() const
{
    return number;
}

int main()
{
//create 3 instances of the Data class
    Data you;
    Data friends;
    Data family;
   
//create local variables for the private member variables
    string namee;
    string adrr;
    int agee;
    int numberr;
    
//get values for the user
    cout << "Enter your name: ";
    getline(cin, namee);
    
    cout << "Enter your address: ";
    getline(cin, adrr);
    
    cout << "Enter your age: ";
    cin >> agee;
    
    cout << "Enter your number: ";
    cin >> numberr;
    
//store these values in the first instance, object you
    you.setName(namee);
    you.setAdr(adrr);
    you.setAge(agee);
    you.setNumb(numberr);
    
    cin.ignore();                   //used due to getline, ignores enter key
    
//get values for the user's friend
    cout << "\nEnter your friend's name: ";
    getline(cin, namee);
    
    cout << "Enter your friend's address: ";
    getline(cin, adrr);
    
    cout << "Enter your friend's age: ";
    cin >> agee;
    
    cout << "Enter your friend's number: ";
    cin >> numberr;
    
//store these values in the second instance, object friends
    friends.setName(namee);
    friends.setAdr(adrr);
    friends.setAge(agee);
    friends.setNumb(numberr);
    
    cin.ignore();                   //used due to getline, ignores enter key
    
//get values for the user's family member
    cout << "\nEnter your family member's name: ";
    getline(cin, namee);
    
    cout << "Enter your family member's address: ";
    getline(cin, adrr);
    
    cout << "Enter your family member's age: ";
    cin >> agee;
    
    cout << "Enter your family member's number: ";
    cin >> numberr;
    
//store these values in the third instance, object family
    family.setName(namee);
    family.setAdr(adrr);
    family.setAge(agee);
    family.setNumb(numberr);
    
//output all of the info received from the user
    cout << "\n\nYOUR DATA:\n";
    cout << "-------------------------\n";
    cout << "Name: " << you.getName() << endl;
    cout << "Address: " << you.getAdr() << endl;
    cout << "Age: " << you.getAge() << endl;
    cout << "Number: " << you.getNumb() << endl << endl;
    
    cout << "YOUR FRIEND'S DATA:\n";
    cout << "-------------------------\n";
    cout << "Name: " << friends.getName() << endl;
    cout << "Address: " << friends.getAdr() << endl;
    cout << "Age: " << friends.getAge() << endl;
    cout << "Number: " << friends.getNumb() << endl << endl;
    
    cout << "YOUR FAMILY MEMBER'S DATA:\n";
    cout << "-------------------------\n";
    cout << "Name: " << family.getName() << endl;
    cout << "Address: " << family.getAdr() << endl;
    cout << "Age: " << family.getAge() << endl;
    cout << "Number: " << family.getNumb() << endl;
    
    
    return 0;
}