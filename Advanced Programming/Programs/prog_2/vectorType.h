/*
   Author: Elijah Sprung
   Date:  2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/prog_2/vectorType.h

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

    double getX(void) const;
    double getY(void) const;
    double getZ(void) const;

    /*
      printVector: Function to print the vector out in a normalized format.
      pre-conditions: None.
      post-conditions: The private members are printed in a format.
    */

    void printVector(void) const;

    /*
      calcMagnitude: Function to find the magnitude of the vector.
      pre-conditions: None.
      post-conditions: The magnitude is returned.
    */

    double calcMagnitude(void) const;

    /*
      scalarMultiply: Function to multiply a vector by a scalar and then return
        the new vector created.
      pre-condition: A double input for the scalar.
      post-condition: A variable of the class vectorType will be returned.
    */
    vectorType scalarMultiply(double scalar);

    /*
      addVector: Function to add two vectors together and return their sum.
      pre-condition: Two vectorType variables must be passed.
      post_condition: A vectorType variable will be returned.
    */

    vectorType addVector(vectorType vector_in);

    /*
      subVector: Function to subtract two vectors together and return that outcome.
      pre-condition: Two vectorType variables must be passed.
      post_condition: A vectorType variable will be returned.
    */

    vectorType subVector(vectorType vector_in);

    /*
      unitVector: Finds and returns the unit vector of a vector.
      pre-condition: One vectorType variable must be passed.
      post-condition: A vectorType variable will be returned.
    */

    vectorType unitVector(void);

    /*
      dotProduct: Finds the dot product of two vectors.
      pre-condition: Two vectorType varaibles must be passed.
      post-condition: The dot product will be returned as a double.
    */

    double dotProduct(vectorType vector_in);

    /*
      crossProduct: Finds the cross product of two vectors.
      pre-condition: Two vectorType variables must be passed.
      post-condition: A new vectorType variable will be returned.
    */

    vectorType crossProduct(vectorType vector_in);

    /*
      equalVector: Checks if two vectors are equal.
      pre-condition: A vectorType variable must be passed.
      post-condition: A boolean value will be returned based on whether the two
        vectors are equal.
    */

    bool equalVector(vectorType vector_in);

    /*
      constructors: The two constructors for the vectorType class.
      pre-condition: 3 doubles for one, and none for the other.
      post-condition: A variable of the vectorType class is created.
    */

    vectorType(double, double, double);
    vectorType(void);
};
#endif