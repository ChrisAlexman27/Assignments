//Christopher Alexman		  CSC 17A		 Chapter 11, P. 653, #11
//
/*******************************************************************************
 *
 * MONTHLY BUDGET
 * _____________________________________________________________________________
 * This program uses a structure to hold various expense categories. It passes
 * the structure to a function that gets all of the values from the user.
 * Then the program passes the structure that displays a report and if it the
 * entered values are under or over compared to reference values.
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

//the structure specified in the problem
struct MonthlyBudget
{
    float housing;                  //housing 
    float utility;                  //utilities
    float hExpen;                   //household expenses
    float transp;                   //transportation
    float food;                     //food
    float medical;                  //medical
    float insurnc;                  //insurance
    float entrtn;                   //entertainment
    float clothes;                  //clothes
    float misc;                     //miscellaneous
    float total;                    //total           
};

//function prototypes
void userInp(MonthlyBudget &);
void calcTtl(MonthlyBudget &);
void ovrUndr(const float, const float);
void output(const MonthlyBudget, const MonthlyBudget);

int main()
{
//create 2 structure variables
    MonthlyBudget spent;
    MonthlyBudget refer = { 500.0, 150.0,  65.0, 50.0, 250.0, 30.0, 100.0, 
                            150.0, 75.0,  50.0, 1420.0 };

//function calls
    userInp(spent);
    calcTtl(spent);
    output(spent, refer);

   return 0;
}

//******************************************************************************
// Definition of function userInp
// This function prompts the user to get how much spent on all the various
// values from the structure. It only gets the values.
//******************************************************************************
void userInp(MonthlyBudget &spent)
{
    cout << "MONTHLY BUDGET\n";
    cout << "--------------\n";
    
    cout << "Housing: ";
    cin >> spent.housing;
    
    cout << "\nUtilities: ";
    cin >> spent.utility;

    cout << "\nHousehold Expenses: ";
    cin >> spent.hExpen;

    cout << "\nTransportation: ";
    cin >> spent.transp;

    cout << "\nFood: ";
    cin >> spent.food;

    cout << "\nMedical: ";
    cin >> spent.medical;

    cout << "\nInsurance: ";
    cin >> spent.insurnc;

    cout << "\nEntertainment: ";
    cin >> spent.entrtn;

    cout << "\nClothing: ";
    cin >> spent.clothes;

    cout << "\nMiscellaneous: ";
    cin >> spent.misc;
}

//******************************************************************************
// Definition of function calcTtl
// This function adds together all of the values entered in the last function.
// The total is the total amount spent in the whole month
//******************************************************************************
void calcTtl(MonthlyBudget &spent)
{
    spent.total = spent.housing + spent.utility + spent.hExpen + spent.transp +
                  spent.food + spent.medical + spent.insurnc + spent.entrtn +
                  spent.clothes + spent.misc;
}

//******************************************************************************
// Definition of function ovrUndr
// This function uses a ternary method to compare the amount spent to the 
// amount that was budgeted by the structure. The comparison is made on each
// budget item.
//******************************************************************************
void ovrUndr(const float spent, const float fix)
{
    const string overBudget = " over budget\n";
    const string underBudget = " under budget\n";
    const string balancedBudget = " balanced budget\n";

    cout << fixed << showpoint << setprecision(2);

//I found this online and cannot fully explain how it works
    spent > fix ? cout << (spent - fix) << overBudget :
    spent < fix ? cout << (fix - spent) << underBudget :
    cout << (fix - spent) << balancedBudget;
}

//******************************************************************************
// Definition of function output
// This function outputs and formats all of the details specified from the 
// question. It calls the ovrUndr function multiple times to determine if
// over or under on budget.
//******************************************************************************
void output(const MonthlyBudget spent, const MonthlyBudget fix)
{
    cout << "\n\nTHE RESULTS\n";
    cout << "---------------------------------------\n";

    cout << "ITEM" << setw(27) << right << "BUDGETED" 
         << setw(20) << right << "SPENT" << setw(28) << right << "RESULT\n";

    cout << setw(20) << left  << "Housing";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.housing; 
    cout << setw(16) << right << "$ " << setw(7) << right << spent.housing;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.housing, fix.housing);

    cout << setw(20) << left  << "Utilities";
    cout << setw(5)  << right << "$ " << setw(7) << right << fix.utility;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.utility;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.utility, fix.utility);

    cout << setw(20) << left  << "Household Expenses";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.hExpen;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.hExpen;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.hExpen, fix.hExpen);

    cout << setw(20) << left  << "Transport";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.transp;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.transp;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.transp, fix.transp);

    cout << setw(20) << left  << "Food";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.food;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.food;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.food, fix.food);

    cout << setw(20) << left  << "Medical";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.medical;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.medical;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.medical, fix.medical);

    cout << setw(20) << left  << "Insurance";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.insurnc;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.insurnc;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.insurnc, fix.insurnc);

    cout << setw(20) << left  << "Entertainment";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.entrtn;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.entrtn;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.entrtn, fix.entrtn);

    cout << setw(20) << left  << "Clothing";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.clothes;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.clothes;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.clothes, fix.clothes);

    cout << setw(20) << left  << "Miscellaneous";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.misc;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.misc;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.misc, fix.misc);

    cout << setw(20) << left  << "Total";
    cout << setw(5) << right  << "$ " << setw(7) << right << fix.total;
    cout << setw(16) << right << "$ " << setw(7) << right << spent.total;
    cout << setw(19) << right << "$ " << setw(7) << right;
    ovrUndr(spent.total, fix.total);
}