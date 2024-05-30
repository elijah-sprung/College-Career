/*
 Elijah Sprung
 CSC 1710-04
 10/01/2020
 home/students/esprung/csc1710/lab7/temperature.cpp
 Program to take a temperature in fahrenheit and take it to a different temperature and then output it in celcius and kelvin.
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Main function.
int main ()
{
    // Variables for each of the temperature values and the increment.
    double far, far2, cel, kel, inc;

    // Ask for starting temperature, temperature goal, and the increment.
    cout << "Please enter your starting value of degrees in fahrenheit." << endl;
    cin >> far;
    cout << "What temperature would you like it to go to in fahrenheit?" << endl;
    cin >> far2;
    cout << "By what increment would you like to use to reach this temperature in fahrenheit?" << endl;
    cin >> inc;

    // Format the table.
    cout << fixed << setprecision(4) << showpoint << endl;
    for (int i = 0; i < 43; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "|" << setw(13) << left << "Fahrenheit" << right << "|" << setw(13) << left << "Celcius" << right << "|" << setw(13) << left << "Kelvin" << right << "|" << endl;

    // Ask for if starting temp is larger.
    if (far > far2)
    {
        // Run while inequal.
        while (far != far2)
        {
            // Calculate celcius and kelvin.
            cel = (far - 32) / 1.8000;
            kel = cel + 273.15;

            // Output values in format.
            cout << "|" << setw(13) << left << far << right << "|" << setw(13) << left << cel << right << "|" << setw(13) << left << kel << right << "|" << endl;
            
            // Decrease control variable.
            far = far - inc;
        }

        // Do calculations and output at the end for the fencepost problem.
        cel = (far - 32) / 1.8000;
        kel = cel + 273.15;

        cout << "|" << setw(13) << left << far << right << "|" << setw(13) << left << cel << right << "|" << setw(13) << left << kel << right << "|" << endl;
    }

    // Check for if starting temp is lower.
    else if (far < far2)
    {
        // Run while inequal.
        while (far != far2)
        {
            // Calculate celcius and kelvin.
            cel = (far - 32) / 1.8000;
            kel = cel + 273.15;

            // Output values in table.
            cout << "|" << setw(13) << left << far << right << "|" << setw(13) << left << cel << right << "|" << setw(13) << left << kel << right << "|" << endl;
            
            // Increase control variable.
            far = far + inc;
        }

        // Calculate temps and output for fencepost problem.
        cel = (far2 - 32) / 1.8000;
        kel = cel + 273.15;

        cout << "|" << setw(13) << left << far << right << "|" << setw(13) << left << cel << right << "|" << setw(13) << left << kel << right << "|" << endl;
    }

    // Finish the formatting of the table at the bottom.
    for (int i = 0; i < 43; i++)
    {
        cout << "-";
    }
    cout << endl;
}