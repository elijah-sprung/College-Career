/*
  Name: Elijah Sprung
  Date: 03/30/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/prog_4/invalidPower.h

  About: The header file for invalidPower.
*/

#ifndef INVALID_POWER
#define INVALID_POWER

#include <iostream>
#include <string>

using namespace std;

class invalidPower
{
private:
  string message;

public:

  /*
    invalidMonth: "Constructor" with no input.
    precondition: Called.
    postcondition: Instantiated.
  */

  invalidPower(const string err_code)
  {
    if (err_code == "NegativeBase")
    {
      message = "The base must be positive, please enter j again.";
    }
    else if (err_code == "OverflowException")
    {
      message = "Result of the power is too large for an int.";
    }
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