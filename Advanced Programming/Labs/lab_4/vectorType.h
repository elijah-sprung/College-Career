/*
   Author: Elijah Sprung
   Date:  1/26/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_4/vectorType.h

   About: The header file for class vectorType.
*/

#ifndef VECTORTYPE
#define VECTORTYPE

class vectorType
{
  private:
  
  /*
    The three private members of the vectorType class.
  */

    double x;
    double y;
    double z;

  public:

    /*
      setComps: Function to set the private members of the vectorType classs
        as the input given by the user.
      pre-condition: 3 doubles must be passed to the function for x, y, and z.
      post-condition: The corresponding private members will be set to those
        values.
    */

    void setComps(double, double, double);

    /*
      get Functions: The functions to return each private member.
      pre-condition: None.
      post-condition: The corresponding private member is returned.
    */

    double getX() const;
    double getY() const;
    double getZ() const;

    /*
      printVector: Function to print the vector out in a normalized format.
      pre-conditions: None.
      post-conditions: The private members are printed in a format.
    */

    void printVector() const;

    /*
      calcMagnitude: Function to find the magnitude of the vector.
      pre-conditions: None.
      post-conditions: The magnitude is returned.
    */

    double calcMagnitude() const;

    /*
      scalarMultiply: Function to multiply a vector by a scalar and then return
        the new vector created.
      pre-condition: A double input for the scalar.
      post-condition: A variable of the class vectorType will be returned.
    */
    vectorType scalarMultiply(double);

    /*
      constructors: The two constructors for the vectorType class.
      pre-condition: 3 doubles for one, and none for the other.
      post-condition: A variable of the vectorType class is created.
    */

    vectorType(double, double, double);
    vectorType();
};
#endif