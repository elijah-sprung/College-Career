/*
  Name: Elijah Sprung
  Date: 02/16/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_6/hybridType.h

  About: this is the header file for the derived autoType class: hybridType
  hybridType is a type of autoType, in which it has two more 
  private instance variable, the amount of charge in its
  batteries --> chargeLevel and the battery/charge efficiency --> chargeEff
*/

#include <iostream>
#include "autoType.h"

using namespace std;

#ifndef HYBRID_TYPE
#define HYBRID_TYPE

class hybridType: public autoType
{
   private:
      double chargeLevel;
      double chargeEff;
   public:
     /*
      setChargeLevel - use to update the private instance variable
                       chargeLevel of a hybridType.  
                       Max change level is 100%.
      pre-conditions: parameter must be a double in percent form
      post-conditions: chargeLevel = chargeLevel_in
      */
      void setChargeLevel(double chargeLevel_in);

     /*
      getChargeLevel - use to "get" the value of chargeLevel 
                       when it is not directly available
                       ((when outside the class))
      post-conditions: returns chargeLevel in percent form
      */
      double getChargeLevel(void)const;

     /*
      setChargeEfficiency - use to update the private instance variable
                            chargeEff of a hybridType
      pre-conditions: parameter must be a double
      post-conditions: chargeEff = chargeEff_in
      */
      void setChargeEfficiency(double chargeEff_in);

     /*
      getChargeEfficiency - use to "get" the value of chargeEff
                            when it is not directly available 
                            ((outside the class))
      post-conditions: returns chargeEff
      */
      double getChargeEfficiency()const;
      
      /*
        getAutoSpecs: Overload for the getAutoSpecs function using the private
          variables of the hybridType class.
        pre-conditions: None.
        post-conditions: All of the private variables will be printed with
          labels.
      */
      
      string getAutoSpecs() const;

      /*
        drive: Overload for the drive function using the private variables of
          the hybridType class.
        pre-conditions: A double value must be passed for the distance to
          drive.
        post-conditions: The values of the hybridType Variable will be altered
          as needed.
      */

      void drive(double distance);

      /*
        hybridType: Constructors for the hybridType class, one with default
          variables and one that takes input.
        pre-condition: None or input for each of the private variables.
        post-condition: A hybridType variable is created.
      */

      hybridType();
      hybridType(double od_in, double fc_in, double fl_in, double mpg_in,
                 double chargeLevel_in, double chargeEff_in);
};

#endif
