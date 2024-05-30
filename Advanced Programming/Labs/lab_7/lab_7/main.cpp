/*
  Name: Elijah Sprung
  Date: 02/16/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_7/main.cpp

  About: Program to test the arrayListType and unorderedArrayListType classes.

  Compilation Line:

  g++ -Wall main.cpp arrayListType.cpp unorderedArrayListType.cpp -o lab7Test

  Run Command:
  
  ./lab7Test
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "arrayListType.h"
#include "unorderedArrayListType.h"

using namespace std;

int main()
{
  srand (time(0));

  unorderedArrayListType list;

  cout << "Filling list with 100 random numbers." << endl << endl;;
  for (int i = 0; i < 100; i++)
  {
    list.insertEnd(rand() % 100);
  }

  cout << "Printing list." << endl;
  list.print();
  cout << endl;

  cout << "Finding max list size." << endl;
  cout << list.maxListSize() << endl;
  cout << endl;

  cout << "Finding list size." << endl;
  cout << list.listSize() << endl;
  cout << endl;

  cout << "Looking for the number 20." << endl;
  if (list.seqSearch(20) == -1)
  {
    cout << "20 was not in the list." << endl;
  }
  else
  {
    cout << "The first instance of 20 is at location "
         << list.seqSearch(20) + 1 << "." << endl;
  }
  cout << endl;

  cout << "Checking if the list is full." << endl;
  if (list.isFull())
  {
    cout << "The list is full." << endl;
  }
  else
  {
    cout << "The list is not full." << endl;
  }
  cout << endl;

  cout << "Replacing the middle spot with 75." << endl;
  list.replaceAt(list.listSize() / 2, 75);
  list.print();
  cout << endl;

  cout << "Breaking the insertEnd method." << endl;
  list.insertEnd(100);
  list.print();
  cout << endl;

  cout << "Breaking the insertFirst method." << endl;
  list.insertFirst(100);
  list.print();
  cout << endl;

  cout << "Breaking the insertAt method." << endl;
  list.insertAt(list.listSize() / 2, 100);
  list.print();
  cout << endl;
  
  cout << "Removing last list item." << endl;
  list.removeAt(list.listSize() - 1);
  list.print();
  cout << endl;

  cout << "Inserting 100 at the end." << endl;
  list.insertEnd(100);
  list.print();
  cout << endl;

  cout << "Removing last list item." << endl;
  list.removeAt(list.listSize() - 1);
  list.print();
  cout << endl;

  cout << "Inserting 100 at the beginning." << endl;
  list.insertFirst(100);
  list.print();
  cout << endl;

  cout << "Removing last list item." << endl;
  list.removeAt(list.listSize() - 1);
  list.print();
  cout << endl;

  cout << "Inserting 100 at the middle." << endl;
  list.insertAt(list.listSize() / 2, 100);
  list.print();
  cout << endl;

  cout << "Finding the maximum value." << endl;
  cout << "The max value is: " << list.findMax() << "." << endl;
  cout << endl;

  cout << "Breaking isEmpty." << endl;
  if (list.isEmpty())
  {
    cout << "List is empty." << endl;
  }
  else
  {
    cout << "List is not empty." << endl;
  }
  cout << endl;

  cout << "Clearing the list." << endl;
  list.clearList();
  cout << "Printing the list:" << endl;
  list.print();
  cout << endl;

  cout << "Checking if list is empty." << endl;
  if (list.isEmpty())
  {
    cout << "List is empty." << endl;
  }
  else
  {
    cout << "List is not empty." << endl;
  }
  cout << endl;

  cout << "Breaking the findMax method." << endl;
  cout << "The max value is: " << list.findMax() << "." << endl;
  cout << endl;

  cout << "Breaking isFull." << endl;
  if (list.isFull())
  {
    cout << "List is full." << endl;
  }
  else
  {
    cout << "List is not full." << endl;
  }
  cout << endl;

  cout << "Destructing the list." << endl;
  cout << list.listSize() << endl;

  return 0;
}