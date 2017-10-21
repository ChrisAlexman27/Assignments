//Christopher Alexman		 CSC 17A		 Chapter 11, P. 652, #05
//
/*******************************************************************************
 *
 * STORE WEATHER DATA INTO AN STRUCTURE
 * _____________________________________________________________________________
 * This function uses a structure to store weather data into an array of 12
 * structures. It asks the user to enter data for each month and stores it in
 * each structure of the array. The input validation is that temp values are
 * between -100 and +140. Then it displays the average monthly rainfall, total
 * rainfall for the year, and the highest/lowest temperatures for the year.
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
#include <iomanip>
using namespace std;
 
struct Data
{   
    string month;               //the name of the month
    float ttlRain;              //total amount of rainfall
    float highTmp;              //highest temperature
    float lowTmp;               //lowest temperature
    float avgTemp;              //average monthly temperature
};

struct YrInfo
{
    float totlPre;              //total precipitate in a year
    float avgPpt;               //average precipitate in a year
    float highPre;              //highest amount of rainfall
    float lowPre;               //lowest amount of rainfall
    string highMon;             //month with highest precipitate
    string lowMon;              //month with lowest precipitate
    float avgTYr;               //average yearly temperature   
    float hgstTem;              //highest temperature of the year
    float lwstTem;              //lowest temperature in the year
};

//the enumerated data type for the month names
enum monthN
{ 
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
    AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER 
} mName;

//use static cast to to change first enumerator to an int
    int mNumber = static_cast<monthN>(mName);

void getData(Data [], int);
void avgTemp(Data [], YrInfo &, int);
void calcPer(Data[], YrInfo &, int);
void getPer(Data[], YrInfo &, int);
void disData(const Data [], const YrInfo &, int);

bool validateInput(Data[], int);

int main()
{
    //create a constant for the size of the array
    const int MONTHS = 12;

//create an array of structures, initialize the members to the month names
    Data mnthNms[MONTHS] = { { "JANUARY" }, { "FEBRUARY" }, { "MARCH" }, 
                             { "APRIL" }, { "MAY" }, { "JUNE" }, { "JULY" }, 
                             { "AUGUST" },   { "SEPTEMBER" }, { "OCTOBER" }, 
                             { "NOVEMBER" }, { "DECEMBER" } };
   
//definition of a structure variable, initialize all values to 0
//it is a holder structure
    YrInfo holder = { 0.0, 0.0, 0.0, 0.0, "\0", "\0", 0.0, 0.0, 0.0, };

//call the functions
    getData(mnthNms, mNumber);
    avgTemp(mnthNms, holder, mNumber);
    calcPer(mnthNms, holder, mNumber);
    getPer(mnthNms, holder, mNumber);
    disData(mnthNms, holder, mNumber);

   return 0;
}

//******************************************************************************
// Definition of function getData
// This function uses a for loop to get all of the various values for each of 
// the 12 months. It uses input validation to  make sure the values are not
// negative or outside the bounds. It receives a structure array and the
// number of months as arguments.
//******************************************************************************
void getData(Data mnthNms[], int mNumber)
{
//use a for loop to get the data for each month, one at a time
    for (int mNumber = 0; mNumber <= DECEMBER; mNumber++)
    {
        cout << "Enter data for " << mnthNms[mNumber].month;
        cout << "\n----------------------------";

        cout << "\n\nAmount of rainfall" << ": ";
        cin >> mnthNms[mNumber].ttlRain;

//input validation, will not accept negative values
        while (mnthNms[mNumber].ttlRain < 0)
        {
            cout << "ERROR. No negative values.";

            cout << "\n\nAmount of rainfall" << ": ";
            cin >> mnthNms[mNumber].ttlRain;
        }

        cout << "Highest temperature" << ": ";
        cin >> mnthNms[mNumber].highTmp;

//input validation, temperature cannot be outside these values
        while (mnthNms[mNumber].highTmp < -100 || mnthNms[mNumber].highTmp > 140)
        {
            cout << "ERROR. Temperatures cannot be above +140F or below -100F ";

            cout << "Highest temperature" << ": ";
            cin >> mnthNms[mNumber].highTmp;
        }

        cout << "Lowest temperature" << ": ";
        cin >> mnthNms[mNumber].lowTmp;

        while (mnthNms[mNumber].lowTmp < -100 || mnthNms[mNumber].lowTmp > 140)
        {
            cout << "ERROR. Temperatures cannot be above +140F or below -100F ";

            cout << "Lowest temperature" << ": ";
            cin >> mnthNms[mNumber].lowTmp;
        }
        
        cout << endl << endl;
    }
}

//******************************************************************************
// Definition of function avgTemp
// This function uses a for loop to step through all of the values given for
// the year and sums them up with the holder variable. 
//******************************************************************************
void avgTemp(Data mnthNms[], YrInfo &holder, int mNumber)
{
    for (int mNumber = 0; mNumber <= DECEMBER; mNumber++)
    {
        mnthNms[mNumber].avgTemp = (mnthNms[mNumber].highTmp + 
                                  mnthNms[mNumber].lowTmp) / 2;

        holder.avgTYr += mnthNms[mNumber].lowTmp + mnthNms[mNumber].highTmp;
    }

    holder.avgTYr /= 24;
}

//******************************************************************************
// Definition of function calcPer
// This function uses an array of structures and the holder reference variable
// in order to calculate the precipitate amounts.
//******************************************************************************
void calcPer(Data mnthNms[], YrInfo &holder, int mNumber)
{
    for (int mNumber = 0; mNumber <= DECEMBER; mNumber++)
    {
        holder.totlPre += mnthNms[mNumber].ttlRain;
        holder.avgPpt = holder.totlPre / 12;
    }
}

//******************************************************************************
// Definition of function getPer
// This function uses an array of structures and the holder reference variable
// to figure out which months have the lowest and highest rainfall values.
//******************************************************************************
void getPer(Data mnthNms[], YrInfo &holder, int mNumber)
{
    holder.highPre = mnthNms[0].ttlRain;
    holder.lowPre =  mnthNms[0].ttlRain;

    for (int mNumber = 0; mNumber <= DECEMBER; mNumber++)
    {
        if (mnthNms[mNumber].ttlRain <= holder.lowPre)
        {
            holder.lowPre = mnthNms[mNumber].ttlRain;
            holder.lowMon = mnthNms[mNumber].month;
        }

        if (mnthNms[mNumber].ttlRain >= holder.highPre)
        {
            holder.highPre = mnthNms[mNumber].ttlRain;
            holder.highMon = mnthNms[mNumber].month;
        }
    }
}

/* **********************************************************
   Definition: displayMetData

    This function uses an array of structs and a const
    reference parameter to display their contents.
   ********************************************************** */

