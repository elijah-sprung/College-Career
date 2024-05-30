/*
  Name: Elijah Sprung
  Date: 03/23/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_10/invalidDay.h

  About: The header file for invalidDay.
*/

#ifndef INVALD_DAY
#define INVALID_DAY

#include <iostream>
#include <string>

using namespace std;

class invalidDay
{
  private:
    string message;

  public:

    /*
      invalidDay: "Constructor" that checks for different errors and the months.
      precondition: Passed error code number and month.
      postcondition: Instantiated.
    */

    invalidDay(const int err_code, const int month)
    {
      switch (err_code)
      {
        case 1:
          switch (month)
          {
          case 1:
            message = "Invalid day input. January only has 31 days. Try again.";
            break;
          case 3:
            message = "Invalid day input. March only has 31 days. Try again.";
            break;
          case 5:
            message = "Invalid day input. May only has 31 days. Try again.";
            break;
          case 7:
            message = "Invalid day input. July only has 31 days. Try again.";
            break;
          case 8:
            message = "Invalid day input. August only has 31 days. Try again.";
            break;
          case 10:
            message = "Invalid day input. October only has 31 days. Try again.";
            break;
          case 12:
            message = "Invalid day input. December only has 31 days. Try again.";
            break;
          }
          break;
        case 2:
          switch (month)
          {
          case 4:
            message = "Invalid day input. April only has 30 days. Try again.";
            break;
          case 6:
            message = "Invalid day input. June only has 30 days. Try again.";
            break;
          case 9:
            message = "Invalid day input. September only has 30 days. Try again.";
            break;
          case 11:
            message = "Invalid day input. November only has 30 days. Try again.";
            break;
          }
          break;
        case 3:
          message = "Invalid day input. February only has 28 days when it is not a leap year. Try again.";
          break;
        case 4:
          message = "Invalid day input. February only has 29 days when it is a leap year. Try again.";
          break;
        case 5:
          message = "Invalid day input. Must be greater than 0.";
          break;
      }
    }

    /*
      invalidDay: "Constructor" with string input.
      precondition: Message input.
      postcondition: Instantiated.
    */

    invalidDay(string str)
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