/*
  Name: Elijah Sprung
  Date: 03/23/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_10/invalidYear.h

  About: The header file for invalidYear.
*/

#ifndef INVALD_YEAR
#define INVALID_YEAR

#include <iostream>
#include <string>

using namespace std;

class invalidYear
{
private:
  string message;

public:

  /*
    invalidYear: "Constructor" with no input.
    precondition: Called.
    postcondition: Instantiated.
  */

  invalidYear()
  {
    message = "Invalid input for year. It must be greater than or equal to 1582. Try again.";
  }

  /*
    invalidMonth: "Constructor" with input.
    precondition: Message input.
    postcondition: Instantiated.
  */

  invalidYear(string str)
  {
    message = str;
  }

  /*
    what: Returns the error message.
    precondition: Called.
    postcondition: Message returned.
  */

  string what()
  {
    return message;
  }
};

#endif