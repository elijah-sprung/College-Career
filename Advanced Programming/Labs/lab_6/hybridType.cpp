/*
  Name: Elijah Sprung
  Date: 02/16/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_6/hybridType.cpp

  Implementation file for the derived class autoType:  
  Includes set, get, and simple mutator methods.
*/

#include "hybridType.h"
#include <iomanip>
#include <sstream>

void hybridType::setChargeLevel(double chargeLevel_in)
{
  if (chargeLevel_in > 0.0 && chargeLevel <= 100.0)
    chargeLevel = chargeLevel_in;
  else
    cerr << "Charge level must be > 0% and <= 100%" << endl;
}

double hybridType::getChargeLevel(void) const
{
  return chargeLevel;
}

void hybridType::setChargeEfficiency(double chargeEff_in)
{
  if (chargeEff_in > 1.0)
    chargeEff = chargeEff_in;
  else
    cerr << "Charge efficiency must be > 1.0" << endl;
}

double hybridType::getChargeEfficiency() const
{
  return chargeEff;
}

string hybridType::getAutoSpecs() const
{
  ostringstream sout;
  string output;
  
  output = autoType::getAutoSpecs();

  sout << fixed << showpoint << setprecision(2);
  sout << "\n";
  sout << "Charge Level = " << chargeLevel << "%";
  sout << ", Charge Efficiency = " << chargeEff;

  output = output.append(sout.str());

  return output;
}

void hybridType::drive(double distance)
{
  double lowestCharge = chargeLevel - 19;
  double batteryDistance = lowestCharge * chargeEff;
  double extraDistance, preGas, postGas;
  bool flag = false;
  int counter = 0;
  
  if (distance < 0)
  {
    cerr << "Cannot drive negative miles." << endl;
    return;
  }

  if (lowestCharge > 0)
  {
    if (distance < batteryDistance)
    {
      odometer += distance;
      chargeLevel -= distance / chargeEff;
      cout << distance << " miles were driven using the battery." << endl;
    }
    else
    {
      odometer += batteryDistance;
      chargeLevel -= batteryDistance / chargeEff;
      cout << "The battery dropped below 20% after " << batteryDistance <<
        " miles. Switching to gas mode." << endl;

      extraDistance = distance - batteryDistance;
      preGas = odometer;
      
      autoType::drive(extraDistance);

      if (odometer > preGas)
      {
        postGas = odometer - preGas;

        while (!flag)
        {
          if (postGas > 20)
          {
            counter++;
            postGas -= 20;
          }
          else
          {
            flag = true;
          }
        }
        chargeLevel += counter;
        cout << "After driving " << odometer - preGas << " miles using gas " <<
          "chargeLevel was increased by " << counter << "%." << endl;
      }
      else
      {
        cout << "The car did not drive using gas, so no charge was added." <<
          endl;
      }
    }
  }
  else
  {
    preGas = odometer;

    autoType::drive(distance);

    if (odometer > preGas)
    {
      postGas = odometer - preGas;

      while (!flag)
      {
        if (postGas > 20)
        {
          counter++;
          postGas -= 20;
        }
        else
        {
          flag = true;
        }
      }
      chargeLevel += counter;
      cout << "After driving " << odometer - preGas << " miles using gas " <<
        "chargeLevel was increased by " << counter << "%." << endl;
    }
    else
    {
      cout << "The car did not drive using gas, so no charge was added." <<
        endl;
    }
  }
}

hybridType::hybridType()
{
  chargeLevel = 0;
  chargeEff = 1;
}

hybridType::hybridType(double od_in, double fc_in, double fl_in, double mpg_in,
  double chargeLevel_in, double chargeEff_in)
{
  if (fc_in > 0)
  {
    fuelCap = fc_in;
  }
  else
  {
    cerr << "Fuel cap entered below 0, set to 20." << endl;
    fuelCap = 20;
  }

  autoType::setAutoSpecs(od_in, fl_in, mpg_in);

  if (chargeLevel_in >= 0)
  {
    chargeLevel = chargeLevel_in;
  }
  else
  {
    cerr << "A value less than 0 was entered, it will be set to 0." << endl;
    chargeLevel = 0;
  }

  if (chargeEff_in >= 1)
  {
    chargeEff = chargeEff_in;
  }
  else
  {
    cerr << "A charge efficiency less than 1 was entered, it will be set to";
    cerr << " 1" << endl;
    chargeEff = 1;
  }
}