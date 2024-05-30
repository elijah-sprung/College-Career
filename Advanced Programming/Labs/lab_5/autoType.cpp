/*
   Author: Elijah Sprung
   Date: 2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_5/autoType.cpp

   About: The implementation file for the autoType class.
*/

#include "autoType.h"
#include <iomanip>
#include <sstream>

autoType::autoType(double od_in, double fl_in, double mpg_in, double fuelCap_in)
{
  odometer = fuelLevel = mpg = 0;

  if (fuelCap_in > 0)
  {
    fuelCap = fuelCap_in;
  }
  else
  {
    cerr << "You have entered a fuel cap that is lower than 1, please enter a";
    cerr << " higher value. Until then it has been sent to 20." << endl;
    fuelCap = 20;
  }
  
  setAutoSpecs(od_in, fl_in, mpg_in);
}

void autoType::setAutoSpecs(double od_in, double fl_in, double mpg_in)
{
  bool flag = false;

  if (od_in < 0)
  {
    cerr << "You have entered an odometer level lower than 0, it will stay at";
    cerr << " 0 until changed." << endl;
    flag = true;
  }
  if (od_in < odometer)
  {
    cerr << "You have entered an odometer level less than the previous level,";
    cerr << " enter a value greater than " << odometer << "." << endl;
    flag = true;
  }

  if (fl_in < 0)
  {
    cerr << "You have entered a fuel level less than zero, it will stay at 0";
    cerr << " until changed." << endl;
    flag = true;
  }
  if (fl_in > fuelCap)
  {
    cerr << "You have entered a fuel level greater than the set cap, enter a";
    cerr << " value lower than " << fuelCap << "." << endl;
    flag = true;
  }

  if (mpg_in < 1)
  {
    cerr << "You have entered a fuel efficiency lower than 1, it will stay at";
    cerr << " 1 until changed." << endl;
    flag = true;
  }

  if (!flag)
  {
    odometer = od_in;
    fuelLevel = fl_in;
    mpg = mpg_in;
  }
  else
  {
    odometer = 0;
    fuelLevel = 0;
    mpg = 1;
  }
}

string autoType::getAutoSpecs(void)const
{
  ostringstream sout;

  sout << fixed << showpoint << setprecision(2);
  sout << "Miles = " << odometer;
  sout << ", Fuel Level = " << fuelLevel;
  sout << ", Efficiency = " << mpg;  
  sout << ", Fuel Capacity = " << fuelCap;

  return sout.str();
}

void autoType::addFuel(double fl_in)
{
  bool flag = false;

  if (fl_in < 0)
  {
    cerr << "A value less than 0 was input, no fuel change." << endl;
    flag = true;
  }
  else if (fl_in + fuelLevel > fuelCap)
  {
    cerr << "This amount would overflow the tank, the tank has been set to";
    cerr << " full." << endl;
    flag = true;
    fuelLevel = fuelCap;
  }

  if (!flag)
  {
    fuelLevel += fl_in;
  }
}

void autoType::drive(double distance)
{
  double maxDistance = fuelLevel * mpg; 
  if (distance <= maxDistance)
  {
    odometer += distance;
    fuelLevel -= distance / mpg;
  } 
  else
  {
    cerr << "Out of gas after " << maxDistance << " miles." << endl;
    odometer += maxDistance;
    fuelLevel = 0;
  }
}
