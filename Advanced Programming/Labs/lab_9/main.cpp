/*
  Name: Elijah Sprung
  Date: 03/16/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_9/main.cpp

  About: Program to test the arrayListType andorderedArrayListType.

  Compilation Line:

  g++ -Wall main.cpp arrayListType.cpp orderedArrayListType.cpp
  -o lab9Test

  Run Command:

  ./lab9Test
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "orderedArrayListType.h"

using namespace std;

/*
  main: Main function to test uniqueListType class.
  preconditions: Program run.
  postconditions: Return 0.
*/

int main()
{
  orderedArrayListType list;

  srand(time(0));
  
  for (int i = 0; i < 10; i++)
  {
    list.insertEnd(rand());
  }

  cout << "Created and filled first list." << endl;
  cout << "First List: ";
  list.print();
  cout << endl;
  cout << endl;

  orderedArrayListType copyList(list);
  cout << "Created second list with copy constructor." << endl;
  cout << "First List: ";
  list.print();
  cout << endl;
  cout << "Second List: ";
  copyList.print();
  cout << endl << endl;

  cout << "Inserting value 420 into the second list to show deep copy." << endl;
  copyList.insert(420);
  cout << "First List: ";
  list.print();
  cout << endl;
  cout << "Second List: ";
  copyList.print();
  cout << endl << endl;

  orderedArrayListType equalList;
  equalList = list;
  cout << "Using the overridden assignment operator on a new list." << endl;
  cout << "First List: ";
  list.print();
  cout << endl;
  cout << "Second List: ";
  equalList.print();
  cout << endl << endl;
  

  cout << "Printing a list with the overrideen stream insertion operator." << endl;
  cout << list;
  cout << endl;

  return 0;
}