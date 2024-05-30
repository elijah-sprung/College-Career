/*
  Name: Elijah Sprung
  Date: 04/13/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_13/main.cpp

  About: Program to test the linkedList and unorderedLinkedList classes.

  Compilation Line:

  g++ -Wall main.cpp -o lab13Test

  Run Command:

  ./lab13Test
*/

#include <iostream>
#include <string>
#include <fstream>
#include "linkedList.h"
#include "unorderedLinkedList.h"

using namespace std;

void load_data(unorderedLinkedList<string>& list);

/*
  main: Main function to test the merge, forwardPrint, and reversePrint member
        functions in the unorderedLinkedList class.
  precondition: None.
  postcondition: Retrun 0 and end.
*/

int main()
{
  unorderedLinkedList<string> list_1;
  unorderedLinkedList<string> list_2;

  cout << "Loading the data for both lists." << endl << endl;

  load_data(list_1);
  load_data(list_2);

  cout << endl;

  cout << "Printing the first list with forwardPrint and reversePrint." << endl << endl;
  
  list_1.forwardPrint();
  cout << endl;
  list_1.reversePrint();
  cout << endl;

  cout << endl;
  
  cout << "Printing the second list with forwardPrint and reversePrint." << endl << endl;

  list_2.forwardPrint();
  cout << endl;
  list_2.reversePrint();
  cout << endl;

  cout << endl;

  cout << "Merging the two lists into the first list." << endl << endl;

  list_1.merge(list_2);

  cout << "Printing the merged list with forwardPrint and reversePrint." << endl << endl;

  list_1.forwardPrint();
  cout << endl;
  list_1.reversePrint();
  cout << endl;

  cout << endl;

  return 0;
}

/*
  load_data: Function to take in the name of a file from a user, use exception
             handling to make certain that the file actually exists and that
             the user may enter a new file until a valid name is given, and
             then load the contents of that file into a linked list until
             the file ends.
  precondition: unorderedLinkedList of type string passed by reference.
  postcondition: Data is loaded.
*/

void load_data(unorderedLinkedList<string>& list)
{
  ifstream file;
  bool flag = false;
  string holder, file_name;

  while (flag == false)
  {
    cout << "Enter the name of the file you wish to open." << endl;
    cin >> file_name;

    try
    {
      file.open(file_name);
      if (!file)
      {
        throw string("Invalid file name, try again.");
      }
      else
      {
        flag = true;
      }
    }

    catch (string error)
    {
      cout << "Exception Error: " << error << endl;
    }
  }

  file >> holder;
  list.insertLast(holder);

  while (!file.eof())
  {
    file >> holder;
    list.insertLast(holder);
  }

  file.close();
}