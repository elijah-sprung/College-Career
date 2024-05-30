/*
  Name: Elijah Sprung
  Date: 04/27/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_13/main.cpp

  About: Program to load in two separate lists, based on the text file names
         given by the user, into ordered linked lists. These lists will then be
         merged into one list, with the second one becoming empty. The data for
         the students will be printed based on descending GPA. Finally, the
         average GPA will be printed out.

  Compilation Line:

  g++ -Wall main.cpp -o prog5Test

  Run Command:

  ./prog5Test
*/

/*
  Junior Data:

  Nathaly Shepherd 2.12
  Myla Lester 2.85
  Gayson Rosales 2.90
  Mia Cruz 2.26
  Marc Bender 2.34
  Aiden Holden 3.12
  Gavin Oneill 2.49
  Lilianna Pitts 2.54
  Rodolfo Grant 3.04
  Brent Domiquez 2.67
  Morgan Phelps 3.23
  Joel Barajas 2.71
*/

/*
  Senior Data:

  Dahlia Davenport 3.37
  Cornelius Mccarthy 1.24
  Keagan Rose 3.55
  Weston Cobb 1.46
  Elianna Carroll 3.68
  Dahlia Aguirre 1.38
  Nicholas Solomon 3.71
  Alivia Riddle 1.17
  Dashawn Fletcher 3.80
  Kinsley Bond 1.01
  Philip Travis 3.93
  Aspen Montes 4.00
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "linkedList.h"
#include "orderedLinkedList.h"
#include "stuType.h"

using namespace std;

void load_data(orderedLinkedList<stuType>& list);
void find_average(orderedLinkedList<stuType> list);

/*
  main: Main function to test the merge, forwardPrint, and reversePrint member
        functions in the orderedLinkedList class.
  precondition: None.
  postcondition: Retrun 0 and end.
*/

int main()
{
  orderedLinkedList<stuType> junior_data;
  orderedLinkedList<stuType> senior_data;

  load_data(junior_data);
  load_data(senior_data);
  cout << endl;

  cout << "Merged List: ";
  junior_data.merge(senior_data);
  junior_data.reverse_print();
  cout << endl << endl;

  find_average(junior_data);

  return 0;
}

/*
  load_data: Function to take in the name of a file from a user, use exception
             handling to make certain that the file actually exists and that
             the user may enter a new file until a valid name is given, and
             then load the contents of that file into a linked list until
             the file ends.
  precondition: orderedLinkedList of type string passed by reference.
  postcondition: Data is loaded.
*/

void load_data(orderedLinkedList<stuType>& list)
{
  ifstream file;
  bool flag = false;
  string file_name;
  stuType holder;
  string fname, lname;
  double GPA;

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

  file >> fname;
  file >> lname;
  file >> GPA;
  holder.set_first_name(fname);
  holder.set_last_name(lname);
  holder.set_GPA(GPA);
  list.insertLast(holder);

  while (!file.eof())
  {
    file >> fname;
    file >> lname;
    file >> GPA;
    holder.set_first_name(fname);
    holder.set_last_name(lname);
    holder.set_GPA(GPA);
    list.insertLast(holder);
  }

  file.close();
}

/*
  find_average: Finds the average GPA of all of the students in an ordered
                linked list using a linked list iterator and outputs it.
  precondition: Passed a orderedLinkedList<stuType> object.
  postcondition: Average is calculated and output.
*/

void find_average(orderedLinkedList<stuType> list)
{
  double total = 0;
  double num = 0;
  linkedListIterator<stuType> iterator;

  for (iterator = list.begin(); iterator != list.end(); ++iterator)
  {
    total += (*iterator).get_GPA();
    num++;
  }

  cout << fixed << showpoint << setprecision(2);
  cout << "The average GPA of all students was: " << total / num << endl;
}