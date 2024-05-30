/*
 Elijah Sprung
 CSC 1710-04
 08/27/2020
 home/students/esprung/csc1710/lab2
 This code will ask the user how many of each bill they have, and then will print out their total combined value.
*/

#include <iostream>
using namespace std;

//Main function.
int main ()
{
    //Integer varaibles for each of the bill values.
    int bills1;
    int bills5;
    int bills10;
    int bills20;

    //Print a statement as a question and then ask the number of each type of bill.
    cout << "Enter number of $1 bills: " << endl;
    cin >> bills1;

    cout << "Enter number of $5 bills: " << endl;
    cin >> bills5;

    cout << "Enter number of $10 bills: " << endl;
    cin >> bills10;

    cout << "Enter number of $20 bills: " << endl;
    cin >> bills20;

    //Create a final integer with the total sum of all of the bills and then print it out.
    int final = bills1 + (bills5 * 5) + (bills10 * 5) + (bills20 * 20);
    cout << "You have a total of " << final << " dollars.";
}