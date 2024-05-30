/*
 Elijah Sprung
 CSC 1710-04
 10/15/2020
 home/students/esprung/csc1710/lab9/factorial2.cpp
 Program to calculate factorials, double factorials, and a summation given a starting value and a ratio using functions.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to find the factorial.
double factorial (double value)
{
    // What is calculated.
    double output = 1;

    // Loop until to given value is reached.
    for (int i = 1; i < value + 1; i++)
    {
        // Multiply all the numbers together.
        output *= i;
    }

    //Return final value.
    return output;
}

// Function to find the double factorial.
double doublefact (double value)
{
    // Set variables for control and output.
    int i = 1;
    double output = 1;
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
    while (i < value + 1);

    //Return final value.
    return output;
}

// Function to find the geometric series.
double geoseries (double value, double control)
{
    // Set the output variable.
    double output;

    // Loop until the desired number of values.
    for (double i = 1; i < control + 1; i++)
    {
        // Check for first value.
        if (i != 1)
        {
            // Add each value while also accounting for the ratio.
            output = output + pow(value, i);
        }
        else
        {
            // Set the first value.
            output = value;
        }
    }
    
    //Return final value.
    return output;
}

//Main function.
int main ()
{
    // Variables for the loops and calculations.
    double input, numVal, control = false;

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

    // Output the final value and reset output for later use.
    cout << input << "! is equal to " << fixed << setprecision(0) << factorial(input) << endl;

    // Reset control variable to be reused.
    control = false;

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

    // Output final value and reset output for later use.
    cout << input << "!! is equal to " << fixed << setprecision(0) << doublefact(input) << endl;

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

    // Output the final value of the summation and the rest of the details.
    cout << "With " << numVal << " values, starting at " << setprecision(1) << input << " and a ratio of 0.5, the summation is " << setprecision(5) << geoseries(input, numVal) << endl;
}