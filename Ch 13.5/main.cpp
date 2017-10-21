//Christopher Alexman		  CSC 17A		 Chapter 13, P. 803, #05
//
/*******************************************************************************
 *
 * RETAIL ITEM CLASS
 * _____________________________________________________________________________
 * This function creates creates a class called RetailItem that holds data about
 * an item in a retail store. The member variables within are the description,
 * units on hand, and price. It uses a constructor that accepts arguments for
 * each member variable. Mutator functions store values in these variables. 
 * Accessor functions return these values in these member variables. A second
 * program created 3 retail item objects and stores specific data in them.
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

class RetItem
{
    private:
        string descrip;
        int untsOnH;
        float price;
    public: 
        RetItem(string, int, float);            //constructor
        void setDesc(string);
        void setUnit(int);
        void setPric(float);
        
        string getDesc() const
            { return descrip; }
        
        int getUnit() const
            { return untsOnH; }
        
        float getPric() const
            { return price; }
};

//******************************************************************************
// The constructor accepts arguments for description, units on hand, and price *
//******************************************************************************
RetItem::RetItem(string d, int u, float p)
{
    descrip = d;
    untsOnH = u;
    price = p;
}

//******************************************************************************
// setDesc sets the values of the member variable descrip                      *
//******************************************************************************
void RetItem::setDesc(string d)
{
    descrip = d;
}

//******************************************************************************
// setUnit sets the values of the member variable unitOnH                      *
//******************************************************************************
void RetItem::setUnit(int u)
{
    untsOnH = u;
}

//******************************************************************************
// setPric sets the values of the member variable price                        *
//******************************************************************************
void RetItem::setPric(float p)
{
    price = p;
}

int main()
{
//create temporary local variables
    string des;
    int unit;
    float prce;
    
//get the values for the 3 retail items
    cout << "ITEM #1\n";
    cout << "Description: ";
    getline(cin, des);
    cout << "Units on Hand: ";
    cin >> unit;
    cout << "Price: ";
    cin >> prce;
    cout << endl;
    
    RetItem item1(des, unit, prce);  //call constructor to store inputted values
    
    cin.ignore();                    //used due to getline, ignores enter key
    
    cout << "ITEM #2\n";
    cout << "Description: ";
    getline(cin, des);
    cout << "Units on Hand: ";
    cin >> unit;
    cout << "Price: ";
    cin >> prce;
    cout << endl;
    
    RetItem item2(des, unit, prce);  //call constructor to store inputted values
        
    cin.ignore();                    //used due to getline, ignores enter key
    
    cout << "ITEM #3\n";
    cout << "Description: ";
    getline(cin, des);
    cout << "Units on Hand: ";
    cin >> unit;
    cout << "Price: ";
    cin >> prce;
    cout << endl;
    
    RetItem item3(des, unit, prce);  //call constructor to store inputted values
    
//output the data inputted from the user
    cout << "ITEM #1\n";
    cout << "Description: " << item1.getDesc() << endl;
    cout << "Units on hand: " << item1.getUnit() << endl;
    cout << "Price: " << item1.getPric() << endl;
    
    cout << "ITEM #2\n";
    cout << "Description: " << item2.getDesc() << endl;
    cout << "Units on hand: " << item2.getUnit() << endl;
    cout << "Price: " << item2.getPric() << endl;
    
    cout << "ITEM #3\n";
    cout << "Description: " << item3.getDesc() << endl;
    cout << "Units on hand: " << item3.getUnit() << endl;
    cout << "Price: " << item3.getPric() << endl;
    
    return 0;
}