/*
   Author: Elijah Sprung
   Date:  2/2/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/lab_4/main.cpp

   About: The main progrom used to test the vectorType class.
*/

#include <iostream>
#include "vectorType.h"

using namespace std;

/*
  main - The main program that runs all of the tests for the vectorType class.
  pre-conditions: The program must be run.
  post-conditions: The program will test all of the different methods and
    constructors of the vectorType class, while also describing what is being
    tested. Also return 0.
*/

int main()
{
  cout << "Testing the use of the 2 different constructors." << endl;
  cout << "One has the values of 2, 3, and 4, and one will be blank." << endl;
  vectorType vector1(2, 3, 4);
  vectorType vector2;
  vectorType vector3;
  vector1.printVector();
  cout << endl;
  vector2.printVector();
  cout << endl;
  
  cout << "Testing the set and get methods." << endl;
  cout << "A blank vector will be replaced with values 3, 4, and 5." << endl;
  vector2.setComps(3, 4, 5);
  cout << vector2.getX() << " " << vector2.getY() << " " << vector2.getZ() << endl;
  
  cout << "Testing the printVector method." << endl;
  vector2.printVector();
  cout << endl;
  
  cout << "Testing the calcMagnitude with a vector of 3, 4, and 5." << endl;
  cout << vector2.calcMagnitude() << endl;

  cout << "Testing the scalarMultiply with a scalar of 3." << endl;
  cout << "The vector scaled will have values of 3, 4, and 5." << endl;
  vector3 = vector2.scalarMultiply(3);
  vector3.printVector();
  

  return 0;
}