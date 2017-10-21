//Christopher Alexman		 CSC 17A		 Chapter 11, P. 652, #04
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
#include <cstdlib>

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

void getData(Data [], const int);
void avgTemp(Data [], YrInfo &, const int);
void calcPer(Data[], YrInfo &, const int);
void getPer(Data[], YrInfo &, const int);
void disData(const Data [], const YrInfo &, const int);

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
    getData(mnthNms, MONTHS);
    avgTemp(mnthNms, holder, MONTHS);
    calcPer(mnthNms, holder, MONTHS);
    getPer(mnthNms, holder, MONTHS);
    disData(mnthNms, holder, MONTHS);

   return 0;
}

//******************************************************************************
// Definition of function getData
// This function uses a for loop to get all of the various values for each of 
// the 12 months. It uses input validation to  make sure the values are not
// negative or outside the bounds. It receives a structure array and the
// number of months as arguments.
//******************************************************************************
void getData(Data mnthNms[], const int MONTHS)
{
//use a for loop to get the data for each month, one at a time
    for (int count = 0; count < MONTHS; count++)
    {
        cout << "Enter data for " << mnthNms[count].month;
        cout << "\n----------------------------";

        cout << "\n\nAmount of rainfall" << ": ";
        cin >> mnthNms[count].ttlRain;

//input validation, will not accept negative values
        while (mnthNms[count].ttlRain < 0)
        {
            cout << "ERROR. No negative values.";

            cout << "\n\nAmount of rainfall" << ": ";
            cin >> mnthNms[count].ttlRain;
        }

        cout << "Highest temperature" << ": ";
        cin >> mnthNms[count].highTmp;

//input validation, temperature cannot be outside these values
        while (mnthNms[count].highTmp < -100 || mnthNms[count].highTmp > 140)
        {
            cout << "ERROR. Temperatures cannot be above +140F or below -100F ";

            cout << "Highest temperature" << ": ";
            cin >> mnthNms[count].highTmp;
        }

        cout << "Lowest temperature" << ": ";
        cin >> mnthNms[count].lowTmp;

        while (mnthNms[count].lowTmp < -100 || mnthNms[count].lowTmp > 140)
        {
            cout << "ERROR. Temperatures cannot be above +140F or below -100F ";

            cout << "Lowest temperature" << ": ";
            cin >> mnthNms[count].lowTmp;
        }
        
        cout << endl << endl;
    }
}

//******************************************************************************
// Definition of function avgTemp
// This function uses a for loop to step through all of the values given for
// the year and sums them up with the holder variable. 
//******************************************************************************
void avgTemp(Data mnthNms[], YrInfo &holder, const int MONTHS)
{
    for (int index = 0; index < MONTHS; index++)
    {
        mnthNms[index].avgTemp = (mnthNms[index].highTmp + 
                                  mnthNms[index].lowTmp) / 2;

        holder.avgTYr += mnthNms[index].lowTmp + mnthNms[index].highTmp;
    }

    holder.avgTYr /= 24;
}

//******************************************************************************
// Definition of function calcPer
// This function uses an array of structures and the holder reference variable
// in order to calculate the precipitate amounts.
//******************************************************************************
void calcPer(Data mnthNms[], YrInfo &holder, const int MONTHS)
{
    for (int index = 0; index < MONTHS; index++)
    {
        holder.totlPre += mnthNms[index].ttlRain;
        holder.avgPpt = holder.totlPre / 12;
    }
}

//******************************************************************************
// Definition of function getPer
// This function uses an array of structures and the holder reference variable
// to figure out which months have the lowest and highest rainfall values.
//******************************************************************************
void getPer(Data mnthNms[], YrInfo &holder, const int MONTHS)
{
    holder.highPre = mnthNms[0].ttlRain;
    holder.lowPre =  mnthNms[0].ttlRain;

    for (int index = 0; index < MONTHS; index++)
    {
        if (mnthNms[index].ttlRain <= holder.lowPre)
        {
            holder.lowPre = mnthNms[index].ttlRain;
            holder.lowMon = mnthNms[index].month;
        }

        if (mnthNms[index].ttlRain >= holder.highPre)
        {
            holder.highPre = mnthNms[index].ttlRain;
            holder.highMon = mnthNms[index].month;
        }
    }
}

//******************************************************************************
// Definition of function disData
// This function displays and formats all of the data using an array of 
// structures and the holder reference variable.
//******************************************************************************
void disData(const Data metData[], const YrInfo &holder, const int MONTHS)
{
    cout << setw(9)  << left  << "MONTH NAME";
    cout << setw(19) << right << "Rainfall Amount";
    cout << setw(20) << right << "Highest Temp";
    cout << setw(20) << right << "Lowest Temp";
    cout << setw(20) << right << "Average Temp" << "\n";

//format for the rest of the output
    cout << fixed << showpoint << setprecision(2);

    for (int count = 0; count < MONTHS; count++)
    {
        cout << setw(9) << left;
        cout << metData[count].month;
        cout << setw(20) << right << metData[count].ttlRain;
        cout << setw(20) << right << metData[count].highTmp;
        cout << setw(20) << right << metData[count].lowTmp;
        cout << setw(20) << right << metData[count].avgTemp;
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