/*
 Elijah Sprung
 CSC 1710-04
 09/21/2020
 home/students/esprung/csc1710/prog1/countingCoins.cpp
 Program to take some amount of money and then output the lowest amoung of coins possible and the numbers and types of each coin.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Main function.
int main ()
{
    // All of the counts for the different types of coins, and the total change.
    double total;
    int quarters, dimes, nickels, pennies;

    // Ask for amount of money and input it.
    cout << "How much money do you have?" << endl;
    cin >> total;

    // Calculate the amount of quarters, and change the total amount for future checking.
    quarters = static_cast<int> (total / 0.25);
    total = ((total / 0.25) - (static_cast<int> (total / 0.25))) * 0.25;

    // Calculate the amount of dimes, and change the total amount for future checking.
    dimes = static_cast<int> (total / 0.10);
    total = ((total / 0.10) - (static_cast<int> (total / 0.10))) * 0.10;

    // Calculate the amount of nickels, and change the total amount for future checking.
    nickels = static_cast<int> (total / 0.05);
    total = ((total / 0.05) - (static_cast<int> (total / 0.05))) * 0.05;

    // Calculate the amount of pennies, and change the total amount for future checking.
    pennies = static_cast<int> (total / 0.01);
    total = ((total / 0.01) - (static_cast<int> (total / 0.01))) * 0.01;

    // Print out the table that shows coin types and their counts.
    cout << left << "Coin Type" << setw(10) << right << "Number" << endl;
    cout << left << "Quarters" << setw(11) << right << quarters << endl;
    cout << left << "Dimes" << setw(14) << right << dimes << endl;
    cout << left << "Nickels" << setw(12) << right << nickels << endl;
    cout << left << "Pennies" << setw(12) << right << pennies << endl;
    cout << left << "Total" << setw(14) << right << quarters + dimes + nickels + pennies << endl;
}