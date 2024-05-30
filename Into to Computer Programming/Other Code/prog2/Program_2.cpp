/*
 Elijah Sprung
 CSC 1710-04
 10/14/2020
 home/students/esprung/csc1710/prog2/SprungInvestTable100.cpp
 My attempt at a 100% score on a table that calculates interest and capital gain with a changing interest rate and input validation.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Constant values to be used in math.
const double RT1 = 1;
const double RT2 = 12;
const double RT = RT1 / RT2;
const double TT = 1000;

// Function to find interest.
double calcintr (double num, double rate)
{
    // Variable to be sent back
    double output;

    // Calculate continually compounding interest.
    output = num * exp(rate * RT);

    // Return the value.
    return output;
}

// Function to find the interest earned.
double findextra (double num1, double num2)
{
    // Value to return.
    double output;

    // Find the excess.
    output = num2 - num1;

    //Return value.
    return output;
}

//Main function.
int main ()
{
    // Variables to be used in calculation.
    double inv, dep, yrs, intr, cintr, totalInv, totalVal, extra = 0, holder;

    // Ask for input on each of the values to be used for calculation.
    cout << "What would you like your initial investment to be? Please enter an amount using only positive integers with no values past two decimal places." << endl;
    cin >> inv;
    cout << "Would you like to make a deposit every month, if so, please enter that amount using only positive integers with no values past two decimal places." << endl;
    cin >> dep;
    cout << "Over how many years would you like to calculate the amount of money gained? Please enter an amount using only positive integers with no decimal values." << endl;
    cin >> yrs;
    cout << "What would you like the interest rate to be? Please enter an amount using only positive integers." << endl;
    cin >> intr;
    cout << "By what factor would you like the interest rate to change by every year? Please enter an amount using only positive integers." << endl;
    cin >> cintr;

    // Make certain that the user input a valid value for each of the calculation values.
    while (inv < 0)
    {
        cout << "You entered an invalid amount for the initial investment, please enter a new one." << endl;
        cin >> inv;
    }
    while (dep < 0)
    {
        cout << "You entered an invalid amount for the recurring deposit, please enter a new one." << endl;
        cin >> dep;
    }
    while (yrs < 0)
    {
        cout << "You entered an invalid amount for the number of years, please enter a new one." << endl;
        cin >> yrs;
    }
    while (intr < 0)
    {
        cout << "You entered an invalid amount for the interest rate, please enter a new one." << endl;
        cin >> intr;
    }
    while (cintr < 0)
    {
        cout << "You entered an invalid amount for the change in interest rate, please enter a new one." << endl;
        cin >> cintr;
    }

    // Output all of the different parameters given.
    cout << "Initial Investment: $" << fixed << setprecision(2) << inv << endl;
    cout << "Monthly Deposits: $" << fixed << setprecision(2) << dep << endl;
    cout << "Number of Years: " << fixed << setprecision(0) << yrs << endl;
    cout << "Interest Rate: " << fixed << setprecision(2) << intr << endl;
    cout << "Change in Interest Rate " << fixed << setprecision(2) << cintr << endl;
    cout << endl;

    // Create the table.
    cout << setw(33) << right << "Investment Table" << setw(17) << endl;
    cout << setw(10) << left << "Month" << setw(20) << left << "Total Invested ($)" << setw(20) << left << "Current Value ($)" << endl;
    
    for (int LCV = 0; LCV < 50; LCV++)
        {
            cout << "_";
        }
    cout << endl;

    // Calculate the value earned based on continuously compounding interest over a series of some years.
    for (int i = 0; i < (12 * yrs) + 1; i++)
    {
        totalInv = inv + (i * dep);
        
        // Make a case for the initial value to account for differences.
        switch (i)
        {
            case 0:
                totalVal = totalInv;
                break;
            default:
                // Find the value with a separate function.
                totalVal = calcintr(totalInv - 100, intr) + extra;
                break;
        }
        
        // Find the excess with a separate function.
        extra = findextra(totalInv - 100, totalVal);

        // Increase the interest rate if the year has ended.
        if (i % 12 == 0 && i != 0)
        {
            intr += cintr;
        }

        // Output the rest of the table.
        cout << setw(10) << left << i << setw(20) << left << totalInv << setw(20) << left << totalVal << endl;
    }
}