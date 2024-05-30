/*
 Elijah Sprung
 CSC 1710-04
 09/24/2020
 home/students/esprung/csc1710/lab6/leapYear.cpp
 A program to read a year from a user and outpute whether or not it is or will be a leap year.
*/

#include <iostream>
using namespace std;

//Main function.
int main ()
{
    // Variables for the year in question and the current year.
    int year, currentYear;

    // Ask for the current year and the year in question and assign them to their variables.
    cout << "Please enter the current year using only digits." << endl;
    cin >> currentYear;
    cout << "Please enter a year equivalent to or greater than 1600 using only digits." << endl;
    cin >> year;

    // Check for if this is a past year and if it is divisible by 4 without a remainder and is a year that ends in 00 and is divisible by 400.
    if (year < currentYear)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            cout << year << " was a leap year." << endl;
        }
        else
        {
            cout << year << " was not a leap year." << endl;
        }
    }
    // Check for if this is a past year and if it is divisible by 4 without a remainder and is a year that ends in 00 and is divisible by 400.
    else if (year == currentYear)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            cout << currentYear << " is a leap year." << endl;
        }
        else
        {
            cout << currentYear << " is not a leap year." << endl;
        }
        
    }
    // Check for if this is a past year and if it is divisible by 4 without a remainder and is a year that ends in 00 and is divisible by 400.
    else if (year > currentYear)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            cout << year << " will be a leap year." << endl;
        }
        else
        {
            cout << year << " will not be a leap year." << endl;
        }
        
    }
}