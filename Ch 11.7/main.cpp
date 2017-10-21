#include <iostream>
#include <string>

using namespace std;

struct Customer{
    string Name;
    string Address;
    string City;
    string State;
    string ZIP;
    string Pnumber; //phone number
    double aBalance; //account balance
    string DataOfLastPaym;
};

void EnterChangeAccInfo(Customer&);
void showInfo(Customer);
//void Search();

const int SIZE = 10;

int main()
{
    int answer;

    //here I started to think, maybe I need to have parts of the info initialized?
    Customer aArrayOfCustomers[SIZE];

//    aArrayOfCustomers[0].Name = "Jake Smith";
//    aArrayOfCustomers[0].Address = "888 Forest Hill";
//    aArrayOfCustomers[0].City = "Peoria";
//    aArrayOfCustomers[0].State = "IL";
//    aArrayOfCustomers[0].ZIP = "61550";
//    aArrayOfCustomers[0].Pnumber = "888-712-9881";
//    aArrayOfCustomers[0].aBalance = 800.25;
//    aArrayOfCustomers[0].DataOfLastPaym = "08/15/2011";


    // Display a menu.
    cout << "---------- MENU ----------------------" << endl;
    cout << "1. Enter new account information      |\n";
    cout << "2. Change account information         |\n";
    cout << "3. Display all account information    |\n";
    cout << "4. Exit the program                   |\n";
    cout << "--------------------------------------" << endl;
    cout << endl;

    while(answer > 4 || answer < 1){
    cout << "Choose 1-4: ";
    cin >> answer;
    }
    cout << endl;

    while(answer != 4){
        switch(answer){
        case 1:{
            //new account info.
            EnterChangeAccInfo(aArrayOfCustomers[0]);

        }
        break;
        case 2:{
            //change account info.

        }
        break;
        case 3:{
            //display info
            showInfo(aArrayOfCustomers[0]); // when I display info it runs infinite?

        }
        break;
        default: break;

        }
    }

    return 0;
}

// Function getInfo gets account information from the user
//and stores it in the parameter, which is a Customer structure
//reference variable.
void EnterChangeAccInfo(Customer &a){
    cout << "Enter customer's name: ";
    cin.ignore();
    getline(cin,a.Name);
    cout << "Address: ";
    getline(cin,a.Address);
    cout << "City: ";
    cin >> a.City;
    cout << "State: ";
    cin >> a.State;
    cout << "ZIP: ";
    cin >> a.ZIP;
    cout << "Phone Number: ";
    cin >> a.Pnumber;
    cout << "Account Balance: ";
    cin >> a.aBalance;
    cout << "Date of Last Payment: ";
    cin.ignore();
    getline(cin,a.DataOfLastPaym);
}

// Function showInfo displays the customer's name, address,
//account balance, and date of last payment.
//The information is passed into the c structure.
void showInfo(Customer display){
    cout << "\n --- Data for " <<display.Name <<" ---\n";
	cout << "\nAddress:\t" << display.Address << ", " << display.City << ", " << display.State << ", " << display.ZIP;
	cout << "\nTelephone:\t" << display.Pnumber;
	cout << "\nLast Payment:\t" << display.DataOfLastPaym;
	cout << "\nAccount balance:\t" << display.aBalance << endl;
}

/*
// Search the array for account
void Search(string theName){
    for(int i = 0; i < SIZE; i++){
        if(theName == info[i].Name){ //issue here
            //enter what to do if account found
            cout << "Name: " << info[i].Name << endl;
            cout << "Address: "<< info[i].Address << endl;
            cout << "City: " << info[i].City << endl;
            cout << "State: " << info[i].State << endl;
            cout << "ZIP: " << info[i].ZIP << endl;
            cout << "Phone Number: " << info[i].Pnumber << endl;
            cout << "Account Balance: " << info[i].aBalance << endl;
            cout << "Date of Last Payment: " << info[i].DataOfLastPaym << endl;
            break;
        }else{
            cout << "Account not found" << endl;
        }
    }
}
*/