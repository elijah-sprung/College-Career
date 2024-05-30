/*
  Name: Elijah Sprung
  Date: 03/2/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_8/main.cpp

  About: Program to test the arrayListType, unorderedArrayListType, and
  uniqueListType classes.

  Compilation Line:

  g++ -Wall main.cpp arrayListType.cpp unorderedArrayListType.cpp
  uniqueListType.cpp -o lab8Test

  Run Command:

  ./lab8Test<names.txt
*/

#include <iostream>
#include <string>
#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "uniqueListType.h"

using namespace std;

void loadData(uniqueListType& list);

/*
  main: Main function to test uniqueListType class.
  preconditions: Program run.
  postconditions: Return 0.
*/

int main()
{
  uniqueListType list(16);
  loadData(list);
  list.print();

  return 0;
}

/*
  loadData: Function to insert data from a file to a lsit.
  preconditions: uniqueListType variable passed.
  postconditions: Loads the list full of unique items.
*/

void loadData(uniqueListType& list)
{
  string data;
  
  cin >> data;

  while (cin && list.isFull() == false)
  {
    list.insertEnd(data);
    cin >> data;
  }
}