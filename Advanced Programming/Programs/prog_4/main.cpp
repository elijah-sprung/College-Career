/*
  Name: Elijah Sprung
  Date: 03/30/2021
  Class: CSC1720-03
  Location: /home/students/esprung/csc1720/prog_4/main.cpp

  About: Program to find the outcome of an integer raised to a power while 
         using exception handling to make certain that all inputs follow
         the rule of powers.

  Compilation Line:

  g++ -Wall main.cpp -o prog4Test

  Run Command:

  ./prog4Test
*/

#include <iostream>
#include <string>
#include <climits>
#include "invalidPower.h"

using namespace std;

double Repower(int j, int k);
void checkJ(int& j);
void getInput(int& j, int& k);
void keepGoing(bool& flag);

/*
  main: Function to call other functions to ask for input from the user to
        calculate a power given the base and the power, check the input 
        validity, output the power, and repeat if the user wishes to. It also
        checks for if the output of the power would be above the value able to
        be held in memory by an int.
  precondition: Compiled.
  postcondition: None.
*/

int main()
{
  int j, k;
  bool flag = false;

  while (flag == false)
  {
    getInput(j, k);
    checkJ(j);
    try
    {
      if (Repower(j, k) > INT_MAX)
      {
        throw invalidPower("OverflowException");
      }
      else
      {
        cout << j << " to the power of " << k << " = " << Repower(j, k) << endl << endl;
        keepGoing(flag);
      }
    }

    catch (invalidPower invalidPowerObj)
    {
      cout << "Error Message: " << invalidPowerObj.what() << endl << endl;
      keepGoing(flag);
    }
  }

  return 0;
}

/*
  Repower: Function to recursively calculate the power of a number
           given the base and the power by the user. This also checks if the
           output would ever exceed the limit of an integer.
  precondition: Passed the base and the power.
  postcondition: Returns the outcome as a double.
*/

double Repower(int j, int k)
{
  if (k == 0)
  {
    return 1;
  }
  else if (k == 1)
  {
    return j;
  }
  else if (k > 1)
  {
    return j * Repower(j, k - 1);
  }
  else if (k < 0)
  {
    return 1 / Repower(j, -k);
  }
}

/*
  checkJ: Function to validate the value of the base entered by the user.
  precondition: Passed the base given by the user.
  postcondition: Program continues if correct and asks for better input if not.
*/

void checkJ(int& j)
{
  bool flag = false;

  while (flag == false)
  {
    try
    {
      if (j < 0)
      {
        throw invalidPower("NegativeBase");
        flag = false;
      }
      else
      {
        flag = true;
      }
    }

    catch (invalidPower invalidPowerObj)
    {
      cout << "Error Message: " << invalidPowerObj.what() << endl << endl;
      cin >> j;
    }
  }
}

/*
  getInput: Function to take in two integers as the bsae and power from the user.
  precondition: Passed memory for j and k.
  postcondition: j and k given values.
*/

void getInput(int& j, int& k)
{
  cout << "Please input your base for the power." << endl;
  cin >> j;
  cout << "Please input the power to be raised to." << endl;
  cin >> k;

  cout << endl;
}

/*
  keepGoing: Function to check whether or not the user wants to repeat the process.
  precondition: Passed memory for flag.
  postcondition: flag is either true or false.
*/

void keepGoing(bool& flag)
{
  bool checker = false;
  string input;

  while (checker == false)
  {
    cout << "Would you like to calculate another power? Enter 'yes' or 'no'." << endl;
    cin >> input;
    
    if (input == "yes")
    {
      flag = false;
      checker = true;
    }
    else if (input == "no")
    {
      flag = true;
      checker = true;
    }
    else
    {
      cout << "You did not enter a valid response for continuation status." << endl;
    }
  }

  cout << endl;
}