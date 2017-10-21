//Christopher Alexman		  CSC 17A		 Chapter 13, P. 802, #03
//
/*******************************************************************************
 *
 * CAR CLASS
 * _____________________________________________________________________________
 * This function creates a class called Car that has member variables of year
 * model, make, and speed. It has a constructor, accessor, accelerate function,
 * and brake function. An object of car is created and it calls the acceleration
 * function 5 times. After each call of that function the current speed is
 * displayed. The brake function is then called 5 times. Each time the current
 * speed of the car is displayed.
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

//Car class declaration
class Car
{
    private:
        int yrModel;
        string make;
        int speed;
    public:
        Car(int, string);               //constructor
        
        int getYr() const
            { return yrModel; }
        
        string getMake() const
            { return make; }
        
        int getSpd() const
            { return speed; }
        
        void accel();
        void brake();
};

//******************************************************************************
// The constructor accepts arguments for year model and make
//******************************************************************************
Car::Car(int y, string m)
{
    yrModel = y;
    make = m;
    speed = 0;
}

//******************************************************************************
// accel function increments 5 to speed every time it is called
//******************************************************************************
void Car::accel()
{
    speed += 5;
}

//******************************************************************************
// brake function decrements 5 to speed every time it is called
//******************************************************************************
void Car::brake()
{
    speed -= 5;
}

int main()
{
//initialize the year and make
    Car specs(1967, "Chevy Impala");
    
    cout << "Starting speed: " << specs.getSpd() << "MPH" << endl << endl;

//loop through 5 times, call the accel function to increment 5, output the speed
    for(int count = 0; count < 5; count++)
    {
        specs.accel();
        cout << "Current speed: " << specs.getSpd() << endl;
    }
    
    cout << endl;
    
//loop through 5 times, call the brake function to decrement 5, output the speed
    for(int count = 0; count < 5; count++)
    {
        specs.brake();
        cout << "Current speed: " << specs.getSpd() << endl;
    }
    
    return 0;
}