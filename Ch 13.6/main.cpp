//Christopher Alexman		  CSC 17A		 Chapter 13, P. 804, #06
//
/*******************************************************************************
 *
 * INVENTORY CLASS
 * _____________________________________________________________________________
 * This function creates creates an inventory class to hold info and to 
 * calculate data for the items. It specifies the private and public member
 * variables. It uses input validation by not accepting negative values for
 * the item number, quantity, or cost.
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

class Invntry
{
    private:
        int itemNum;
        int qntity;
        float cost;
        float ttlCost;
    public:
        Invntry();                      //default constructor
        Invntry(int, int, float);
        
        void setNum(int);
        void setQuan(int);
        void setCost(float);
        void setTotl(int, float);
        
        int getNum() const
            { return itemNum; }
        
        int getQuan() const
            { return qntity; }
        
        float getCost() const
            { return cost; }
        
        float getTotl() const
            { return ttlCost; }
};

//******************************************************************************
// The constructor initializes the private member variables to 0
//******************************************************************************
Invntry::Invntry()
{
    itemNum = 0;
    qntity = 0;
    cost = 0.0;
    ttlCost = 0.0;
}

//******************************************************************************
// The constructor copies the values to the appropriate member variables
//******************************************************************************
Invntry::Invntry(int n, int q, float c)
{
    itemNum = n;
    qntity = q;
    cost = c;
}

//******************************************************************************
// setNum assigns a value to the itemNum member                                *
//******************************************************************************
void Invntry::setNum(int n)
{
    itemNum = n;
}

//******************************************************************************
// setQuan assigns a value to the qntity member                                *
//******************************************************************************
void Invntry::setQuan(int q)
{
    qntity = q;
}

//******************************************************************************
// setCost assigns a value to the cost member                                  *
//******************************************************************************
void Invntry::setCost(float c)
{
    cost = c;
}

//******************************************************************************
// setTotl assigns a value to the ttlCost member                               *
//******************************************************************************
void Invntry::setTotl(int q, float c)
{
    ttlCost = q * c;
}

int main()
{
//create temporary local variables
    int number;
    int quant;
    float costt;
    float totalC;
    
//get the values from the user, use input validation
    cout << "ITEM #1\n";
    cout << "Enter the item number: ";
    cin >> number;
    while (number < 0)
    {
        cout << "ERROR. No negative values.";
            cout << "Enter the item number: ";
            cin >> number;
    }
    
    cout << "Enter the item quantity: ";
    cin >> quant;
    while (number < 0)
    {
        cout << "ERROR. No negative values.";
            cout << "Enter the item quantity: ";
            cin >> quant;
    }
    
    cout << "Enter the items cost: ";
    cin >> costt;
    while (number < 0)
    {
        cout << "ERROR. No negative values.";
            cout << "Enter the items cost: ";
            cin >> costt;
    }
    
    cout << endl;
    
    Invntry data(number, quant, costt);     //create an Invntry object
    data.setTotl(quant, costt);             //call function to get total cost
    
//output the data from the user
    cout << "ITEM #1" << endl;
    cout << "Item number: " << data.getNum() << endl;
    cout << "Item quantity: " << data.getQuan() << endl;
    cout << "Item cost: " << data.getCost() << endl;
    cout << "Total cost: " << data.getTotl();
    
    return 0;
}