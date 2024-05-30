/*
   Author: Elijah Sprung
   Date: 2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_5/hybridType.cpp

   About: The implementation file for the hybridType class.
*/

#include "autoType.h"
#include "hybridType.h"
#include <iostream>

void hybridType::setChargeLevel(double charge_in)
{
  if ((charge_in >= 0) && (charge_in <= 100))
  {
    chargeLevel = charge_in;
  }
  else
  {
    cerr << "A value less than 0 or greater than 100 was entered, charge level";
    cerr << "will be set to 0" << endl;
    chargeLevel = 0;
  }
}

double hybridType::getChargeLevel(void) const
{
  return chargeLevel;
}

void hybridType::setChargeEfficiency(double chargeEff_in)
{
  if (chargeEff_in > 0)
  {
    chargeEff = chargeEff_in;
  }
  else
  {
    cerr << "A value less than 1 was entered, charge efficiency will be set";
    cerr << "to 1." << endl;
    chargeEff = 1;
  }
}

double hybridType::getChargeEfficiency(void) const
{
  return chargeEff;
}