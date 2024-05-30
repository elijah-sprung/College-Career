/*
  Name: Elijah Sprung
  Date: 03/23/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/lab_10/main.cpp

  About: Program to test the invalidDay and invalidMonth classes.

  Compilation Line:

  g++ -Wall main.cpp -o lab10Test

  Run Command:

  ./lab10Test
*/

#include <iostream>
#include <string>
#include "invalidYear.h"
#include "invalidMonth.h"
#include "invalidDay.h"

using namespace std;

void getBirthday(int& day, int& month, int& year);
void checkYear(int& year);
bool checkLeapYear(const int year);
void checkMonth(int& month);
void checkDay(int& day, const int month, const bool leapYear);
void printBirthday(const int day, const int month, const int year);

/*
  main: Function to call all functions to get birth date and return it in form.
  precondition: Called.
  postcondition: Return 0.
*/

int main()
{
  int day, month, year;
  bool leapYear;

  getBirthday(day, month, year);
  checkYear(year);
  leapYear = checkLeapYear(year);
  checkMonth(month);
  checkDay(day, month, leapYear);

  printBirthday(day, month, year);

  return 0;
}

/*
  getBirthday: Function to get birth date input from user.
  precondition: Passed by reference date values.
  postcondition: Date values instantiated.
*/

void getBirthday(int& day, int& month, int& year)
{
  cout << "Please input your birthday in order of day, month, and year." << endl;
  cout << "Use only integers and press 'Enter' after each input." << endl;

  cin >> day;
  cin >> month;
  cin >> year;
}

/*
  checkYear: Function to make sure the year is greater than or equal to 1582
             using throw and catch statements.
  precondition: Pass by reference year value.
  postcondition: None.
*/

void checkYear(int& year)
{
  bool flag = false;

  while (flag == false)
  {
    try
    {
      if (year < 1582)
      {
        throw invalidYear();
        flag = false;
      }
      else
      {
        flag = true;
      }
    }

    catch (invalidYear invalidYearObj)
    {
      cout << "Error Message: " << invalidYearObj.what() << endl;
      cin >> year;
    }
  }
}

/*
  checkLeapYear: Function to figure out if the passed year is a leap year.
  precondition: Passed year value.
  postcondition: Returns true or false.
*/

bool checkLeapYear(const int year)
{
  if (year > 1582 && year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      if (year % 400 == 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return true;
    }
  }
}

/*
  checkMonth: Function to check the month using throw and catch statements to
              check if there were any errors.
  precondition: Passed by reference month value.
  poscondition: None.
*/

void checkMonth(int& month)
{
  bool flag = false;
  
  while (flag == false)
  {
    try
    {
      if (month > 0 && month <= 12)
      {
        flag = true;
      }
      else
      {
        throw invalidMonth();
        flag = false;
      }
    }

    catch (invalidMonth invalidMonthObj)
    {
      cout << "Error Message: " << invalidMonthObj.what() << endl;
      cin >> month;
    }
  }
}

/*
  checkDay: Function to check the day using throw and catch statements to
              check if there were any errors.
  precondition: Passed by reference day, month, and leap year values.
  poscondition: None.
*/

void checkDay(int& day, const int month, const bool leapYear)
{
  bool flag = false;

  while (flag == false)
  {
    try
    {
      if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day > 31)
      {
        throw invalidDay(1, month);
        flag = false;
      }
      else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 0 && day > 30)
      {
        throw invalidDay(2, month);
        flag = false;
      }
      else if (leapYear == false && month == 2 && day > 0 && day > 28)
      {
        throw invalidDay(3, month);
        flag = false;
      }
      else if (leapYear == true && month == 2 && day > 0 && day > 29)
      {
        throw invalidDay(4, month);
      }
      else if (day < 0)
      {
        throw invalidDay(5, month);
        flag = false;
      }
      else
      {
        flag = true;
      }
    }

    catch (invalidDay invalidDayObj)
    {
      cout << "Error Message: " << invalidDayObj.what() << endl;
      cin >> day;
    }
  }
}

/*
  printBirthday: Function to print out the birth date in the form:
                 Month Day, Year.
  precondition: Passed day, month, and year values.
  postcondition: None.
*/

void printBirthday(const int day, const int month, const int year)
{
  cout << endl;
  cout << "Final Output: ";

  switch (month)
  {
    case 1:
      cout << "January " << day << ", " << year << "." << endl;
      break;
    case 2:
      cout << "February " << day << ", " << year << "." << endl;
      break;
    case 3:
      cout << "March " << day << ", " << year << "." << endl;
      break;
    case 4:
      cout << "April " << day << ", " << year << "." << endl;
      break;
    case 5:
      cout << "May " << day << ", " << year << "." << endl;
      break;
    case 6:
      cout << "June " << day << ", " << year << "." << endl;
      break;
    case 7:
      cout << "July " << day << ", " << year << "." << endl;
      break;
    case 8:
      cout << "August " << day << ", " << year << "." << endl;
      break;
    case 9:
      cout << "September " << day << ", " << year << "." << endl;
      break;
    case 10:
      cout << "October " << day << ", " << year << "." << endl;
      break;
    case 11:
      cout << "November " << day << ", " << year << "." << endl;
      break;
    case 12:
      cout << "December " << day << ", " << year << "." << endl;
      break;
  }
}