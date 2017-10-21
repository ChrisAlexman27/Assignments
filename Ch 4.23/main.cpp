//Christopher Alexman                CSC 17A              Chapter 4, P. 225, #23
//
/*******************************************************************************
 * CALCULATE AREA OF A CIRCLE, RECTANGLE, AND TRIANGLE
 * _____________________________________________________________________________
 * This program prompts the user if they want to calculate the
 * area of a circle, rectangle, or triangle in menu format. 
 * Based on the user choice the program will ask the user for
 * the components needed for the formula. It also places
 * restrictions on input values.
 *
 * Calculations are based on the formulas:
 * area = pi * radius^2
 * area = length * width
 * area = base * height * .5
 * _____________________________________________________________________________
 * INPUT
 * 	radiusC                 //radius of a circle
 * 	length                  //length of a rectangle
 * 	width                   //width of a rectangle
 * 	base                    //base of a triangle
 * 	height                  //height of a triangle
 * 	PI                      //the constant for pi
 * 	choice                  //the menu choice of the user
 * 	ch                      //for the enter key
 * 		 
 * 	
 * OUTPUT
 * 	areaCircle              //area of a circle
 * 	areaRectangle       	//area of a rectangle
 * 	areaTriangle	        //area of a triangle
 *
 ******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
 
int main() 
{
//declare and initialize constant
    const float PI = 3.14159;   //the constant for pi
 
//define variables
    float radiusC;              //radius of a circle
    float length;               //length of a rectangle
    float width;                //width of a rectangle
    float base;                 //base of a triangle
    float height;               //height of a triangle
    int choice;                 //the menu choice of the user
    float areaCir;              //area of a circle
    float areaRec;              //area of a rectangle
    float areaTri;              //area of a triangle
 
//display menu and get a choice
    cout << "Geometry Calculator\n\n";
    cout << "\t1. Calculate the Area of a Circle\n";
    cout << "\t2. Calculate the Area of a Rectangle\n";
    cout << "\t3. Calculate the Area of a Triangle\n";
    cout << "\t4. Quit\n\n";
    cout << "\tEnter your choice (1-4): \n\n";
    cin >> choice;
    
//input validation for if choice is outside of the menu options
    while ((choice > 4) || (choice < 1))            //values outside the bounds
    {
        cout << "Error, choice not on list.\n";     //prompts for choice again
        cout << "Enter your choice (1-4): ";
        cin >> choice;                              //ask for choice again
        cout << endl;
    }
 
//prompts user to enter radius, calculates area, displays
    if (choice == 1)
    {
        cout << "Enter the radius of the circle: ";
	cin >> radiusC;
        
//input validation not allowing negative values, loops until positive number
        while (radiusC < 0)
        {
            cout << "No negative values are allowed.\n";
            cout << "Enter the radius of the circle: ";
            cin >> radiusC;
        }
	areaCir = PI * pow(radiusC, 2);     //calculates area of the circle
	cout << "\nThe area of the circle is: " << areaCir << endl;
    }
//prompts user to enter length, width; calculates area, displays
    else if (choice == 2)
    {
	cout << "Enter the length and width of the rectangle: ";
	cin >> length >> width;
        
//input validation not allowing negative values, loops until positive numbers
        while ((length < 0) || (width < 0))
        {
            cout << "No negative values are allowed.\n";
            cout << "Enter the length and width of the rectangle: ";
            cin >> length >> width;
        }
	areaRec = length * width;       //calculates area of the rectangle
	cout << "\nThe area of the rectangle is " << areaRec;
    }
//prompts user to enter base, height; calculates area, displays
    else if (choice == 3)
    {
	cout << "Enter the base and height for the triangle: ";
	cin >> base >> height;
        
//input validation not allowing negative values, loops until positive number
        while ((base < 0) || (height < 0))
        {
            cout << "No negative values are allowed.\n";
            cout << "Enter the base and height for the triangle: \n";
            cin >> base >> height;
            
        }
	areaTri = base * height * .5;       //calculates area of the triangle
	cout << "\nThe area of the triangle is " << areaTri;
    }
//closes program per user request
    else if (choice == 4)
    {
	cout << "Goodbye";
    }
 
	return 0;
}