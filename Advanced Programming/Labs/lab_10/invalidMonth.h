/*
  Name: Elijah Sprung
  Date: 03/23/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_10/invalidMonth.h

  About: The header file for invalidMonth.
*/

#ifndef INVALD_MONTH
#define INVALID_MONTH

#include <iostream>
#include <string>

using namespace std;

class invalidMonth
{
private:
  string message;

public:

  /*
    invalidMonth: "Constructor" with no input.
    precondition: Called.
    postcondition: Instantiated.
  */

  invalidMonth()
  {
    message = "Invalid input for month. It must be greater than 0 and less than 13. Try again.";
  }

  /*
    invalidMonth: "Constructor" with input.
    precondition: Message input.
    postcondition: Instantiated.
  */

  invalidMonth(string str)
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