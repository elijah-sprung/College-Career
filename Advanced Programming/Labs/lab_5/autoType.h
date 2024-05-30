/*
   Author: Elijah Sprung
   Date: 2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_5/autoType.h

   About: The header file for the autoType class.
*/

#include <iostream>

using namespace std;

#ifndef AUTO_TYPE
#define AUTO_TYPE

class autoType
{
  private:
    double odometer;
    double fuelLevel;
    double mpg;
    double fuelCap;

  public:

    /* Constructor for the class with parameters
     * Sets the odometer, fuelLevel, mpg, and fuelCap.  If no paramters
     * are given it uses the default values.
     * Postcondition - odometer=od_in, fuelLevel=fl_in
     *                 mpg=mpg_in, fuelCap = fuelCap_in
     * NOTE: with this constructor, a default constructor is
     * NOT needed.
     */

    autoType(double od_in = 0, double fl_in = 0, double mpg_in = 1, double fuelCap_in = 20);
      
    /* Function to set the auto specs - odometer, fuelLevel, and mpg.
     * Postcondition - odometer=od_in, fuelLevel=fl_in
     *                 mpg=mpg_in
     */

    void setAutoSpecs(double od_in, double fl_in, double mpg_in);

    /* Function to build a string containing the odometer, fuelLevel,
     * mpg and fuelCap. The values will be rounded off to two decimal places.
     * Postcondition - the string is returned.
     */

    string getAutoSpecs(void)const;

    /*
      addFuel: Adds fuel to the tank without going over the cap.
      pre-condition: A value must be passed to increase the fuel level by.
      post-condition: The fuel level will only change if it would not exceed
        the tank cap.
    */

    void addFuel(double fl_in);

    /* Function to drive the car the distance given in a parameter.
     * The function will update the odometer and fuel amounts and
     * monitor if you are trying to drive more than you have fuel.
     * If you do not have enough fuel to drive the distance, the 
     * odometer and fuel will be updated based on how far you actually
     * can drive.
     */ 

    void drive(double distance);
};
#endif
