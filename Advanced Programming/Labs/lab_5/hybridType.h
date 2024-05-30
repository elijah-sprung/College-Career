/*
   Author: Elijah Sprung
   Date: 2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_5/hybridType.h

   About: The header file for the derived hybridType class.
*/

#include "autoType.h"
#include <iostream>

using namespace std;

#ifndef HYBRID_TYPE
#define HYBRID_TYPE

class hybridType : public autoType
{
  private:
    double chargeLevel;
    double chargeEff;

  public:

    /*
      setChargeLevel: Sets the charge in the battery given a value.
      pre-condition: A value must be passed greater than 0.
      post-condition: The charge will be changed accordingly.
    */

    void setChargeLevel(double charge_in);

    /*
      getChargeLevel: Returns the charge in the battery.
      pre-condition: None.
      post-condition: Charge is returned as double.
    */

    double getChargeLevel(void) const;

    /*
      setChargeLevel: Sets the charge efficiency in the battery given a value.
      pre-condition: A value must be passed greater than 1.
      post-condition: The charge will be changed accordingly.
    */

    void setChargeEfficiency(double chargeEff_in);

    /*
      getChargeEfficienct: Returns the charge efficienct if the battery.
      pre-condition: None.
      post-condition: Charge efficiency is returned as double.
    */

    double getChargeEfficiency(void) const;
};
#endif