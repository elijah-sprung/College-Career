/*
 Elijah Sprung
 CSC 1710-04
 10/08/2020
 home/students/esprung/csc1710/lab8/factorial.cpp
 Program to calculate factorials, double factorials, and a summation given a starting value and a ratio.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Main function.
int main ()
{
    // Variables for the loops and calculations.
    double input, numVal, output = 1, control = false;

    // Ask for a value to find the factorial.
    cout << "What would you like to take the factorial of? Please enter a positive integer greater than 0 but less than 171." << endl;
    cin >> input;
    
    // Check if the value follows all rules given.
    while (control == false)
    {
        if (input > 0 && input < 171)
        {
            control = true;
        }
        else
        {
            cout << "You have input an invalid value, please enter a positive integer greater than 0 and less than 171." << endl;
            cin >> input;
        }
        
    }
    // Reset control variable to be reused.
    control = false;

    // Loop until to given value is reached.
    for (int i = 1; i < input + 1; i++)
    {
        // Multiply all the numbers together.
        output *= i;
    }
    // Output the final value and reset output for later use.
    cout << input << "! is equal to " << fixed << setprecision(0) << output << endl;
    output = 1;

    // Ask for a value to find the double factorial of.
    cout << "What would you like to take the double factorial of? Please enter a positive, odd integer greater than 0 and less than 301." << endl;
    cin >> input;

    // Make sure the user followed all rules given.
    while (control == false)
    {
        if (input > 0 && input < 301 && static_cast<int>(input) % 2 == 1)
        {
            control = true;
        }
        else
        {
            cout << "You have input an invalid value, please enter a positive, odd integer greater than 0 and less than 301." << endl;
            cin >> input;
        }
        
    }
    // Reset control to be used later.
    control = false;

    // Set a control integer;
    int i = 1;
    // Loop until the desired value is found.
    do 
    {
        // Check for odd.
        if ((i % 2) == 1)
        {
            // Multiply all the values together.
            output *= i;
        }

        // Add 1 to i.
        i++;
    }
    while (i < input + 1);

    // Output final value and reset output for later use.
    cout << input << "!! is equal to " << fixed << setprecision(0) << output << endl;
    output = 0;

    // Ask for the starting value and number of values in the summation.
    cout << "What would you like the starting value of your summation to be? Please enter a positive integer greater than 0." << endl;
    cin >> input;
    cout << "How many values would you like to go to in your summation? Please enter a positive integer greater than 1." << endl;
    cin >> numVal;

    // Check to make sure that the user has followed all directions.
    while (control == false)
    {
        if (input > 0)
        {
            if (numVal > 1)
            {
                control = true;
            }
            else
            {
                cout << "You have input an invalid value for how many numbers you want in your summation. Please enter a positive integer greater than 1." << endl;
                cin >> numVal;
            }
        }
        else
        {
            cout  << "You have input an invalid starting value. Please enter a positive integer greater than 0." << endl;
            cin >> input;
        }
    }

    // Loop until the desired number of values.
    for (double i = 1; i < numVal + 1; i++)
    {
        // Check for first value.
        if (i != 1)
        {
            // Add each value while also accounting for the ratio.
            output = output + pow(input, i);
        }
        else
        {
            // Set the first value.
            output = input;
        }
    }
    // Output the final value of the summation and the rest of the details.
    cout << "With " << numVal << " values, starting at " << setprecision(1) << input << " and a ratio of 0.5, the summation is " << setprecision(5) << output << endl;
}