//******************************************************************************
// Definition of function disData
// This function displays and formats all of the data using an array of 
// structures and the holder reference variable.
//******************************************************************************
void disData(const Data metData[], const YrInfo &holder, int mNumber)
{
    cout << setw(9)  << left  << "MONTH NAME";
    cout << setw(19) << right << "Rainfall Amount";
    cout << setw(20) << right << "Highest Temp";
    cout << setw(20) << right << "Lowest Temp";
    cout << setw(20) << right << "Average Temp" << "\n";

//format for the rest of the output
    cout << fixed << showpoint << setprecision(2);

    for (int mNumber = 0; mNumber <= DECEMBER; mNumber++)
    {
        cout << setw(9) << left;
        cout << metData[mNumber].month;
        cout << setw(20) << right << metData[mNumber].ttlRain;
        cout << setw(20) << right << metData[mNumber].highTmp;
        cout << setw(20) << right << metData[mNumber].lowTmp;
        cout << setw(20) << right << metData[mNumber].avgTemp;
        cout << endl;
    }
    
    cout << endl << endl;

    cout << "Total rainfall: ";
    cout << holder.totlPre << " mm";
            
    cout << "\nAverage rainfall: ";   
    cout << holder.avgPpt << " mm";
            
    cout << "\n\nMonth with highest rainfall: ";
    cout << holder.highMon;
            
    cout << "\nHighest recorded rainfall:  ";              
    cout << holder.highPre << " mm";
            
    cout << "\n\nMonth with lowest rainfall: "; 
    cout << holder.lowMon;
            
    cout << "\nLowest recorded rainfall: ";
    cout << holder.lowPre << " mm" << "\n";
   
    cout << "\nAverage of all monthly average temperatures: ";      
    cout << holder.avgTYr << "  F";
            
}