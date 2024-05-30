/*
   Author: Elijah Sprung
   Date:  2/11/2021
   Class: CSC-1720-03
   Code location: /home/students/esprung/csc1720/prog_2/main.cpp

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
  cout << "Testing the constructors and printVector:" << endl;
  vectorType vector_1, vector_2(1, 2, 3);
  vector_1.printVector();
  cout << endl;
  vector_2.printVector();
  cout << endl << endl;

  cout << "Testing setComps:" << endl;
  vector_1.setComps(1, 2, 3);
  vector_1.printVector();
  cout << endl << endl;

  cout << "Testing calcMagnitude:" << endl;
  cout << vector_1.calcMagnitude() << endl << endl;

  cout << "Testing scalarMultiply:" << endl;
  vectorType test_vector;
  test_vector = vector_1.scalarMultiply(3);
  vector_1.printVector();
  cout << " * 3 = ";
  test_vector.printVector();
  cout << endl << endl;

  cout << "Testing addVector:" << endl;
  test_vector = vector_1.addVector(vector_2);
  vector_1.printVector();
  cout << " + ";
  vector_2.printVector();
  cout << " = ";
  test_vector.printVector();
  cout << endl << endl;

  cout << "Testing subVector:" << endl;
  test_vector = vector_1.subVector(vector_2);
  vector_1.printVector();
  cout << " - ";
  vector_2.printVector();
  cout << " = ";
  test_vector.printVector();
  cout << endl << endl;

  cout << "Testing unitVector:" << endl;
  test_vector = vector_1.unitVector();
  cout << "The unit vector of ";
  vector_1.printVector();
  cout << " is ";
  test_vector.printVector();
  cout << endl << endl;

  cout << "Testing dotProduct:" << endl;
  double test_double;
  test_double = vector_1.dotProduct(vector_2);
  vector_1.printVector();
  cout << " dot ";
  vector_2.printVector();
  cout << " = " << test_double << endl << endl;;

  cout << "Testing crossProduct:" << endl;
  test_vector = vector_1.crossProduct(vector_2);
  vector_1.printVector();
  cout << " cross product ";
  vector_2.printVector();
  cout << " = ";
  test_vector.printVector();
  cout << endl << endl;

  cout << "Testing equalVector:" << endl;
  if (vector_1.equalVector(vector_2))
  {
    vector_1.printVector();
    cout << " = ";
    vector_2.printVector();
  }
  else
  {
    vector_1.printVector();
    cout << " != ";
    vector_2.printVector();
  }

  return 0;
}